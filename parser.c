#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"
#include "parser.h"
#include "LinkedList.h"

/**
 * @brief Parsea y carga datos de un archivo de texto en una lista enlazada de compras.
 * Esta función toma un archivo de texto y lee los datos, que deben estar en un formato específico.
 * Luego, crea instancias de la estructura "eCompras" con los datos y los almacena en una lista enlazada.
 * @param file Puntero al archivo de texto desde el que se leerán los datos.
 * @param arrayList Puntero a la lista enlazada donde se almacenarán los datos.
 * @return Devuelve 1 si se parsean y cargan correctamente los datos en la lista, -1 en caso de error.
 */
int parser_entityFromText(FILE* file, Linkedlist* arrayList)
{
	int allOk = -1;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	eServicio* oneEntity;
	char header[256];
    fscanf(file, "%[^\n]\n", header);  // lectura fantasma
	while(!feof(file))
	{
		fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,], %[^\n]", var1, var2, var3, var4, var5, var6);
		oneEntity = entity_newParameters(var1, var2, var3, var4, var5, var6);
		if(oneEntity != NULL)
		{
			ll_add(arrayList, oneEntity);
			allOk = 1;
		}
	}
	return allOk;
}
