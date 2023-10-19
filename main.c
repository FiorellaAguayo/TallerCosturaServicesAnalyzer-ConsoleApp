#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "inputs.h"
#include "LinkedList.h"
#include "controller.h"

int main()
{
    int stop = 0;
    int flag = 0;
    char fileName[30];
    Linkedlist* listaServicios = ll_newLinkedList();

    do
    {
        switch(menu())
        {
            case 1:
                //cargar archivo
                askForCSVFile(fileName, "\nPor favor, ingrese el nombre del archivo con extension .csv: ", "\nEl nombre no es valida");
                if(controller_loadFileFromText(fileName, listaServicios))
                {
                    printf("\nEl archivo '%s' se ha cargado correctamente.", fileName);
                    flag = 1;
                }
                else
                {
                    printf("\nHubo un problema al cargar el archivo.");
                }
                break;
            case 2:
                if(flag)
                {
                    if(controller_printList(listaServicios))
                    {
                        printf("\nSe imprimio la lista correctamente.");
                    }
                    else
                    {
                        printf("\nHubo un problema al imprimir '%s'.", fileName);
                    }
                }
                else
                {
                    printf("\n\nPrimero debes cargar el archivo.");
                }
                break;
            case 3:
                if(flag)
                {
                    if(controller_assignTotals(listaServicios))
                    {
                        printf("\nTotales asignados con exito!");
                    }
                    else
                    {
                        printf("\nHubo un problema al asignar los totales.");
                    }
                }
                else
                {
                    printf("\n\nPrimero debes cargar el archivo.");
                }
                break;
            case 4:
                if(flag)
                {
                    switch(menuFiltros())
                    {
                        case 1:
                            if(controller_filter_Minorista(listaServicios))
                            {
                                printf("\nSe cargo la lista filtrada de minorista.");
                            }
                            else
                            {
                                printf("\nHubo un problema al cargar la lista filtrada.");
                            }
                            break;

                        case 2:
                            if(controller_filter_Mayorista(listaServicios))
                            {
                                printf("\nSe cargo la lista filtrada de mayorista.");
                            }
                            else
                            {
                                printf("\nHubo un problema al cargar la lista filtrada.");
                            }
                            break;

                        case 3:
                            if(controller_filter_Exportar(listaServicios))
                            {
                                printf("\nSe cargo la lista filtrada de exportar.");
                            }
                            else
                            {
                                printf("\nHubo un problema al cargar la lista filtrada.");
                            }
                            break;
                    }
                }
                else
                {
                    printf("\nTodavia no se cargo el archivo.");
                }
                break;
            case 5:
                if(flag)
                {
                    if(controller_sortList(listaServicios))
                    {
                        printf("\nSe ordeno la lista exitosamente.");
                    }
                    else
                    {
                        printf("\nHubo un problema al ordenar la lista.");
                    }
                }
                else
                {
                    printf("\nTodavia no se cargo el archivo.");
                }
                break;
            case 6:
                if(flag)
                {
                    askForCSVFile(fileName, "¿Con que nombre desea guardar la lista? (.csv): ", "\nEl nombre no es valido. ");
                    if(controller_saveFileFromText(fileName, listaServicios))
                    {
                        printf("\nSe guardo la lista exitosamente!");
                    }
                    else
                    {
                        printf("\nHubo un problema al guardar la lista.");
                    }
                }
                else
                {
                    printf("\nTodavia no se cargo el archivo.");
                }
                break;
            case 7:
                //salir
                printf("\n\nGracias por utilizar este programa!");
                stop = 1;
                break;
        }
    }while(stop == 0);

    return 0;
}
