#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"

int cargarArchivoDesdeTexto(char* path, Linkedlist* arrayListaServicios)
{
    int todoOk = 0;
    FILE* file;
    if(path != NULL && arrayListaServicios != NULL)
    {
        file = fopen(path, "r");
        if(file != NULL)
        {
            printf("hola 1");
            parser_ServiciosDesdeTexto(file, arrayListaServicios);
            printf("hola");
            todoOk = 1;
        }
        fclose(file);
    }
    return todoOk;
}
