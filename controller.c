#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "servicio.h"

int controller_cargarArchivoDesdeTexto(char* path, Linkedlist* arrayListaServicios)
{
    int todoOk = 0;
    FILE* file;
    if(path != NULL && arrayListaServicios != NULL)
    {
        file = fopen(path, "r");
        if(file != NULL)
        {
            parser_ServiciosDesdeTexto(file, arrayListaServicios);
            todoOk = 1;
        }
        fclose(file);
    }
    return todoOk;
}

int controller_imprimirLista(Linkedlist* arrayListaServicios)
{
    int todoOk = 0;
    eServicio* unServicio = NULL;
    if(arrayListaServicios != NULL)
    {
        int tamLista = ll_len(arrayListaServicios);
        if(tamLista > 0)
        {
            servicio_mostrarEncabezado();
            for(int i = 0; i < tamLista; i++)
            {
                unServicio = (eServicio*) ll_get(arrayListaServicios, i);
                servicio_mostrarUnServicio(unServicio);
            }
            todoOk = 1;
        }
        else
        {
            servicio_deleteServicio(unServicio);
        }
    }
    return todoOk;
}
