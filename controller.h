#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"

int controller_cargarArchivoDesdeTexto(char* path, Linkedlist* arrayListaServicios);
int controller_imprimirLista(Linkedlist* arrayListaServicios);

#endif // CONTROLLER_H_INCLUDED
