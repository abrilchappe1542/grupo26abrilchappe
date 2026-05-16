#include "menu.h"

// EJERCICIO 7
void menuPunto7(){
    Pila pilon1, pilon2, p_resultado;
    int cantidad;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en las pilas (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila 1:\n");
        pilon1 = p_cargar(cantidad);
        printf("\nCargamos pila 2:\n");
        pilon2 = p_cargar(cantidad);

        printf("\nPILA 1: \n");
        p_mostrar(pilon1);
        printf("\nPILA 2: \n");
        p_mostrar(pilon2);

        p_resultado = p_ej7_elementoscomunes(pilon1, pilon2);
        printf("\nELEMENTOS EN COMUN: \n");
        p_mostrar(p_resultado);

        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nEsta funcion es de orden cuadratico: O(n * m) donde n es el tamanio de la pila 1, \ny m es el tamanio de la pila 2.");
        seguir = preguntarContinuar();
        system("cls");
    }
}