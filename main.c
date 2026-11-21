#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// FUNCION PARA MOSTRAR LOS REGISTROS
void mostrar(int fechas[], int estados[], int cantidad) {
    int i;

    printf("\n--- REGISTROS DE ASISTENCIA ---\n");

    if (cantidad == 0) {
        printf("No hay registros cargados.\n");
        return;
    }

    for (i = 0; i < cantidad; i++) {
        printf("Fecha: %d | ", fechas[i]);

        if (estados[i] == 1) {
            printf("Presente\n");
        } else {
            printf("Ausente\n");
        }
    }
}

// FUNCION PARA AGREGAR UN REGISTRO
void agregar(int fechas[], int estados[], int *cantidad) {
    int fecha, estado;

    if (*cantidad >= MAX) {
        printf("\nNo se pueden agregar mas registros.\n");
        return;
    }

    printf("\nIngrese la fecha (AAAAMMDD): ");
    scanf("%d", &fecha);

    printf("Ingrese 1 para presente o 0 para ausente: ");
    scanf("%d", &estado);

    if (estado != 0 && estado != 1) {
        printf("\nEstado incorrecto.\n");
        return;
    }

    fechas[*cantidad] = fecha;
    estados[*cantidad] = estado;

    (*cantidad)++;

    printf("\nRegistro agregado correctamente.\n");
}

// FUNCION PARA BUSCAR SECUENCIALMENTE
int buscarSecuencial(int fechas[], int cantidad, int fecha) {
    int i;

    for (i = 0; i < cantidad; i++) {
        if (fechas[i] == fecha) {
            return i;
        }
    }

    return -1;
}

// FUNCION PARA ORDENAR POR BURBUJA
void ordenarBurbuja(int fechas[], int estados[], int cantidad) {
    int i, j;
    int auxFecha, auxEstado;

    for (i = 0; i < cantidad - 1; i++) {
        for (j = 0; j < cantidad - 1 - i; j++) {

            if (fechas[j] > fechas[j + 1]) {

                auxFecha = fechas[j];
                fechas[j] = fechas[j + 1];
                fechas[j + 1] = auxFecha;

                auxEstado = estados[j];
                estados[j] = estados[j + 1];
                estados[j + 1] = auxEstado;
            }
        }
    }

    printf("\nRegistros ordenados por fecha.\n");
}

// FUNCION PARA BUSCAR BINARIAMENTE
int buscarBinaria(int fechas[], int cantidad, int fecha) {
    int inicio = 0;
    int fin = cantidad - 1;
    int medio;

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;

        if (fechas[medio] == fecha) {
            return medio;
        }

        if (fecha < fechas[medio]) {
            fin = medio - 1;
        } else {
            inicio = medio + 1;
        }
    }

    return -1;
}

// FUNCION PARA MODIFICAR UN REGISTRO
void actualizar(int fechas[], int estados[], int cantidad) {
    int fecha, posicion, nuevoEstado;

    printf("\nIngrese la fecha del registro que desea modificar: ");
    scanf("%d", &fecha);

    posicion = buscarSecuencial(fechas, cantidad, fecha);

    if (posicion == -1) {
        printf("\nNo se encontro el registro.\n");
        return;
    }

    printf("Ingrese el nuevo estado (1 presente / 0 ausente): ");
    scanf("%d", &nuevoEstado);

    if (nuevoEstado != 0 && nuevoEstado != 1) {
        printf("\nEstado incorrecto.\n");
        return;
    }

    estados[posicion] = nuevoEstado;

    printf("\nRegistro actualizado correctamente.\n");
}

// FUNCION PARA ELIMINAR UN REGISTRO
void eliminar(int fechas[], int estados[], int *cantidad) {
    int fecha, posicion, i;

    printf("\nIngrese la fecha del registro que desea eliminar: ");
    scanf("%d", &fecha);

    posicion = buscarSecuencial(fechas, *cantidad, fecha);

    if (posicion == -1) {
        printf("\nNo se encontro el registro.\n");
        return;
    }

    for (i = posicion; i < *cantidad - 1; i++) {
        fechas[i] = fechas[i + 1];
        estados[i] = estados[i + 1];
    }

    (*cantidad)--;

    printf("\nRegistro eliminado correctamente.\n");
}

