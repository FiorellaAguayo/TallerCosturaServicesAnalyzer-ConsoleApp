#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"
#include "LinkedList.h"
#include "servicio.h"

/**
 * @brief Carga datos desde un archivo de texto a una lista enlazada.
 * Esta función carga datos desde un archivo de texto en el formato especificado y los almacena en una lista enlazada.
 * @param path La ruta del archivo de texto que se desea cargar.
 * @param arrayList Puntero a la lista enlazada donde se almacenarán los datos cargados.
 * @return Devuelve 1 si los datos se cargan correctamente desde el archivo, 0 en caso contrario.
 */
int controller_loadFileFromText(char* path, Linkedlist* arrayList)
{
    int allOk = 0;
    FILE* file;
    if(path != NULL && arrayList != NULL)
    {
        file = fopen(path, "r");
        if(file != NULL)
        {
            parser_entityFromText(file, arrayList);
            allOk = 1;
        }
        fclose(file);
    }
    return allOk;
}

/**
 * @brief Guarda datos desde una lista enlazada a un archivo de texto.
 * Esta función toma una lista enlazada que contiene datos y los guarda en un archivo de texto en el formato especificado.
 * @param path La ruta del archivo de texto en el que se desea guardar los datos.
 * @param arrayList Puntero a la lista enlazada que contiene los datos a guardar.
 * @return Devuelve 1 si los datos se guardan correctamente en el archivo de texto, 0 en caso contrario.
 */
int controller_saveFileFromText(char* path, Linkedlist* arrayList)
{
	int allOk = 0;
	FILE* file;
	eServicio* entity;
	int id;
	char descripcion[30];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;
	if(path != NULL && arrayList != NULL)
	{
		file = fopen(path, "w");
		if(file != NULL)
		{
			entity = entity_new();
			fprintf(file,"id,descripcion,tipo,precioUnitario,cantidad,totalServicio");
			int tam = ll_len(arrayList);
			for(int i = 0; i < tam; i++)
			{
				entity = (eServicio*)ll_get(arrayList, i);
				if(entity != NULL)
				{
					entity_getId(entity, &id);
					entity_getDescripcion(entity, descripcion);
					entity_getTipo(entity, &tipo);
					entity_getCantidad(entity, &cantidad);
					entity_getPrecioUnitario(entity, &precioUnitario);
					entity_getTotalServicios(entity, &totalServicio);
					fprintf(file, "\n%d,%s,%d,%.2f,%d,%.2f", id, descripcion, tipo, precioUnitario, cantidad, totalServicio);
					allOk = 1;
				}
				else
				{
					break;
				}
			}
			fclose(file);
		}
	}
    return allOk;
}

/**
 * @brief Imprime los datos de una lista enlazada en la consola.
 * Esta función muestra en la consola los datos almacenados en una lista enlazada en un formato específico.
 * @param arrayList Puntero a la lista enlazada que contiene los datos a imprimir.
 * @return Devuelve 1 si se imprimen correctamente los datos de la lista, 0 en caso contrario.
 */
int controller_printList(Linkedlist* arrayList)
{
    int allOk = 0;
    eServicio* unServicio;
    if(arrayList != NULL)
    {
        int tam = ll_len(arrayList);
        if(tam > 0)
        {
            entity_showHeader();
            for(int i = 0; i < tam; i++)
            {
                unServicio = (eServicio*) ll_get(arrayList, i);
                if(unServicio != NULL)
                {
                    entity_showOneEntity(unServicio);
                }
            }
            allOk = 1;
        }
    }
    return allOk;
}

/**
 * @brief Calcula y asigna los totales de compras en una lista enlazada.
 * Esta función toma una lista enlazada que contiene datos de compras y calcula los totales de cada compra,
 * asignándolos a las respectivas estructuras.
 * @param arrayList Puntero a la lista enlazada que contiene los datos de compras.
 * @return Devuelve 1 si los totales se calculan y asignan correctamente, 0 en caso contrario.
 */
int controller_assignTotals(Linkedlist* arrayList)
{
    int allOk = 0;
    if(arrayList != NULL)
    {
        ll_map(arrayList, entity_map);
        allOk = 1;
    }
    return allOk;
}

/**
 * @brief Filtra y guarda en un archivo de texto las compras de juguetería de una lista enlazada.
 * Esta función toma una lista enlazada que contiene datos de compras y filtra las compras de juguetería.
 * Luego, guarda las compras filtradas en un archivo de texto con el nombre "FiltroJugueteria.csv".
 * @param arrayList Puntero a la lista enlazada que contiene los datos de compras.
 * @return Devuelve 1 si se filtran y guardan correctamente las compras de juguetería, 0 en caso contrario.
 */
int controller_filter_Minorista(Linkedlist* arrayList)
{
    int allOk = 0;
    Linkedlist* list;
    if(arrayList != NULL)
    {
        list = ll_filter(arrayList, entity_filterByMinorista);
        controller_saveFileFromText("FiltroMinorista.csv", list);
        allOk = 1;
    }
    return allOk;
}

/**
 * @brief Filtra y guarda en un archivo de texto las compras de electrónica de una lista enlazada.
 * Esta función toma una lista enlazada que contiene datos de compras y filtra las compras de electrónica.
 * Luego, guarda las compras filtradas en un archivo de texto con el nombre "FiltroElectronica.csv".
 * @param arrayList Puntero a la lista enlazada que contiene los datos de compras.
 * @return Devuelve 1 si se filtran y guardan correctamente las compras de electrónica, 0 en caso contrario.
 */
int controller_filter_Mayorista(Linkedlist* arrayList)
{
    int allOk = 0;
    Linkedlist* list;
    if(arrayList != NULL)
    {
        list = ll_filter(arrayList, entity_filterByMayorista);
        controller_saveFileFromText("FiltroMayorista.csv", list);
        allOk = 1;
    }
    return allOk;
}

/**
 * @brief Filtra y guarda en un archivo de texto las compras de electrónica de una lista enlazada.
 * Esta función toma una lista enlazada que contiene datos de compras y filtra las compras de electrónica.
 * Luego, guarda las compras filtradas en un archivo de texto con el nombre "FiltroElectronica.csv".
 * @param arrayList Puntero a la lista enlazada que contiene los datos de compras.
 * @return Devuelve 1 si se filtran y guardan correctamente las compras de electrónica, 0 en caso contrario.
 */
int controller_filter_Exportar(Linkedlist* arrayList)
{
    int allOk = 0;
    Linkedlist* list;
    if(arrayList != NULL)
    {
        list = ll_filter(arrayList, entity_filterByExportar);
        controller_saveFileFromText("FiltroExportar.csv", list);
        allOk = 1;
    }
    return allOk;
}

/**
 * @brief Ordena y muestra una lista enlazada de compras según un criterio especificado.
 * Esta función toma una lista enlazada que contiene datos de compras y la ordena según un criterio especificado.
 * Luego, muestra la lista ordenada en la consola.
 * @param arrayList Puntero a la lista enlazada que se desea ordenar y mostrar.
 * @return Devuelve 1 si la lista se ordena y muestra correctamente, 0 en caso contrario.
 */
int controller_sortList(Linkedlist* arrayList)
{
    int allOk = 0;
    if(arrayList != NULL)
    {
        int criterion = menuOrdenamiento();
        if(ll_isEmpty(arrayList) == 0)
        {
            ll_sort(arrayList, entity_sortByDescripcion, criterion);
            controller_printList(arrayList);
            allOk = 1;
        }
        else
        {
            printf("\nAtencion. La lista esta vacia!");
        }
    }
    return allOk;
}
