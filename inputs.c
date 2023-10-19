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
 * Esta funci�n imprime el mensaje proporcionado en la consola si no es NULL.
 * @param message El mensaje que se imprimir�.
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
 * Esta funci�n lee una cadena de caracteres desde la consola y la almacena en el b�fer proporcionado.
 * @param text El b�fer donde se almacenar� la cadena de entrada.
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
 * @brief Valida si una cadena representa un n�mero entero.
 * Esta funci�n verifica si la cadena proporcionada se puede convertir en un n�mero entero.
 * @param integerToValidate La cadena que se va a validar.
 * @return Devuelve 1 si la cadena es un n�mero entero v�lido, 0 en caso contrario.
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
 * @brief Solicita al usuario que ingrese un n�mero entero dentro de un rango espec�fico.
 * Esta funci�n muestra un mensaje al usuario, solicita una entrada y valida si el valor ingresado es un n�mero entero v�lido
 * dentro del rango especificado.
 * @param validatedInteger Puntero a la variable donde se almacenar� el n�mero entero validado.
 * @param message El mensaje que se muestra como indicaci�n.
 * @param messageError El mensaje de error que se muestra para una entrada no v�lida.
 * @param minimum El valor m�nimo permitido para el entero.
 * @param maximum El valor m�ximo permitido para el entero.
 * @return Devuelve 1 si se ingresa un n�mero entero v�lido dentro del rango, 0 en caso contrario.
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
 * @brief Valida si una cadena de caracteres contiene solo letras (sin espacios ni n�meros).
 * Esta funci�n verifica si una cadena de caracteres contiene exclusivamente letras del alfabeto, sin espacios ni n�meros.
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
 * Esta funci�n convierte la primera letra de la cadena en may�scula y las letras iniciales de cada palabra en min�scula,
 * manteniendo el resto de la cadena en min�scula.
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
 * @brief Solicita al usuario una entrada de texto y realiza validaciones y formato espec�ficos.
 * Esta funci�n muestra un mensaje al usuario, solicita una entrada de texto y aplica validaciones. Luego, formatea el texto
 * para que la primera letra de cada palabra est� en may�scula y el resto en min�scula.
 * @param validatedText Puntero a la variable donde se almacenar� el texto validado y formateado.
 * @param message El mensaje que se muestra como indicaci�n.
 * @param messageError El mensaje de error que se muestra para una entrada no v�lida.
 * @param maximum La longitud m�xima permitida para el texto.
 * @return Devuelve 1 si se ingresa un texto v�lido y se aplica el formato correctamente, 0 en caso contrario.
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
 * Esta funci�n muestra un mensaje al usuario, solicita un nombre de archivo y verifica si cumple con el formato de archivo CSV
 * (extensi�n ".csv"). Luego, almacena el nombre de archivo en la variable `text`.
 * @param text Puntero a la variable donde se almacenar� el nombre de archivo v�lido.
 * @param message El mensaje que se muestra como indicaci�n.
 * @param messageError El mensaje de error que se muestra para una entrada no v�lida.
 * @return Devuelve 1 si se ingresa un nombre de archivo en formato CSV v�lido, 0 en caso contrario.
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