// FUNCION PARA MOSTRAR EL TOTAL DE ASISTENCIAS E INASISTENCIAS
void mostrarTotales(int estados[], int cantidad) {
    int asistencias = 0;
    int inasistencias = 0;
    int i;

    for (i = 0; i < cantidad; i++) {
        if (estados[i] == 1) {
            asistencias++;
        } else {
            inasistencias++;
        }
    }

    printf("\n--- RESUMEN DE ASISTENCIAS ---\n");
    printf("Total de asistencias: %d\n", asistencias);
    printf("Total de inasistencias: %d\n", inasistencias);
    printf("Total de registros: %d\n", cantidad);
}

// PROGRAMA PRINCIPAL
int main() {

    int codigo;
    int fechas[MAX];
    int estados[MAX];
    int cantidad = 0;
    int opcion;
    int fechaBuscada;
    int posicion;

    printf("========================================\n");
    printf("   SISTEMA DE CONTROL DE ASISTENCIAS\n");
    printf("========================================\n");

    printf("\nIngrese su codigo de usuario: ");
    scanf("%d", &codigo);

    printf("\nBienvenido al sistema!\n");
    printf("Codigo de usuario: %d\n", codigo);

    do {

        printf("\n========================================\n");
        printf("          MENU DE ASISTENCIAS\n");
        printf("========================================\n");
        printf("1. Registrar asistencia o inasistencia\n");
        printf("2. Mostrar todos los registros\n");
        printf("3. Modificar un registro\n");
        printf("4. Eliminar un registro\n");
        printf("5. Buscar una fecha (secuencial)\n");
        printf("6. Ordenar registros por fecha\n");
        printf("7. Buscar una fecha (binaria)\n");
        printf("8. Mostrar totales\n");
        printf("0. Salir\n");

        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                agregar(fechas, estados, &cantidad);
                break;

            case 2:
                mostrar(fechas, estados, cantidad);
                break;

            case 3:
                actualizar(fechas, estados, cantidad);
                break;

            case 4:
                eliminar(fechas, estados, &cantidad);
                break;

            case 5:
                printf("\nIngrese la fecha que desea buscar (AAAAMMDD): ");
                scanf("%d", &fechaBuscada);

                posicion = buscarSecuencial(fechas, cantidad, fechaBuscada);

                if (posicion != -1) {
                    printf("\nRegistro encontrado.\n");
                    printf("Fecha: %d\n", fechas[posicion]);

                    if (estados[posicion] == 1) {
                        printf("Estado: Presente\n");
                    } else {
                        printf("Estado: Ausente\n");
                    }
                } else {
                    printf("\nFecha no encontrada.\n");
                }
                break;

            case 6:
                ordenarBurbuja(fechas, estados, cantidad);
                mostrar(fechas, estados, cantidad);
                break;

            case 7:
                ordenarBurbuja(fechas, estados, cantidad);

                printf("\nIngrese la fecha a buscar (AAAAMMDD): ");
                scanf("%d", &fechaBuscada);

                posicion = buscarBinaria(fechas, cantidad, fechaBuscada);

                if (posicion != -1) {
                    printf("\nRegistro encontrado.\n");
                    printf("Fecha: %d\n", fechas[posicion]);

                    if (estados[posicion] == 1) {
                        printf("Estado: Presente\n");
                    } else {
                        printf("Estado: Ausente\n");
                    }
                } else {
                    printf("\nFecha no encontrada.\n");
                }
                break;

            case 8:
                mostrarTotales(estados, cantidad);
                break;

            case 0:
                printf("\nSaliendo del sistema...\n");
                break;

            default:
                printf("\nOpcion incorrecta.\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}
