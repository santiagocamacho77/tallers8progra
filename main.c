#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int tiempos[MAX_PRODUCTOS];
    int recursos[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    int tiempoDisponible, recursosDisponibles;
    int opcion;

    // Ingreso de datos para tiempo y recursos disponibles
    printf("Ingrese el tiempo que trabajara la empresa (en minutos): ");
    scanf("%d", &tiempoDisponible);

    printf("Ingrese el numero de recursos de la empresa : ");
    scanf("%d", &recursosDisponibles);

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Verificar capacidad\n");
        printf("6. Productos en el tiempo total de trabajo de la empresa\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(nombres, tiempos, recursos, &cantidadProductos);
                break;
            case 2:
                mostrarProductos(nombres, tiempos, recursos, cantidadProductos);
                break;
            case 3:
                editarProducto(nombres, tiempos, recursos, cantidadProductos);
                break;
            case 4:
                eliminarProducto(nombres, tiempos, recursos, &cantidadProductos);
                break;
            case 5:
                verificarCapacidad(tiempoDisponible, recursosDisponibles,  tiempos,  recursos, nombres,cantidadProductos);
                break;
            case 7:
                printf("Saliendo....\n");
                break;
            case 6:
                calcularProductosEnTiempo(tiempoDisponible, nombres,tiempos,cantidadProductos);
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 7);

    return 0;
}