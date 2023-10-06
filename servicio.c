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

eServicio* servicios_newParametros(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr)
{
    eServicio* unServicio;
    unServicio = newServicio();
    if(unServicio != NULL)
    {
        while(!(servicio_setId(unServicio, atoi(idStr)
              && servicio_setDescripcion(unServicio, descripcionStr)
              && servicio_setTipo(unServicio, atoi(tipoStr))
              && servicio_setPrecioUnitario(unServicio, atof(precioUnitarioStr))
              && servicio_setCantidad(unServicio, atoi(cantidadStr))
              && servicio_setTotalServicios(totalServicioStr, atof(totalServicioStr)))))
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

int servicios_getDescripcion(eServicio* unServicio, char* descripcion)
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
