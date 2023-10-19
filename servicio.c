#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

/**
 * @brief Crea una nueva instancia de la estructura "eServicio" y la inicializa con valores predeterminados.
 * Esta función aloca memoria dinámica para una nueva instancia de la estructura "eServicio" y la inicializa con valores predeterminados.
 * @return Puntero a la nueva instancia de "eServicio" creada, o NULL en caso de error en la asignación de memoria.
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
 * Esta función crea una nueva instancia de la estructura "eServicio" y la inicializa con valores proporcionados a través de parámetros.
 * @param idStr Cadena que representa el ID del artículo.
 * @param descripcionStr Cadena que representa la descripción del artículo.
 * @param tipoStr Cadena que representa el tipo del artículo.
 * @param precioUnitarioStr Cadena que representa el precio unitario del artículo.
 * @param cantidadStr Cadena que representa la cantidad del artículo.
 * @param totalServicioStr Cadena que representa el total del bulto del artículo.
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
 * Esta función libera la memoria asignada dinámicamente para una instancia de la estructura "eServicio".
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
 * @brief Establece el ID del artículo en una instancia de la estructura "eServicio".
 * Esta función asigna un valor de ID del artículo a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecerá el ID.
 * @param idArticulo El valor del ID del artículo que se asignará a la instancia.
 * @return Devuelve 0 si se establece correctamente el ID, -1 en caso de error (puntero nulo o ID no válido).
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
 * @brief Obtiene el ID del artículo de una instancia de la estructura "eServicio".
 * Esta función obtiene el valor de ID del artículo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendrá el ID del artículo.
 * @param idArticulo Puntero a la variable donde se almacenará el ID del artículo.
 * @return Devuelve 0 si se obtiene correctamente el ID del artículo, -1 en caso de error (punteros nulos).
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
 * @brief Establece la descripción de un artículo en una instancia de la estructura "eServicio".
 * Esta función asigna una descripción de artículo a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecerá la descripción.
 * @param descripcion La cadena de caracteres que representa la descripción del artículo.
 * @return Devuelve 0 si se establece correctamente la descripción, -1 en caso de error (puntero nulo).
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
 * @brief Obtiene la descripción de un artículo desde una instancia de la estructura "eServicio".
 * Esta función obtiene la descripción de un artículo desde una instancia de la estructura "eServicio" y la almacena en la cadena de caracteres proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendrá la descripción.
 * @param descripcion Puntero a la cadena de caracteres donde se almacenará la descripción del artículo.
 * @return Devuelve 0 si se obtiene correctamente la descripción, -1 en caso de error (punteros nulos).
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
 * @brief Establece el tipo de artículo en una instancia de la estructura "eServicio".
 * Esta función asigna un valor de tipo de artículo a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecerá el tipo.
 * @param tipo El valor del tipo de artículo que se asignará a la instancia.
 * @return Devuelve 0 si se establece correctamente el tipo, -1 en caso de error (puntero nulo o tipo no válido).
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
 * @brief Obtiene el tipo de artículo de una instancia de la estructura "eServicio".
 * Esta función obtiene el valor del tipo de artículo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendrá el tipo de artículo.
 * @param tipo Puntero a la variable donde se almacenará el tipo de artículo.
 * @return Devuelve 0 si se obtiene correctamente el tipo de artículo, -1 en caso de error (punteros nulos).
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
 * @brief Establece el precio unitario de un artículo en una instancia de la estructura "eServicio".
 * Esta función asigna un valor de precio unitario a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecerá el precio unitario.
 * @param precioUnitario El valor del precio unitario del artículo que se asignará a la instancia.
 * @return Devuelve 0 si se establece correctamente el precio unitario, -1 en caso de error (puntero nulo o precio no válido).
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
 * @brief Obtiene el precio unitario de un artículo desde una instancia de la estructura "eServicio".
 * Esta función obtiene el valor del precio unitario del artículo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendrá el precio unitario del artículo.
 * @param precioUnitario Puntero a la variable donde se almacenará el precio unitario del artículo.
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
 * @brief Establece la cantidad de un artículo en una instancia de la estructura "eServicio".
 * Esta función asigna un valor de cantidad a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecerá la cantidad.
 * @param cantidad El valor de la cantidad del artículo que se asignará a la instancia.
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
 * @brief Obtiene la cantidad de un artículo desde una instancia de la estructura "eServicio".
 * Esta función obtiene el valor de cantidad del artículo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendrá la cantidad del artículo.
 * @param cantidad Puntero a la variable donde se almacenará la cantidad del artículo.
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
 * @brief Establece el total de compras de un artículo en una instancia de la estructura "eServicio".
 * Esta función asigna un valor de total de compras a una instancia de la estructura "eServicio".
 * @param entity Puntero a la instancia de "eServicio" en la que se establecerá el total de compras.
 * @param totalServicio El valor del total de compras del artículo que se asignará a la instancia.
 * @return Devuelve 0 si se establece correctamente el total de compras, -1 en caso de error (puntero nulo o total no válido).
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
 * @brief Obtiene el total de compras de un artículo desde una instancia de la estructura "eServicio".
 * Esta función obtiene el valor del total de compras del artículo desde una instancia de la estructura "eServicio" y lo almacena en la variable proporcionada.
 * @param entity Puntero a la instancia de "eServicio" de la que se obtendrá el total de compras del artículo.
 * @param totalServicio Puntero a la variable donde se almacenará el total de compras del artículo.
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
 * Esta función imprime en la consola el encabezado de la tabla de compras con las columnas correspondientes.
 */
