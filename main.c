#include "menu.h"
#include "libs/validaciones/headers/validaciones.h"


int main() {
    int opcion;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ejercicio 1 -> Palindromo \n");
        printf("2. Ejercicio 2 -> Producto\n");
        printf("3. Ejercicio 3 -> Fibonacci\n");
        printf("4. Ejercicio 4 -> Division\n");
        printf("5. Ejercicio 5 -> Separador de miles\n");
        printf("6. Ejercicio 6 -> Mafia china\n");
        printf("7. Ejercicio 7 -> Onda digital\n");
        printf("8. Ejercicio 8 -> Subconjuntos\n");
        printf("9. Ejercicio 9 -> DivisiblePor7\n");
        printf("10.Ejercicio 10 -> Explosion\n");
        printf("0. Salir\n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoDatosNumericosPositivos("\nEntrada erronea.\n-> ");
        system("cls");

        switch (opcion) {
            case 1:
                menuPunto1();
                break;
            case 2:
                menuPunto2();
                break;
            case 3:
                menuPunto3();
                break;
            case 4:
                menuPunto4();
                break;
            case 5:
                menuPunto5();
                break;
            case 6:
                menuPunto6();
                break;
            case 7:
                menuPunto7();
                break;
            case 8:
                menuPunto8();
                break;
            case 9:
                menuPunto9();
                break;
            case 10:
                menuPunto10();
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

    return 0;
}
