#include "menu.h"
#include "..\libs\listas\headers\listas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_2_listas.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


// void menuPunto2(){
//     Lista l1,l2, lresA,lresB,lresC;
//     Resultados res2;
//     ResultadoValorMaximo resvm;
//     int seguir = 1;
//     int cantidad;
//     while (seguir == 1)
//     {
//         printf("Ingrese la cantidad de elementos a ingresar en las listas\n-> ");
//         cantidad= ingresoDatosNumericosNoCero("Ingrese un numero valido!");

//         printf("\nCargamos lista 1:\n");
//         l1 = l_cargar(cantidad);
//         printf("\nCargamos lista 2:\n");
//         l2 = l_cargar(cantidad);
        
//         //MUESTRO LAS LISTAS CARGADAS
//         printf("\nLISTA 1: \n");
//         l_mostrar(l1);
//         printf("\nLISTA 2: \n");
//         l_mostrar(l2);
    
//         //EJERCICIO A
//         printf("\nEJERCICIO 2A\n");
//         lresA = verElementosQueNoSeRepiten(l1,l2);
//         printf("\nLa lista con elementos de L1 que no estan en l2 es:\n");
//         l_mostrar(lresA);
        
//         //EJERCICIO B
//         printf("\nEJERCICIO 2B\n");
//         lresB = verElementosQueNoSeRepiten(l1,l2);
//         printf("\nLa lista con elementos de L2 que no estan en L1 es:\n");
//         l_mostrar(lresB);
        
//         //EJERCICIO C
//         printf("\nEJERCICIO 2C\n");
//         lresC = verElementosRepetidos(l1,l2);
//         printf("\nLa lista con elementos de L1 que se repiten en L2 es:\n");
//         l_mostrar(lresC);
        
        
//         //EJERCICIO D
//         printf("\nEJERCICIO 2D\n");
//         res2 = promedioAmbasListas(l1,l2);
//         printf("\nEl promedio de L1 es: %.2f \nEl promedio de L2 es: %.2f\n", res2.resultado1, res2.resultado2);
        
//         //EJERCICIO E
//         printf("\nEJERCICIO 2D\n");
//         resvm = valorMaximo(l1,l2);
//         printf("El valor minimo es %d en la posicion %d de la lista %d\n", resvm.valor, resvm.pos, resvm.lista);

//         seguir = preguntarContinuar();
//         system("cls");
//     }
    
// }


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


//void menuPunto6(){
//     Lista list1, list2;
//     int cantidad, seguir = 1;
//     bool res;
//     while(seguir == 1){
//         printf("Ingrese la cantidad de elementos a cargar en las listas\n-> ");
//         cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!");

//         printf("\nCargamos lista 1:\n");
//         list1 = l_cargar(cantidad);
//         printf("\nCargamos lista 2:\n");
//         list2 = l_cargar(cantidad);

//         printf("\nLISTA 1: \n");
//         l_mostrar(list1);
//         printf("\nLISTA 2: \n");
//         l_mostrar(list2);

//         res = esSublista(list1,list2);
//         printf(res? "La lista L2 es sublista de l1":"La lista L2 no es sublista de L1");

//         seguir = preguntarContinuar();
//         system("cls");    
//     }
// }
