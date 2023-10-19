#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

/**
 * @brief Crea una nueva instancia de la estructura "eServicio" y la inicializa con valores predeterminados.
 * Esta funci�n aloca memoria din�mica para una nueva instancia de la estructura "eServicio" y la inicializa con valores predeterminados.
 * @return Puntero a la nueva instancia de "eServicio" creada, o NULL en caso de error en la asignaci�n de memoria.
 */
eServicio* entity_new()
{
    eServicio* entity;
    entity = (eServicio*)malloc(sizeof(eServicio));
    if(entity != NULL)
    {
        entity->id_servicio = 0;
        strcpy(entity->descripcion, " ");
        entity->tipo = 0;
        entity->precioUnitario = 0.00;
        entity->cantidad = 0;
        entity->totalServicio = 0.00;
    }
    return entity;
}

/**
 * @brief Crea una nueva instancia de la estructura "eServicio" y la inicializa con valores proporcionados.
 * Esta funci�n crea una nueva instancia de la estructura "eServicio" y la inicializa con valores proporcionados a trav�s de par�metros.
 * @param idStr Cadena que representa el ID del art�culo.
 * @param descripcionStr Cadena que representa la descripci�n del art�culo.
 * @param tipoStr Cadena que representa el tipo del art�culo.
 * @param precioUnitarioStr Cadena que representa el precio unitario del art�culo.
 * @param cantidadStr Cadena que representa la cantidad del art�culo.
 * @param totalServicioStr Cadena que representa el total del bulto del art�culo.
 * @return Puntero a la nueva instancia de "eServicio" creada y inicializada con los valores proporcionados, o NULL en caso de error.
 */
eServicio* entity_newParameters(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr)
{
    eServicio* entity;
    entity = entity_new();
    if(entity != NULL)
    {
        if( entity_setId(entity, atoi(idStr)) == -1 ||
            entity_setDescripcion(entity, descripcionStr) == -1 ||
            entity_setTipo(entity, atoi(tipoStr)) == -1 ||
            entity_setPrecioUnitario(entity, atof(precioUnitarioStr)) == -1 ||
            entity_setCantidad(entity, atoi(cantidadStr)) == -1 ||
            entity_setTotalServicios(entity, atof(totalServicioStr)) == -1 )
        {
            entity = NULL;
            entity_deleteEntity(entity);
        }
    }
    return entity;
}

/**
 * @brief Libera la memoria ocupada por una instancia de la estructura "eServicio".
 * Esta funci�n libera la memoria asignada din�micamente para una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" cuya memoria se desea liberar.
 */
void entity_deleteEntity(eServicio* entity)
{
    if(entity != NULL)
    {
        free(entity);
    }
}

/**
 * @brief Establece el ID del art�culo en una instancia de la estructura "eServicio".
 * Esta funci�n asigna un valor de ID del art�culo a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecer� el ID.
 * @param idArticulo El valor del ID del art�culo que se asignar� a la instancia.
 * @return Devuelve 0 si se establece correctamente el ID, -1 en caso de error (puntero nulo o ID no v�lido).
 */
