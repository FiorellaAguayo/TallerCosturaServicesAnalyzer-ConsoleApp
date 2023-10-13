#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

eServicio* newServicio()
{
    eServicio* unServicio;
    unServicio = (eServicio*)malloc(sizeof(eServicio));
    if(unServicio != NULL)
    {
        unServicio->id_servicio = 0;
        strcpy(unServicio->descripcion, "-");
        unServicio->tipo = 0;
        unServicio->precioUnitario = 0;
        unServicio->cantidad = 0;
        unServicio->totalServicio = 0;
    }
    return unServicio;
}

eServicio* servicio_newParametros(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr)
{
    eServicio* unServicio;
    unServicio = newServicio();
    if(unServicio != NULL)
    {
        while(servicio_setId(unServicio, atoi(idStr)) == 0
              && servicio_setDescripcion(unServicio, descripcionStr) == 0
              && servicio_setTipo(unServicio, atoi(tipoStr)) == 0
              && servicio_setPrecioUnitario(unServicio, atof(precioUnitarioStr)) == 0
              && servicio_setCantidad(unServicio, atoi(cantidadStr)) == 0
              && servicio_setTotalServicios(unServicio, atof(totalServicioStr)) == 0)
        {
            servicio_deleteServicio(unServicio);
            unServicio = NULL;
        }
    }
    return unServicio;
}

void servicio_deleteServicio(eServicio* unServicio)
{
    free(unServicio);
}

int servicio_setId(eServicio* unServicio, int idServicio)
{
    int todoOk = 0;
    if(unServicio != NULL && idServicio > 0)
    {
        unServicio->id_servicio = idServicio;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_getId(eServicio* unServicio, int* idServicio)
{
    int todoOk = 0;
    if(unServicio != NULL && idServicio != NULL)
    {
        *idServicio = unServicio->id_servicio;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_setDescripcion(eServicio* unServicio, char* descripcion)
{
	int todoOk = 0;
	if(unServicio != NULL && descripcion != NULL)
	{
		strcpy(unServicio->descripcion, descripcion);
	}
	todoOk = 1;
    return todoOk;
}

int servicio_getDescripcion(eServicio* unServicio, char* descripcion)
{
	int todoOk = 0;
	if(unServicio != NULL && descripcion != NULL)
	{
		strcpy(descripcion, unServicio->descripcion);
		todoOk = 1;
	}
	return todoOk;
}

int servicio_setTipo(eServicio* unServicio, int tipo)
{
    int todoOk = 0;
    if(unServicio != NULL && tipo > 0)
    {
        unServicio->tipo = tipo;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_getTipo(eServicio* unServicio, int* tipo)
{
    int todoOk = 0;
    if(unServicio != NULL && tipo != NULL)
    {
        *tipo = unServicio->tipo;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_setPrecioUnitario(eServicio* unServicio, float precioUnitario)
{
    int todoOk = 0;
    if(unServicio != NULL && precioUnitario > 0)
    {
        unServicio->precioUnitario = precioUnitario;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_setCantidad(eServicio* unServicio, int cantidad)
{
    int todoOk = 0;
    if(unServicio != NULL && cantidad > 0)
    {
        unServicio->cantidad = cantidad;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_getCantidad(eServicio* unServicio, int* cantidad)
{
    int todoOk = 0;
    if(unServicio != NULL && cantidad != NULL)
    {
        *cantidad = unServicio->cantidad;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_getPrecioUnitario(eServicio* unServicio, float* precioUnitario)
{
    int todoOk = 0;
    if(unServicio != NULL && precioUnitario != NULL)
    {
        *precioUnitario = unServicio->precioUnitario;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_setTotalServicios(eServicio* unServicio, float totalServicio)
{
    int todoOk = 0;
    if(unServicio != NULL && totalServicio > 0)
    {
        unServicio->totalServicio = totalServicio;
        todoOk = 1;
    }
    return todoOk;
}

int servicio_getTotalServicios(eServicio* unServicio, float* totalServicio)
{
    int todoOk = 0;
    if(unServicio != NULL && totalServicio != NULL)
    {
        *totalServicio = unServicio->totalServicio;
        todoOk = 1;
    }
    return todoOk;
}

void servicio_mostrarEncabezado()
{
    printf("\n-----------------------------------------------------------------------------------------------\n");
    printf("| id  |  descripcion       | tipo          | precio unitario        | cantidad | total servicio |\n");
    printf("-------------------------------------------------------------------------------------------------\n");
}

int servicio_mostrarUnServicio(eServicio* unServicio)
{
    int todoOk = 0;
    eServicio auxServicio;
    if(unServicio != NULL)
    {
        servicio_getId(unServicio, &auxServicio.id_servicio);
        servicio_getDescripcion(unServicio, auxServicio.descripcion);
        servicio_getTipo(unServicio, &auxServicio.tipo);
        servicio_getPrecioUnitario(unServicio, &auxServicio.precioUnitario);
        servicio_getCantidad(unServicio, &auxServicio.cantidad);
        servicio_getTotalServicios(unServicio, &auxServicio.totalServicio);

        printf("| %-3d | %-6s | %-15d | %-15f | %-10d | %-5f|\n", auxServicio.id_servicio, auxServicio.descripcion, auxServicio.tipo, auxServicio.precioUnitario, auxServicio.cantidad, auxServicio.totalServicio);
        todoOk = 1;
    }
    return todoOk;
}
