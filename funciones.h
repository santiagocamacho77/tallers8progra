#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50
void ingresarProducto(char nombres[][MAX_NOMBRE], int tiempos[], int recursos[], int *cantidadProductos);
void mostrarProductos(char nombres[][MAX_NOMBRE], int tiempos[], int recursos[], int cantidadProductos);
int buscarProducto(char nombres[][MAX_NOMBRE], int cantidadProductos, char *nombreProducto);
void editarProducto(char nombres[][MAX_NOMBRE], int tiempos[], int recursos[], int cantidadProductos);
void eliminarProducto(char nombres[][MAX_NOMBRE], int tiempos[], int recursos[], int *cantidadProductos);
void verificarCapacidad(int tiempoDisponible, int recursosDisponibles, int tiempos[], int recursos[], char nombres[][MAX_NOMBRE], int cantidadProductos);
void calcularProductosEnTiempo(int tiempoDisponible, char nombres[][MAX_NOMBRE], int tiempos[], int cantidadProductos);