int entity_setId(eServicio* entity, int idArticulo)
{
    int allOk = -1;
    if(entity != NULL && idArticulo > 0)
    {
        entity->id_servicio = idArticulo;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Obtiene el ID del art�culo de una instancia de la estructura "eServicio".
 * Esta funci�n obtiene el valor de ID del art�culo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendr� el ID del art�culo.
 * @param idArticulo Puntero a la variable donde se almacenar� el ID del art�culo.
 * @return Devuelve 0 si se obtiene correctamente el ID del art�culo, -1 en caso de error (punteros nulos).
 */
int entity_getId(eServicio* entity, int* idArticulo)
{
    int allOk = -1;
    if(entity != NULL && idArticulo != NULL)
    {
        *idArticulo = entity->id_servicio;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Establece la descripci�n de un art�culo en una instancia de la estructura "eServicio".
 * Esta funci�n asigna una descripci�n de art�culo a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecer� la descripci�n.
 * @param descripcion La cadena de caracteres que representa la descripci�n del art�culo.
 * @return Devuelve 0 si se establece correctamente la descripci�n, -1 en caso de error (puntero nulo).
 */
int entity_setDescripcion(eServicio* entity, char* descripcion)
{
	int allOk = -1;
	if(entity != NULL)
	{
		strcpy(entity->descripcion, descripcion);
        allOk = 0;
	}
    return allOk;
}

/**
 * @brief Obtiene la descripci�n de un art�culo desde una instancia de la estructura "eServicio".
 * Esta funci�n obtiene la descripci�n de un art�culo desde una instancia de la estructura "eServicio" y la almacena en la cadena de caracteres proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendr� la descripci�n.
 * @param descripcion Puntero a la cadena de caracteres donde se almacenar� la descripci�n del art�culo.
 * @return Devuelve 0 si se obtiene correctamente la descripci�n, -1 en caso de error (punteros nulos).
 */
int entity_getDescripcion(eServicio* entity, char* descripcion)
{
	int allOk = -1;
	if(entity != NULL && descripcion != NULL)
	{
		strcpy(descripcion, entity->descripcion);
		allOk = 0;
	}
	return allOk;
}

/**
 * @brief Establece el tipo de art�culo en una instancia de la estructura "eServicio".
 * Esta funci�n asigna un valor de tipo de art�culo a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecer� el tipo.
 * @param tipo El valor del tipo de art�culo que se asignar� a la instancia.
 * @return Devuelve 0 si se establece correctamente el tipo, -1 en caso de error (puntero nulo o tipo no v�lido).
 */
int entity_setTipo(eServicio* entity, int tipo)
{
    int allOk = -1;
    if(entity != NULL && tipo > 0)
    {
        entity->tipo = tipo;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Obtiene el tipo de art�culo de una instancia de la estructura "eServicio".
 * Esta funci�n obtiene el valor del tipo de art�culo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendr� el tipo de art�culo.
 * @param tipo Puntero a la variable donde se almacenar� el tipo de art�culo.
 * @return Devuelve 0 si se obtiene correctamente el tipo de art�culo, -1 en caso de error (punteros nulos).
 */
int entity_getTipo(eServicio* entity, int* tipo)
{
    int allOk = -1;
    if(entity != NULL && tipo != NULL)
    {
        *tipo = entity->tipo;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Establece el precio unitario de un art�culo en una instancia de la estructura "eServicio".
 * Esta funci�n asigna un valor de precio unitario a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecer� el precio unitario.
 * @param precioUnitario El valor del precio unitario del art�culo que se asignar� a la instancia.
 * @return Devuelve 0 si se establece correctamente el precio unitario, -1 en caso de error (puntero nulo o precio no v�lido).
 */
int entity_setPrecioUnitario(eServicio* entity, float precioUnitario)
{
    int allOk = -1;
    if(entity != NULL && precioUnitario > 0)
    {
        entity->precioUnitario = precioUnitario;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Obtiene el precio unitario de un art�culo desde una instancia de la estructura "eServicio".
 * Esta funci�n obtiene el valor del precio unitario del art�culo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendr� el precio unitario del art�culo.
 * @param precioUnitario Puntero a la variable donde se almacenar� el precio unitario del art�culo.
 * @return Devuelve 0 si se obtiene correctamente el precio unitario, -1 en caso de error (punteros nulos).
 */
int entity_getPrecioUnitario(eServicio* entity, float* precioUnitario)
{
    int allOk = -1;
    if(entity != NULL && precioUnitario != NULL)
    {
        *precioUnitario = entity->precioUnitario;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Establece la cantidad de un art�culo en una instancia de la estructura "eServicio".
 * Esta funci�n asigna un valor de cantidad a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecer� la cantidad.
 * @param cantidad El valor de la cantidad del art�culo que se asignar� a la instancia.
 * @return Devuelve 0 si se establece correctamente la cantidad, -1 en caso de error (puntero nulo).
 */
int entity_setCantidad(eServicio* entity, int cantidad)
{
    int allOk = -1;
    if(entity != NULL)
    {
        entity->cantidad = cantidad;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Obtiene la cantidad de un art�culo desde una instancia de la estructura "eServicio".
 * Esta funci�n obtiene el valor de cantidad del art�culo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendr� la cantidad del art�culo.
 * @param cantidad Puntero a la variable donde se almacenar� la cantidad del art�culo.
 * @return Devuelve 0 si se obtiene correctamente la cantidad, -1 en caso de error (punteros nulos).
 */
int entity_getCantidad(eServicio* entity, int* cantidad)
{
    int allOk = -1;
    if(entity != NULL && cantidad != NULL)
    {
        *cantidad = entity->cantidad;

        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Establece el total de compras de un art�culo en una instancia de la estructura "eServicio".
 * Esta funci�n asigna un valor de total de compras a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecer� el total de compras.
 * @param totalServicio El valor del total de compras del art�culo que se asignar� a la instancia.
 * @return Devuelve 0 si se establece correctamente el total de compras, -1 en caso de error (puntero nulo o total no v�lido).
 */
int entity_setTotalServicios(eServicio* entity, float totalServicio)
{
    int allOk = -1;
    if(entity != NULL && totalServicio >= 0)
    {
        entity->totalServicio = totalServicio;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Obtiene el total de compras de un art�culo desde una instancia de la estructura "eServicio".
 * Esta funci�n obtiene el valor del total de compras del art�culo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendr� el total de compras del art�culo.
 * @param totalServicio Puntero a la variable donde se almacenar� el total de compras del art�culo.
 * @return Devuelve 0 si se obtiene correctamente el total de compras, -1 en caso de error (punteros nulos).
 */
int entity_getTotalServicios(eServicio* entity, float* totalServicio)
{
    int allOk = -1;
    if(entity != NULL && totalServicio != NULL)
    {
        *totalServicio = entity->totalServicio;
        allOk = 0;
    }
    return allOk;
}

/**
 * @brief Muestra el encabezado de la tabla de compras.
 * Esta funci�n imprime en la consola el encabezado de la tabla de compras con las columnas correspondientes.
 */
void entity_showHeader()
{
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("| ID  |  DESCRIPCION               | TIPO            | PRECIO UNITARIO      | CANTIDAD   | TOTAL SERVICIO |\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
}

/**
 * @brief Muestra los detalles de un art�culo de compra.
 * Esta funci�n muestra en la consola los detalles de un art�culo de compra, incluyendo su ID, descripci�n, tipo, precio unitario, cantidad y total de servicio.
 * @param entity Puntero a la instancia de "eServicio" cuyos detalles se mostrar�n.
 * @return Devuelve 1 si se muestra correctamente el art�culo, 0 en caso de error (puntero nulo).
 */
int entity_showOneEntity(eServicio* entity)
{
    int allOk = 0;
    eServicio auxEntity;
    if(entity != NULL)
    {
        entity_getId(entity, &auxEntity.id_servicio);
        entity_getDescripcion(entity, auxEntity.descripcion);
        entity_getTipo(entity, &auxEntity.tipo);
        entity_getPrecioUnitario(entity, &auxEntity.precioUnitario);
        entity_getCantidad(entity, &auxEntity.cantidad);
        entity_getTotalServicios(entity, &auxEntity.totalServicio);

        printf("| %-3d | %-26s | %-15d | %-20.2f | %-10d | %-15.2f|\n", auxEntity.id_servicio, auxEntity.descripcion, auxEntity.tipo, auxEntity.precioUnitario, auxEntity.cantidad, auxEntity.totalServicio);
        printf("-----------------------------------------------------------------------------------------------------------\n");
        allOk = 1;
    }
    return allOk;
}

/**
 * @brief Calcula el total de compras y lo asigna a cada art�culo de compra en la lista.
 * Esta funci�n calcula el total de compras para cada art�culo de compra en la lista y lo asigna a cada instancia de "eServicio".
 * @param element Puntero a la instancia de "eServicio" en la lista.
 * @return Puntero a la instancia de "eServicio" con el total de compras calculado.
 */
void* entity_map(void* element)
{
    eServicio* entity;
    int cantidad;
    float precioUnitario;
    float totalServicio;
    entity = (eServicio*) element;
    entity_getCantidad(entity, &cantidad);
    entity_getPrecioUnitario(entity, &precioUnitario);

    if(entity != NULL)
    {
        totalServicio = (float)cantidad * precioUnitario;
        entity_setTotalServicios(entity, totalServicio);
    }
    return entity;
}

/**
 * @brief Filtra art�culos de jugueter�a en la lista.
 * Esta funci�n se utiliza como funci�n de filtro para identificar art�culos de jugueter�a en la lista de compras.
 * @param element Puntero a la instancia de "eServicio" en la lista.
 * @return Devuelve 1 si el art�culo es de jugueter�a, 0 en caso contrario o en caso de error (puntero nulo).
 */
int entity_filterByMinorista(void* element)
{
    int allOk = 0;
    eServicio* entity = (eServicio*) element;
    if(entity != NULL)
    {
        if(entity->tipo == 1)
        {
            allOk = 1;
        }
    }
    return allOk;
}

/**
 * @brief Filtra art�culos de electr�nica en la lista.
 * Esta funci�n se utiliza como funci�n de filtro para identificar art�culos de electr�nica en la lista de compras.
 * @param element Puntero a la instancia de "eServicio" en la lista.
 * @return Devuelve 1 si el art�culo es de electr�nica, 0 en caso contrario o en caso de error (puntero nulo).
 */
int entity_filterByMayorista(void* element)
{
    int allOk = 0;
    eServicio* entity = (eServicio*) element;
    if(entity != NULL)
    {
        if(entity->tipo == 2)
        {
            allOk = 1;
        }
    }
    return allOk;
}

/**
 * @brief Filtra art�culos de indumentaria en la lista.
 * Esta funci�n se utiliza como funci�n de filtro para identificar art�culos de indumentaria en la lista de compras.
 * @param element Puntero a la instancia de "eServicio" en la lista.
 * @return Devuelve 1 si el art�culo es de indumentaria, 0 en caso contrario o en caso de error (puntero nulo).
 */
int entity_filterByExportar(void* element)
{
    int allOk = 0;
    eServicio* entity = (eServicio*) element;
    if(entity != NULL)
    {
        if(entity->tipo == 3)
        {
            allOk = 1;
        }
    }
    return allOk;
}

/**
 * @brief Compara dos art�culos de compra por descripci�n para ordenamiento.
 * Esta funci�n se utiliza como funci�n de comparaci�n para ordenar dos art�culos de compra por su descripci�n en orden alfab�tico.
 * @param item1 Puntero a la primera instancia de "eServicio" para comparar.
 * @param item2 Puntero a la segunda instancia de "eServicio" para comparar.
 * @return Devuelve 1 si el primer art�culo es mayor en orden alfab�tico, -1 si es menor y 0 si son iguales o en caso de error (punteros nulos).
 */
int entity_sortByDescripcion(void* item1, void* item2)
{
    int allOk = 0;
    eServicio* entity1 = (eServicio*) item1;
    eServicio* entity2 = (eServicio*) item2;
    char description1[50];
    char description2[50];
    if(entity1 != NULL && entity2 != NULL)
    {
        if(entity_getDescripcion(entity1, description1) == 0 && entity_getDescripcion(entity2, description2) == 0)
        {
            if(strcmp(description1, description2) > 0)
            {
                allOk = 1;
            }
            else if(strcmp(description1, description2) < 0)
            {
                allOk = -1;
            }
        }
    }
    return allOk;
}
