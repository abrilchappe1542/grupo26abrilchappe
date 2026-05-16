#include "menu.h"

void main() {
    int opcion;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("7. Ejercicio 7 \n");
        printf("0. Salir\n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoDatosNumericosPositivos("\nEntrada erronea.\n-> ");
        system("cls");

        switch (opcion) {
            case 7:
                menuPunto7();
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