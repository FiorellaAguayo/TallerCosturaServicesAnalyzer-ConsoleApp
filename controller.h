#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"

int controller_loadFileFromText(char* path, Linkedlist* arrayList);
int controller_printList(Linkedlist* arrayList);
int controller_saveFileFromText(char* path, Linkedlist* arrayList);
int controller_assignTotals(Linkedlist* arrayList);
int controller_filter_Minorista(Linkedlist* arrayList);
int controller_filter_Mayorista(Linkedlist* arrayList);
int controller_filter_Exportar(Linkedlist* arrayList);
int controller_sortList(Linkedlist* arrayList);

#endif // CONTROLLER_H_INCLUDED
