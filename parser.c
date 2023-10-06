#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"
#include "parser.h"
#include "LinkedList.h"

int parser_ServiciosDesdeTexto(FILE* file, Linkedlist* arrayListaServicios)
{
	int allOk = -1;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];
	eServicio* newCompra = NULL;
	int r=0;

	file = fopen("servicios.csv","r");
	if(file == NULL)
	{
		file("\nEl archivo es nulo");
	}

	fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);

	while(!feof(file))
	{
		r=fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
		if(r<6)
		{
			break;
		}
		newCompra = compras_NewParametros(var1,var2,var3,var4,var5,var6);

		if(newCompra != NULL)
		{
			ll_add(arrayListaServicios,newCompra);
			allOk = 1;
		}
	}
	fclose(pFile);

	return allOk;
}
