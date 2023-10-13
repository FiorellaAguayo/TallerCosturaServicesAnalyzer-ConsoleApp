#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct Node
{
    void* pElement;               //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;       //puntero al prox nodo
}typedef Node;

struct Linkedlist
{
    Node* pFirstNode;
    int size;                 //cada vez que agrego o elimino un elemento size++/--
}typedef Linkedlist;

#endif // LINKEDLIST_H_INCLUDED

//Publicas
Linkedlist* ll_newLinkedList();
int ll_len(Linkedlist* thisList);
Node* test_getNode(Linkedlist* thisList, int nodeIndex);
int test_addNode(Linkedlist* thisList, int nodeIndex, void* pElement);
int ll_add(Linkedlist* thisList, void* pElement);
void* ll_get(Linkedlist* thisList, int nodeIndex);
int ll_set(Linkedlist* thisList, int nodeIndex, void* pElement);
int ll_remove(Linkedlist* thisList, int nodeIndex);
int ll_clear(Linkedlist* thisList);
int ll_deleteLinkedList(Linkedlist* thisList);
int ll_indexOf(Linkedlist* thisList, void* pElement);
int ll_isEmpty(Linkedlist* thisList);
int ll_push(Linkedlist* thisList, int nodeIndex, void* pElement);
void* ll_pop(Linkedlist* thisList, int nodeIndex);                          //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(Linkedlist* thisList, void* pElement);
int ll_containsAll(Linkedlist* thisList, Linkedlist* thisList2);
