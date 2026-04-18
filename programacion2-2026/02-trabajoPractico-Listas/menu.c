#include "menu.h"


//menu punto 3:
void menuPunto3(){
    ResultadosMul resp;
    Lista list1, list2;
    int cantidad, seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a ingresar en las listas\n-> ");
        cantidad= ingresoDatosNumericosNoCero("Ingrese un numero valido!");


        printf("\nCargamos lista 1:\n");
        list1 = l_cargar(cantidad);
        printf("\nCargamos lista 2:\n");
        list2 = l_cargar(cantidad);

        printf("\nLISTA 1: \n");
        l_mostrar(list1);
        printf("\nLISTA 2: \n");
        l_mostrar(list2);

        printf("|\n|\n|__RESULTADOS DE LOS ANALISIS (si son multiplos, si hay un escalar y cual):\n");
        resp = multiplo(list1, list2);
        printf(resp.esMultiplo? "\nLista 2 es multiplo de Lista 1":"\nLista 2 NO es multiplo de Lista 1");
        printf(resp.escalar? "\nExiste un numero escalar: %d":"\nNO existe un numero escalar", resp.numEscalar);

        seguir = preguntarContinuar();
        system("cls");
    }
}

//menu punto 4:
void menuPunto4(){
    Lista list1, list2;
    int cantidad, seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en las listas\n-> ");
        cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!");

        printf("\nCargamos lista 1:\n");
        list1 = l_cargar(cantidad);
        printf("\nCargamos lista 2:\n");
        list2 = l_cargar(cantidad);

        printf("\nLISTA 1: \n");
        l_mostrar(list1);
        printf("\nLISTA 2: \n");
        l_mostrar(list2);

        printf("|\n|\n|__RESULTADO DE LA COMPARACION:\n");
        CompararListas(list1, list2);

        seguir = preguntarContinuar();
        system("cls");
    }
}
