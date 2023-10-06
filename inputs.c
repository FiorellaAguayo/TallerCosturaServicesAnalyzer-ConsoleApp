#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

static void imprimirMensaje(char mensaje[]);
static void pedirDato(char cadena[]);
static int ValidarSoloLetras(char cadena[]);
static int ordenarCadena(char cadena[]);

/**
 * @brief Imprime un mensaje en la consola.
 * Esta funci�n imprime el mensaje proporcionado en la consola si no es NULL.
 * @param mensaje El mensaje que se imprimir�.
 */
static void imprimirMensaje(char mensaje[])
{
    if(mensaje != NULL)
    {
        printf(mensaje);
    }
}

/**
 * @brief Lee una cadena de caracteres desde la consola.
 * Esta funci�n lee una cadena de caracteres desde la consola y la almacena en el b�fer proporcionado.
 * @param cadena El b�fer donde se almacenar� la cadena de entrada.
 */
static void pedirDato(char cadena[])
{
    if(cadena != NULL)
    {
        char buffer[256];
        fflush(stdin);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';
        strcpy(cadena, buffer);
    }
}

/**
 * @brief Valida si una cadena representa un n�mero entero.
 * Esta funci�n verifica si la cadena proporcionada se puede convertir en un n�mero entero.
 * @param enteroAValidar La cadena que se va a validar.
 * @return Devuelve 1 si la cadena es un n�mero entero v�lido, 0 en caso contrario.
 */
int validarEntero(char enteroAValidar[])
{
    int todoOk = 1;
    if(strlen(enteroAValidar) > 0)
    {
        for(int i = 0; i < strlen(enteroAValidar); i++)
        {
            if(isdigit(enteroAValidar[i]) == 0)
            {
                if(i == 0 && enteroAValidar[0] == '-')
                {
                    todoOk = 1;
                }
                else
                {
                    todoOk = 0;
                }
            }
        }
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

/**
 * @brief Solicita al usuario que ingrese un n�mero entero dentro de un rango espec�fico.
 * Esta funci�n muestra un mensaje al usuario, solicita una entrada y valida si el valor ingresado es un n�mero entero v�lido
 * dentro del rango especificado.
 * @param enteroValidado Puntero a la variable donde se almacenar� el n�mero entero validado.
 * @param mensaje El mensaje que se muestra como indicaci�n.
 * @param mensajeError El mensaje de error que se muestra para una entrada no v�lida.
 * @param minimo El valor m�nimo permitido para el entero.
 * @param maximo El valor m�ximo permitido para el entero.
 * @return Devuelve 1 si se ingresa un n�mero entero v�lido dentro del rango, 0 en caso contrario.
 */
int pedirEntero(int* enteroValidado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int todoOk = 0;
    if(enteroValidado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo)
    {
        char auxEntero[150];
        imprimirMensaje(mensaje);
        pedirDato(auxEntero);

        while(validarEntero(auxEntero) == 0 || atoi(auxEntero) > maximo || atoi(auxEntero) < minimo)
        {
            imprimirMensaje(mensajeError);
            pedirDato(auxEntero);
        }

        *enteroValidado = atoi(auxEntero);
        todoOk = 1;
    }
    return todoOk;
}

static int ValidarSoloLetras(char cadena[])
{
	int soloHayLetras = 1;
	int i = 0;
	if (cadena != NULL)
	{
		while (cadena[i] != '\0')
		{
			if (cadena[i] != ' ' && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
			{
				soloHayLetras = 0;
			}
			i++;
		}
	}
	return soloHayLetras;
}

static int ordenarCadena(char cadena[])
{
	int todoOk = 0;
	if (cadena != NULL)
	{
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);

		for (int i = 0; cadena[i] != '\0'; i++)
		{
			if (cadena[i] == ' ')
				cadena[i + 1] = toupper(cadena[i + 1]);
		}
		todoOk = 1;
	}
	return todoOk;
}

int pedirCadena(char* cadenaValidada, char mensaje[], char mensajeError[], int maximo)
{
    int todoOk = 0;
    if(cadenaValidada != NULL && mensaje != NULL && mensajeError != NULL && maximo > 0)
    {
        char auxCadena[256];
		imprimirMensaje(mensaje);
		pedirDato(auxCadena);

		while(strlen(auxCadena) > maximo || ValidarSoloLetras(auxCadena) == 0 || auxCadena[0] == 0)
        {
            imprimirMensaje(mensajeError);
		    pedirDato(auxCadena);
        }
        strcpy(cadenaValidada, auxCadena);
        ordenarCadena(cadenaValidada);

        todoOk = 1;
    }
    return todoOk;
}

int pedirArchivoCSV(char* cadena, char* mensaje, char* mensajeError)
{
    int todoOk = 0;
    if (cadena != NULL && mensaje != NULL && mensajeError != NULL)
    {
        char auxCadena[256];
        printf("%s", mensaje);
        scanf("%s", auxCadena);

        int len = strlen(auxCadena);
        if (len >= 4 && strcmp(auxCadena + len - 4, ".csv") == 0)
        {
            strcpy(cadena, auxCadena);
            todoOk = 1;
        }
        else
        {
            printf("%s", mensajeError);
        }
    }
    return todoOk;
}
