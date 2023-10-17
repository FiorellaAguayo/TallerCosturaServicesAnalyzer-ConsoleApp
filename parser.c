#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"
#include "parser.h"
#include "LinkedList.h"

int parser_ServiciosDesdeTexto(FILE* file, Linkedlist* arrayListaServicios)
{
	int allOk = -1;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	eServicio* unServicio;
	char header[256];

    fscanf(file, "%[^\n]\n", header);

	while(!feof(file))
	{
		fscanf(file, " %[^,],%[^,],%[^,],%[^,],%[^,], %[^\n]", var1, var2, var3, var4, var5, var6);
		unServicio = servicio_newParametros(var1, var2, var3, var4, var5, var6);
		if(unServicio != NULL)
		{
			ll_add(arrayListaServicios, unServicio);
			allOk = 1;
		}
	}
	return allOk;
}
