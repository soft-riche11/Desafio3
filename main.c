#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>

int main() {

    int codigo;
    int asistencias = 18;
    int inasistencias = 5;
    int opcion;

    printf("================================\n");
    printf("  SISTEMA DE CONTROL DE ASISTENCIAS\n");
    printf("================================\n");
    
    
    printf("\nIngrese su codigo de usuario: ");
    scanf("%d", &codigo);

    printf("\nBienvenido al sistema!\n");

    printf("\nCodigo de usuario: %d\n", codigo);

    printf("\n--- MIS ASISTENCIAS ---\n");

    printf("\n\n Presione 1 para ver asistencias y 2 para inasistencias: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("\nTotal de asistencias: %d\n", asistencias);
            break;

		case 2:
			printf("\nTotal de inasistencias: %d\n", inasistencias);
            break;

        default:
            printf("\nOpcion incorrecta\n");
            break;
    }
    return 0;
}
