#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id_servicio;
    char descripcion[30];
    int tipo;
    float precioUnitario;
    int cantidad;
    float totalServicio;
    int isEmpty;
}eServicio;

#endif // SERVICIO_H_INCLUDED

eServicio* newServicio();
eServicio* servicios_newParametros(char* idStr, char* descripcionStr, char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr);

void servicio_deleteServicio(eServicio* unServicio);

int servicio_setId(eServicio* unServicio, int idServicio);
int servicio_getId(eServicio* unServicio, int* idServicio);

int servicio_setDescripcion(eServicio* unServicio, char* descripcion);
int servicios_getDescripcion(eServicio* unServicio, char* descripcion);

int servicio_setTipo(eServicio* unServicio, int tipo);
int servicio_getTipo(eServicio* unServicio, int* tipo);

int servicio_setPrecioUnitario(eServicio* unServicio, float precioUnitario);
int servicio_getPrecioUnitario(eServicio* unServicio, float* precioUnitario);

int servicio_setCantidad(eServicio* unServicio, int cantidad);
int servicio_getCantidad(eServicio* unServicio, int* cantidad);

int servicio_setTotalServicios(eServicio* unServicio, float totalServicio);
int servicio_getTotalServicios(eServicio* unServicio, float* totalServicio);