void entity_showHeader()
{
    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("| ID  |  DESCRIPCION               | TIPO            | PRECIO UNITARIO      | CANTIDAD   | TOTAL SERVICIO |\n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
}

/**
 * @brief Muestra los detalles de un artículo de compra.
 * Esta función muestra en la consola los detalles de un artículo de compra, incluyendo su ID, descripción, tipo, precio unitario, cantidad y total de servicio.
 * @param entity Puntero a la instancia de "eServicio" cuyos detalles se mostrarán.
 * @return Devuelve 1 si se muestra correctamente el artículo, 0 en caso de error (puntero nulo).
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
 * @brief Calcula el total de compras y lo asigna a cada artículo de compra en la lista.
 * Esta función calcula el total de compras para cada artículo de compra en la lista y lo asigna a cada instancia de "eServicio".
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
 * @brief Filtra artículos de juguetería en la lista.
 * Esta función se utiliza como función de filtro para identificar artículos de juguetería en la lista de compras.
 * @param element Puntero a la instancia de "eServicio" en la lista.
 * @return Devuelve 1 si el artículo es de juguetería, 0 en caso contrario o en caso de error (puntero nulo).
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
 * @brief Filtra artículos de electrónica en la lista.
 * Esta función se utiliza como función de filtro para identificar artículos de electrónica en la lista de compras.
 * @param element Puntero a la instancia de "eServicio" en la lista.
 * @return Devuelve 1 si el artículo es de electrónica, 0 en caso contrario o en caso de error (puntero nulo).
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
 * @brief Filtra artículos de indumentaria en la lista.
 * Esta función se utiliza como función de filtro para identificar artículos de indumentaria en la lista de compras.
 * @param element Puntero a la instancia de "eServicio" en la lista.
 * @return Devuelve 1 si el artículo es de indumentaria, 0 en caso contrario o en caso de error (puntero nulo).
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
 * @brief Compara dos artículos de compra por descripción para ordenamiento.
 * Esta función se utiliza como función de comparación para ordenar dos artículos de compra por su descripción en orden alfabético.
 * @param item1 Puntero a la primera instancia de "eServicio" para comparar.
 * @param item2 Puntero a la segunda instancia de "eServicio" para comparar.
 * @return Devuelve 1 si el primer artículo es mayor en orden alfabético, -1 si es menor y 0 si son iguales o en caso de error (punteros nulos).
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
