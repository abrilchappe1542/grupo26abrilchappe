#include "menu.h"

void main() {
    int opcion;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("2. Ejercicio 2 \n");
        printf("4. Ejercicio 4 \n");
        printf("7. Ejercicio 7 \n");
        printf("9. Ejercicio 9 \n");
        printf("0. Salir\n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoDatosNumericosPositivos("\nEntrada erronea.\n-> ");
        system("cls");

        switch (opcion) {
            case 2:
                menuPunto2();
                break;
            case 4:
                menuPunto4();
                break;
            case 7:
                menuPunto7();
                break;
            case 9:
                menuPunto9();
                break;
            case 0:
                printf("Saliendo...\n");
                system("pause");
                break;
            default:
                printf("AVISO: Ingrese un numero parte de las opciones.\n");
                break;
        }

    } while (opcion != 0);
}
