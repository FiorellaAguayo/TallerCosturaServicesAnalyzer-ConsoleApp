#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node* getNode(Linkedlist* thisList, int nodeIndex);
static int addNode(Linkedlist* thisList, int nodeIndex, void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
Linkedlist* ll_newLinkedList()
{
    Linkedlist* thisList = NULL;
    thisList = (Linkedlist*)malloc(sizeof(Linkedlist));
    if(thisList != NULL)
    {
        thisList->size = 0;
        thisList->pFirstNode = NULL;
    }
    return thisList;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(Linkedlist* thisList)
{
    int longitud = -1;
    if(thisList != NULL)
    {
        longitud = thisList->size;
    }
    return longitud;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(Linkedlist* thisList, int nodeIndex)
{
    Node* nodo = NULL;
    if(thisList != NULL && nodeIndex >= 0 && nodeIndex < ll_len(thisList))
    {
        nodo = thisList->pFirstNode;  //nodo es la direccion del nodo 0
        for(int i = nodeIndex; i > 0; i--)
        {
            nodo = nodo->pNextNode;
        }
    }
    return nodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(Linkedlist* thisList, int nodeIndex)
{
    return getNode(thisList, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(Linkedlist* thisList, int nodeIndex, void* pElement)
{
    int todoOk = -1;
    Node* nuevoNodo = NULL;
    Node* anterior = NULL;
    if(thisList != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(thisList))
    {
        nuevoNodo->pElement = pElement;
        nuevoNodo->pNextNode = getNode(thisList, nodeIndex);
        if(nodeIndex == 0)
        {
            thisList->pFirstNode = nuevoNodo;
        }
        else
        {
            anterior = getNode(thisList, nodeIndex - 1);
            anterior->pNextNode = nuevoNodo;
        }
        thisList->size++;
        todoOk = 0;
    }
    return todoOk;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(Linkedlist* thisList, int nodeIndex, void* pElement)
{
    return addNode(thisList, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(Linkedlist* thisList, void* pElement)
{
    return addNode(thisList, ll_len(thisList), pElement);
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(Linkedlist* thisList, int nodeIndex)
{
    void* returnAux = NULL;
    Node* nodo = NULL;
    if(thisList != NULL && nodeIndex > 0 && nodeIndex < ll_len(thisList))
    {
        nodo = getNode(thisList, nodeIndex);
        if(nodo != NULL)
        {
            returnAux = nodo->pElement;
        }
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(Linkedlist* thisList, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* nodo = NULL;

    if(thisList != NULL && nodeIndex > 0 && nodeIndex < ll_len(thisList))
    {
        nodo = getNode(thisList, nodeIndex);
        if(nodo != NULL)
        {
            nodo->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(Linkedlist* thisList, int nodeIndex)
{
    int returnAux = -1;
    Node* auxNodoUno = NULL;
    Node* auxNodoDos = NULL;
    if(thisList != NULL && nodeIndex >=0 && nodeIndex < ll_len(thisList))
    {
    	auxNodoUno = getNode(thisList, nodeIndex);
    	if (auxNodoUno != NULL)
    	{
    		if( nodeIndex == 0 )
    		{
    			thisList -> pFirstNode = auxNodoUno->pNextNode;
    			free(auxNodoUno);
    			thisList -> size--;
    			returnAux = 0;
    		}
    		else
    		{
    			auxNodoDos = getNode (thisList , nodeIndex - 1);
    			if(auxNodoDos != NULL)
    			{
    				auxNodoDos -> pNextNode = auxNodoUno->pNextNode;
    				free(auxNodoUno);
    				thisList -> size --;
    				returnAux = 0; //repito porque funciona solo si entra aca.
    			}
    		}
    	}
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(Linkedlist* thisList)
{
    int returnAux = -1;

    if(thisList != NULL)
    {
        while(ll_len(thisList))
        {
           returnAux = ll_remove(thisList, 0);
           if(returnAux)
           {
               break;
           }
        }
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param thisList LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(Linkedlist* thisList)
{
    int returnAux = -1;
    if(thisList != NULL)
    {
        if(!ll_clear(thisList))
        {
            free(thisList);
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(Linkedlist* thisList, void* pElement)
{
    int returnAux = -1;
    if(thisList != NULL)
    {
        for(int i = 0; i < ll_len(thisList); i++) //no es <= por que tengo 5 elemnt lo que pasa que el indice de cada elemtn arranca en 0 entonces el ultimo es el 4 y si le pongo <= como el len es 5 el ult no existe
        { //si el tamaño es ll_len(thisList) entonces tiene ll_len(thisList)-1 indices
            if(ll_get(thisList, i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux; //me indica segun un element donde esta el elemento , en que indice en que nodo, me indica cual es la posicion
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(Linkedlist* thisList)
{
    int returnAux = -1;
    if(thisList != NULL)
    {
       if(ll_len(thisList))
       {
    	   returnAux = 0;
       }
       else
       {
    	   returnAux = 1;
       }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param thisList LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(Linkedlist* thisList, int nodeIndex, void* pElement)
{
	return addNode(thisList, nodeIndex, pElement);
}


/** \brief elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(Linkedlist* thisList, int nodeIndex)
{
    void* returnAux = NULL;
    if(thisList != NULL && nodeIndex > 0 && nodeIndex < ll_len(thisList))
    {
        returnAux = ll_get(thisList, nodeIndex);
        ll_remove(thisList, nodeIndex);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param thisList LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(Linkedlist* thisList, void* pElement)
{
    int returnAux = -1;
    if(thisList != NULL)
    {
        returnAux = 0;
        if(ll_indexOf(thisList, pElement) != -1)
        {
            returnAux = 1;
        }
    }
    return returnAux; //me retorna si existe o no existe el element, el nodo
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param thisList LinkedList* Puntero a la lista
 * \param thisList2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (thisList2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (thisList2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(Linkedlist* thisList, Linkedlist* thisList2)
{
    int returnAux = -1;
    if(thisList != NULL && thisList2 != NULL)
    {
        returnAux = 1;

        for(int i = 0; i < ll_len(thisList2); i++)
        {
            if(!ll_contains(thisList, ll_get(thisList2, i)))
            {
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}
