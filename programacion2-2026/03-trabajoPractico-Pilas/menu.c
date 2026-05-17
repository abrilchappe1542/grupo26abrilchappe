#include "menu.h"

void menuPunto6(){
    Pila p;

    int cantidad;
    int seguir = 1;
    while (seguir == 1)
    {
        printf("Ingrese la cantidad de elementos a cargar en las pilas (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila 1:\n");
        p = p_cargar(cantidad);
    
    
    if (p_es_vacia(p))
    {
        printf("La pila esta vacia");
        return;
    }

    int valor = ingresoDatosNumericos("Ese valor no es posible ingresar. Porfavor ingresa un numero valido");
    Pila pres = p_ej6_eliminarclaveRecursivo(p,valor);

    printf("Que queres ejecutar?\n->(1) Iterativo\n(2)-> Recursivon\n");
    int Ite_o_Rec = ingresoIntLimitado("Ese valor no es posible, ingresa un valor valido (1. Ite, 2. Rec)",1,2);

    printf("La pila sin el valor %d quedo asi:\n|\n|",valor);
    p_mostrar(p);

    printf("La complejidad algoritmica de la funcion iterativa como de la recursiva es de orden lineal O(n) teniendo en cuenta las tads ya que el tiempo de ejecucion \nse ajustara en base al tamanio del programa");
    
    seguir = preguntarContinuar();
    system("cls");
    }
}

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
