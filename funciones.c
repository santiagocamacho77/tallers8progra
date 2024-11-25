#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 10
#define MAX_NOMBRE 50


void ingresarProducto(char nombres[][MAX_NOMBRE], int tiempos[], int recursos[], int *cantidadProductos) {
    if (*cantidadProductos >= MAX_PRODUCTOS) {
        printf("No se pueden ingresar más productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres[*cantidadProductos]);

    printf("Ingrese el tiempo de fabricación por unidad (en minutos): ");
    scanf("%d", &tiempos[*cantidadProductos]);

    printf("Ingrese los recursos requeridos por unidad: ");
    scanf("%d", &recursos[*cantidadProductos]);

    (*cantidadProductos)++;
}


void mostrarProductos(char nombres[][MAX_NOMBRE], int tiempos[], int recursos[], int cantidadProductos) {
    if (cantidadProductos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }

    printf("Productos ingresados:\n");
    for (int i = 0; i < cantidadProductos; i++) {
        printf("Producto: %s, Tiempo: %d minutos, Recursos: %d\n", nombres[i], tiempos[i], recursos[i]);
    }
}


int buscarProducto(char nombres[][MAX_NOMBRE], int cantidadProductos, char *nombreProducto) {
    for (int i = 0; i < cantidadProductos; i++) {
        if (strcmp(nombres[i], nombreProducto) == 0) {
            return i;
        }
    }
    return -1;
}


void editarProducto(char nombres[][MAX_NOMBRE], int tiempos[], int recursos[], int cantidadProductos) {
    char nombreProducto[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombreProducto);

    int indice = buscarProducto(nombres, cantidadProductos, nombreProducto);
    if (indice == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Ingrese el nuevo tiempo de fabricación por unidad (en minutos): ");
    scanf("%d", &tiempos[indice]);

    printf("Ingrese los nuevos recursos requeridos por unidad: ");
    scanf("%d", &recursos[indice]);

    printf("Producto editado correctamente.\n");
}


void eliminarProducto(char nombres[][MAX_NOMBRE], int tiempos[], int recursos[], int *cantidadProductos) {
    char nombreProducto[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombreProducto);

    int indice = buscarProducto(nombres, *cantidadProductos, nombreProducto);
    if (indice == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = indice; i < *cantidadProductos - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        tiempos[i] = tiempos[i + 1];
        recursos[i] = recursos[i + 1];
    }

    (*cantidadProductos)--; 
    printf("Producto eliminado correctamente.\n");
}

void verificarCapacidad(int tiempoDisponible, int recursosDisponibles, int tiempos[], int recursos[], char nombres[][MAX_NOMBRE], int cantidadProductos) {
    int totalMaterialesGastados = 0, totalProductosFabricables = 0;

    for (int i = 0; i < cantidadProductos; i++) {
        int productosPorTiempo = tiempoDisponible / tiempos[i];
        int productosPorRecursos = recursosDisponibles / recursos[i];
        int productosFabricables;
        if (productosPorTiempo < productosPorRecursos) {
            productosFabricables = productosPorTiempo;
        } else {
            productosFabricables = productosPorRecursos;
        }

        if (productosFabricables > 0) {
    
            int materialesGastadosPorProducto = productosFabricables * recursos[i];

            
            if (totalMaterialesGastados + materialesGastadosPorProducto > recursosDisponibles) {
                
                productosFabricables = (recursosDisponibles - totalMaterialesGastados) / recursos[i];
                materialesGastadosPorProducto = productosFabricables * recursos[i]; 
            }

            totalMaterialesGastados += materialesGastadosPorProducto;
            totalProductosFabricables += productosFabricables;

            
            printf("Se pueden fabricar %d unidades de '%s'.\n", productosFabricables, nombres[i]);
            printf("Materiales gastados para '%s': %d\n", nombres[i], materialesGastadosPorProducto);
        } else {
            printf("No se puede fabricar '%s' por falta de tiempo o recursos.\n", nombres[i]);
        }

        
        if (totalMaterialesGastados >= recursosDisponibles) {
            printf("Se ha alcanzado el límite de recursos disponibles.\n");

            
            char respuesta;
            printf("¿Desea agregar más materiales? (s/n): ");
            scanf(" %c", &respuesta); 

            if (respuesta == 's' || respuesta == 'S') {
                int materialesAdicionales;
                printf("Ingrese la cantidad de materiales adicionales: ");
                scanf("%d", &materialesAdicionales);
                recursosDisponibles += materialesAdicionales;
                printf("Ahora tiene %d materiales disponibles.\n", recursosDisponibles);
            } else {
                printf("No se agregarán más materiales.\n");
                break;  
            }
        }
    }

   
    printf("Total de productos fabricables: %d\n", totalProductosFabricables);
    printf("Total de materiales gastados: %d\n", totalMaterialesGastados);
}


void calcularProductosEnTiempo(int tiempoDisponible, char nombres[][MAX_NOMBRE], int tiempos[], int cantidadProductos) {
    int totalProductosSolicitados = 0;
    
    
    printf("Ingrese la cantidad total de productos solicitados (por ejemplo, 10 de sopa, 20 de arroz, etc.):\n");
    
    
    int cantidadSolicitada[MAX_PRODUCTOS];
    
    
    for (int i = 0; i < cantidadProductos; i++) {
        printf("¿Cuántas unidades de '%s' se requieren? ", nombres[i]);
        scanf("%d", &cantidadSolicitada[i]);
        totalProductosSolicitados += cantidadSolicitada[i];
    }

    
    for (int i = 0; i < cantidadProductos; i++) {
        int productosPosibles = tiempoDisponible / tiempos[i]; 
        
        if (productosPosibles >= cantidadSolicitada[i]) {
            printf("Se pueden fabricar suficientes unidades de '%s' (solicitado: %d, posible: %d).\n", nombres[i], cantidadSolicitada[i], productosPosibles);
        } else {
            printf("No se pueden fabricar suficientes unidades de '%s' (solicitado: %d, posible: %d).\n", nombres[i], cantidadSolicitada[i], productosPosibles);
        }
    }
    
   
    int tiempoTotalNecesario = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        int productosPosibles = tiempoDisponible / tiempos[i]; 
        int productosRealmenteFabricados;
        if (productosPosibles >= cantidadSolicitada[i]) {
            productosRealmenteFabricados = cantidadSolicitada[i];
        } else {
            productosRealmenteFabricados = productosPosibles;
        }
        tiempoTotalNecesario += productosRealmenteFabricados * tiempos[i];  
    }

    if (tiempoTotalNecesario <= tiempoDisponible) {
        printf("\nSi es posible cumplir con la produccion solicitada en el tiempo disponible!\n");
    } else {
        printf("\nNo es posible cumplir con la produccion solicitada en el tiempo disponible.\n");
    }
}