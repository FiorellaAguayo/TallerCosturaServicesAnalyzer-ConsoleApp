#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

static void printMessage(char message[]);
static void askForData(char text[]);
static int validateInteger(char integerToValidate[]);
static int validateOnlyCharacters(char text[]);
static int orderString(char text[]);

/**
 * @brief Imprime un mensaje en la consola.
 * Esta función imprime el mensaje proporcionado en la consola si no es NULL.
 * @param message El mensaje que se imprimirá.
 */
static void printMessage(char message[])
{
    if(message != NULL)
    {
        printf(message);
    }
}

/**
 * @brief Lee una cadena de caracteres desde la consola.
 * Esta función lee una cadena de caracteres desde la consola y la almacena en el búfer proporcionado.
 * @param text El búfer donde se almacenará la cadena de entrada.
 */
static void askForData(char text[])
{
    if(text != NULL)
    {
        char buffer[256];
        fflush(stdin);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';
        strcpy(text, buffer);
    }
}

/**
 * @brief Valida si una cadena representa un número entero.
 * Esta función verifica si la cadena proporcionada se puede convertir en un número entero.
 * @param integerToValidate La cadena que se va a validar.
 * @return Devuelve 1 si la cadena es un número entero válido, 0 en caso contrario.
 */
static int validateInteger(char integerToValidate[])
{
    int allOk = 1;
    if(strlen(integerToValidate) > 0)
    {
        for(int i = 0; i < strlen(integerToValidate); i++)
        {
            if(isdigit(integerToValidate[i]) == 0)
            {
                if(i == 0 && integerToValidate[0] == '-')
                {
                    allOk = 1;
                }
                else
                {
                    allOk = 0;
                }
            }
        }
    }
    else
    {
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Solicita al usuario que ingrese un número entero dentro de un rango específico.
 * Esta función muestra un mensaje al usuario, solicita una entrada y valida si el valor ingresado es un número entero válido
 * dentro del rango especificado.
 * @param validatedInteger Puntero a la variable donde se almacenará el número entero validado.
 * @param message El mensaje que se muestra como indicación.
 * @param messageError El mensaje de error que se muestra para una entrada no válida.
 * @param minimum El valor mínimo permitido para el entero.
 * @param maximum El valor máximo permitido para el entero.
 * @return Devuelve 1 si se ingresa un número entero válido dentro del rango, 0 en caso contrario.
 */
int askForInteger(int* validatedInteger, char message[], char messageError[], int minimum, int maximum)
{
    int allOk = 0;
    if(validatedInteger != NULL && message != NULL && messageError != NULL && minimum < maximum)
    {
        char auxInteger[150];
        printMessage(message);
        askForData(auxInteger);
        while(validateInteger(auxInteger) == 0 || atoi(auxInteger) > maximum || atoi(auxInteger) < minimum)
        {
            printMessage(messageError);
            askForData(auxInteger);
        }
        *validatedInteger = atoi(auxInteger);
        allOk = 1;
    }
    return allOk;
}

/**
 * @brief Valida si una cadena de caracteres contiene solo letras (sin espacios ni números).
 * Esta función verifica si una cadena de caracteres contiene exclusivamente letras del alfabeto, sin espacios ni números.
 * @param text La cadena de caracteres que se desea validar.
 * @return Devuelve 1 si la cadena contiene solo letras, 0 en caso contrario.
 */
static int validateOnlyCharacters(char text[])
{
	int onlyHasCharacters = 1;
	int i = 0;
	if (text != NULL)
	{
		while (text[i] != '\0')
		{
			if (text[i] != ' ' && (text[i] < 'a' || text[i] > 'z') && (text[i] < 'A' || text[i] > 'Z'))
			{
				onlyHasCharacters = 0;
			}
			i++;
		}
	}
	return onlyHasCharacters;
}

/**
 * @brief Ordena una cadena de caracteres como una frase capitalizada.
 * Esta función convierte la primera letra de la cadena en mayúscula y las letras iniciales de cada palabra en minúscula,
 * manteniendo el resto de la cadena en minúscula.
 * @param text La cadena de caracteres que se desea ordenar como frase capitalizada.
 * @return Devuelve 1 si la cadena se ha ordenado correctamente, 0 en caso de error (puntero nulo).
 */
static int orderString(char text[])
{
	int allOk = 0;
	if (text != NULL)
	{
		strlwr(text);
		text[0] = toupper(text[0]);
		for(int i = 0; text[i] != '\0'; i++)
		{
			if (text[i] == ' ')
            text[i + 1] = toupper(text[i + 1]);
		}
		allOk = 1;
	}
	return allOk;
}

/**
 * @brief Solicita al usuario una entrada de texto y realiza validaciones y formato específicos.
 * Esta función muestra un mensaje al usuario, solicita una entrada de texto y aplica validaciones. Luego, formatea el texto
 * para que la primera letra de cada palabra esté en mayúscula y el resto en minúscula.
 * @param validatedText Puntero a la variable donde se almacenará el texto validado y formateado.
 * @param message El mensaje que se muestra como indicación.
 * @param messageError El mensaje de error que se muestra para una entrada no válida.
 * @param maximum La longitud máxima permitida para el texto.
 * @return Devuelve 1 si se ingresa un texto válido y se aplica el formato correctamente, 0 en caso contrario.
 */
int askForText(char* validatedText, char message[], char messageError[], int maximum)
{
    int allOk = 0;
    if(validatedText != NULL && message != NULL && messageError != NULL && maximum > 0)
    {
        char auxText[256];
		printMessage(message);
		askForData(auxText);
		while(strlen(auxText) > maximum || validateOnlyCharacters(auxText) == 0 || auxText[0] == 0)
        {
            printMessage(messageError);
		    askForData(auxText);
        }
        strcpy(validatedText, auxText);
        orderString(validatedText);
        allOk = 1;
    }
    return allOk;
}

/**
 * @brief Solicita al usuario un nombre de archivo en formato CSV y realiza validaciones.
 * Esta función muestra un mensaje al usuario, solicita un nombre de archivo y verifica si cumple con el formato de archivo CSV
 * (extensión ".csv"). Luego, almacena el nombre de archivo en la variable `text`.
 * @param text Puntero a la variable donde se almacenará el nombre de archivo válido.
 * @param message El mensaje que se muestra como indicación.
 * @param messageError El mensaje de error que se muestra para una entrada no válida.
 * @return Devuelve 1 si se ingresa un nombre de archivo en formato CSV válido, 0 en caso contrario.
 */
int askForCSVFile(char* text, char* message, char* messageError)
{
    int allOk = 0;
    if (text != NULL && message != NULL && messageError != NULL)
    {
        char auxText[256];
        printf("%s", message);
        scanf("%s", auxText);
        int len = strlen(auxText);
        if (len >= 4 && strcmp(auxText + len - 4, ".csv") == 0)
        {
            strcpy(text, auxText);
            allOk = 1;
        }
        else
        {
            printf("%s", messageError);
        }
    }
    return allOk;
}
