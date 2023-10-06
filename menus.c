#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

int menu()
{
	int opcion;

	printf("\n\n-------------------------");
	printf("\n         MENU            ");
	printf("\n-------------------------");
	printf("\n\n1. Cargar archivo.   ");
	printf("\n2. Imprimir lista.   ");
	printf("\n3. Asignar totales.     ");
	printf("\n4. Filtrar por tipo.     ");
	printf("\n5. Mostrar servicios.     ");
	printf("\n6. Guardar servicios.");
	printf("\n7. Salir.");

	pedirEntero(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 8);

	return opcion;
}
