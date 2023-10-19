#ifndef entity_H_INCLUDED
#define entity_H_INCLUDED

typedef struct
{
    int id_servicio;
    char descripcion[30];
    int tipo;
    float precioUnitario;
    int cantidad;
    float totalServicio;
}eServicio;

#endif // entity_H_INCLUDED

eServicio* entity_new();
eServicio* entity_newParameters(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr);

void entity_deleteEntity(eServicio* entity);

int entity_setId(eServicio* entity, int idServicio);
int entity_getId(eServicio* entity, int* idServicio);

int entity_setDescripcion(eServicio* entity, char* descripcion);
int entity_getDescripcion(eServicio* entity, char* descripcion);

int entity_setTipo(eServicio* entity, int tipo);
int entity_getTipo(eServicio* entity, int* tipo);

int entity_setPrecioUnitario(eServicio* entity, float precioUnitario);
int entity_getPrecioUnitario(eServicio* entity, float* precioUnitario);

int entity_setCantidad(eServicio* entity, int cantidad);
int entity_getCantidad(eServicio* entity, int* cantidad);

int entity_setTotalServicios(eServicio* entity, float totalServicio);
int entity_getTotalServicios(eServicio* entity, float* totalServicio);

void entity_showHeader();
int entity_showOneEntity(eServicio* entity);

void* entity_map(void* element);
int entity_filterByMinorista(void* element);
int entity_filterByMayorista(void* element);
int entity_filterByExportar(void* element);
int entity_sortByDescripcion(void* item1, void* item2);

