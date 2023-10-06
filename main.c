#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "inputs.h"
#include "LinkedList.h"
#include "controller.h"

int main()
{
    int seguir = 1;
    int flag = 0;
    char nombreArchivo[30];
    Linkedlist* listaServicios = ll_newLinkedList();

    do
    {
        switch(menu())
        {
            case 1:
                //cargar archivo
                pedirArchivoCSV(nombreArchivo, "\nPor favor, ingrese el nombre del archivo con extension .csv: ", "\nEl nombre no es valida");
                if(cargarArchivoDesdeTexto(nombreArchivo, listaServicios))
                {
                    printf("\nEl archivo '%s' se ha cargado correctamente.", nombreArchivo);
                    flag = 1;
                }
                else
                {
                    printf("\nHubo un problema al cargar el archivo.");
                }
                break;
            case 2:
                //imprimir lista
                if(flag)
                {

                }
                else
                {
                    printf("\n\nPrimero debes cargar el archivo.");
                }
                break;
            case 3:
                //asignar totales
                if(flag)
                {

                }
                else
                {
                    printf("\n\nPrimero debes cargar el archivo.");
                }
                break;
            case 4:
                //filtrar por tipo
                if(flag)
                {

                }
                else
                {
                    printf("\n\nPrimero debes cargar el archivo.");
                }
                break;
            case 5:
                //mostrar servicios
                if(flag)
                {

                }
                else
                {
                    printf("\n\nPrimero debes cargar el archivo.");
                }
                break;
            case 6:
                //guardar servicios
                if(flag)
                {

                }
                else
                {
                    printf("\n\nPrimero debes cargar el archivo.");
                }
                break;
            case 7:
                //salir
                printf("\n\nGracias por utilizar este programa!");
                seguir = 0;
                break;
        }
    }while(seguir == 1);

    return 0;
}
