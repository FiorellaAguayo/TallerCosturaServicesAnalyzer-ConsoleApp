#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node* getNode(Linkedlist *this, int nodeIndex);
static int addNode(Linkedlist *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
Linkedlist* ll_newLinkedList(void)
{
	Linkedlist *this = NULL;

	this = (Linkedlist*) malloc(sizeof(Linkedlist));
	if (this != NULL)
	{
		this->size = 0;
		this->pFirstNode = NULL;
	}

	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(Linkedlist *this)
{
	int returnAux = -1;

	if (this != NULL)
	{
		returnAux = this->size;
	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(Linkedlist *this, int nodeIndex)
{
	Node *auxNode = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		auxNode = this->pFirstNode; //inicializo pNodo a la dirección del primer nodo
		if(auxNode != NULL)
		{
			for(int i = 0; i < nodeIndex; i++)
			{
				auxNode = auxNode->pNextNode; // voy a iterar hata encontrar el indice pasado por parametro
			}
		}
	}

	return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(Linkedlist *this, int nodeIndex)
{
	return getNode(this, nodeIndex);
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
static int addNode(Linkedlist *this, int nodeIndex, void *pElement)
{
	int returnAux = -1;
	Node *nodo = NULL;
	Node *auxNodo = NULL;

	nodo = (Node*) malloc(sizeof(Node));
	auxNodo = (Node*) malloc(sizeof(Node));

	if (this != NULL && nodo != NULL && auxNodo != NULL)
	{
		if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
		{
			if (nodeIndex == 0)
			{
				nodo->pNextNode = this->pFirstNode;
				this->pFirstNode = nodo;
			}
			else
			{
				auxNodo = getNode(this, nodeIndex - 1);
				nodo->pNextNode = auxNodo->pNextNode;
				auxNodo->pNextNode = nodo;
			}
			nodo->pElement = pElement;
			this->size++;
			returnAux = 0;
		}
	}
	return returnAux;
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
int test_addNode(Linkedlist *this, int nodeIndex, void *pElement)
{
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(Linkedlist *this, void *pElement)
{
	int returnAux = -1;

	if (this != NULL && addNode(this, ll_len(this), pElement))
	{
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(Linkedlist *this, int index)
{
	void *returnAux = NULL;
	Node *pNodo = NULL;

	if (this != NULL && index >= 0 && index < (ll_len(this)))
	{
		pNodo = getNode(this, index);
		if (pNodo != NULL)
		{
			returnAux = pNodo->pElement;
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
int ll_set(Linkedlist *this, int index, void *pElement)
{
	int returnAux = -1;
	Node *pNodo = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		pNodo = getNode(this, index);
		if (pNodo != NULL)
		{
			pNodo->pElement = pElement;
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
int ll_remove(Linkedlist *this, int index)
{
	int returnAux = -1;
	Node *auxNodeUno = NULL;
	Node *auxNodeDos = NULL;
	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNodeUno = getNode(this, index);
		if (auxNodeUno != NULL)
		{
			if (index == 0)
			{
				this->pFirstNode = auxNodeUno->pNextNode;
				free(auxNodeUno);
				this->size--;
				returnAux = 0;
			}
			else
			{
				auxNodeDos = getNode(this, index - 1);
				if (auxNodeDos != NULL)
				{
					auxNodeDos->pNextNode = auxNodeUno->pNextNode;
					free(auxNodeUno);
					this->size--;
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
int ll_clear(Linkedlist *this)
{
	int returnAux = -1;

	if (this != NULL)
	{
		for (int i = 0; i < ll_len(this); i++)
		{
			ll_remove(this, 0);
		}
		returnAux = 0;
	}
	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(Linkedlist *this)
{
	int returnAux = -1;
	if (this != NULL)
	{
		if (!ll_clear(this))
		{
			free(this);
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
int ll_indexOf(Linkedlist *this, void *pElement)
{
	int returnAux = -1;

	if (this != NULL)
	{
		for (int i = 0; i < ll_len(this); i++)
		{
			if (ll_get(this, i) == pElement)
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(Linkedlist *this)
{
	int returnAux = -1;

	if (this != NULL)
	{
		int tam = ll_len(this);
		if (tam)
		{
			if (tam > 0)
			{
				returnAux = 0;
			}
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
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(Linkedlist *this, int index, void *pElement)
{
	int returnAux = -1;

	if (this != NULL && index >= 0 && pElement != NULL && addNode(this, index, pElement))
	{
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(Linkedlist *this, int index)
{
	void *returnAux = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this))
	{
		returnAux = ll_get(this, index);
		ll_remove(this, index);
	}
	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(Linkedlist *this, void *pElement)
{
	int returnAux = -1;
	if (this != NULL)
	{
		returnAux = 0;
		if (ll_indexOf(this, pElement) != -1)
		{
			returnAux = 1;
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(Linkedlist *this, Linkedlist *this2)
{
	int returnAux = -1;
	void *aux;

	if (this != NULL && this2 != NULL)
	{
		returnAux = 1;
		int tam = ll_len(this2);
		for (int i = 0; i < tam; i++)
		{
			aux = ll_get(this2, i);
			if (!ll_contains(this, aux))
			{
				returnAux = 0;
				break;
			}
		}
	}
	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
Linkedlist* ll_subList(Linkedlist *this, int from, int to)
{
	Linkedlist *cloneArray = NULL;

	if (this != NULL && from < to && from >= 0 && to <= ll_len(this))
	{
		cloneArray = ll_newLinkedList();
		if (cloneArray != NULL)
		{
			for (int i = from; i < to; i++)
			{
				ll_add(cloneArray, ll_get(this, i));
			}
		}
	}
	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
Linkedlist* ll_clone(Linkedlist *this)
{
	Linkedlist* listaClonada;
	if(this != NULL)
	{
		listaClonada = ll_subList(this, 0, ll_len(this));
	}
	return listaClonada;
}

int ll_sort(Linkedlist *this, int (*pFunc)(void*, void*), int order)
{
	int returnAux = -1;
	void* pElementI;
	void* pElementJ;

	if (this != NULL && pFunc != NULL && order >= 0 && order <= 1)
	{
		for(int i = 0; i < ll_len(this) - 1; i++)
		{
			for(int j = i + 1; j < ll_len(this); j++)
			{
				pElementI = ll_get(this, i);
				pElementJ = ll_get(this, j);

				if((pFunc(pElementI, pElementJ) > 0 && order == 1) || (pFunc(pElementI, pElementJ) < 0 && order == 0))
				{
					ll_set(this, j, pElementI);
					ll_set(this, i, pElementJ);
				}
			}
		}
		returnAux = 0;
	}

	return returnAux;
}
