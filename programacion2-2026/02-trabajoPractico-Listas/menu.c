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

//menu punto 2
void menuPunto2() {
    Lista l1, l2, lresA, lresB, lresC;
    ResultadoValorMinimo resvm;
    int seguir = 1;
    int cantidad;

    while (seguir == 1) {
        printf("Ingrese la cantidad de elementos para las listas: ");
        cantidad = ingresoDatosNumericosNoCero("Ingresa un numero valido!");

        printf("\nCargando Lista 1...");
        l1 = l_cargar(cantidad);
        printf("\nCargando Lista 2...");
        l2 = l_cargar(cantidad);
        
    
        printf("\nLISTA 1: "); l_mostrar(l1);
        printf("\nLISTA 2: "); l_mostrar(l2);

        
        printf("\n2.A Elementos de L1 que no estan en L2: ");
        lresA = verElementosQueNoSeRepiten(l1, l2);
        l_mostrar(lresA);

        
        printf("\n2.B Elementos de L2 que no estan en L1: ");
        lresB = verElementosQueNoSeRepiten(l2, l1); 
        l_mostrar(lresB);

      
        printf("\n2.C Elementos comunes en ambas listas: ");
        lresC = verElementosRepetidos(l1, l2);
        l_mostrar(lresC);

        
        printf("\n2.D Promedios:");
        printf("\n*Promedio L1: %.2f", promedio(l1));
        printf("\n*Promedio L2: %.2f\n", promedio(l2));

        
        printf("\n2.E Valores minimos encontrados:");
        resvm = valorMinimo(l1, l2);
        printf("\n*L1: Minimo %d (Posicion %d)", resvm.valor, resvm.pos);
        printf("\n*L2: Minimo %d (Posicion %d)\n", resvm.valor_2, resvm.pos_2);

        seguir = preguntarContinuar();
        system("cls");
    }
}


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

void menuPunto5(){
    //Lista list1;
    Lista list1 = l_crear();
    int seguir = 1;
    while(seguir == 1){
        list1=hacerPolinomio(list1);
        //l_mostrar(list1);
        printf("Ingrese el rango para evaluar el polinomio:\n");
        printf("Ingrese el limite inferior (x): ");
        float x = ingresoDatosFloat("Debe ser un numero valido! Ingrese el valor del limite inferior (x): ");
        printf("Ingrese el limite superior (y): ");
        float y = ingresoDatosFloat("Debe ser un numero valido! Ingrese el valor del limite superior (y): ");
        printf("Ingrese el valor del sumando: ");
        float sumando = ingresoDatosFloat("Debe ser un numero valido! Ingrese el valor del sumando: ");
        Lista rango = calcularRango(list1, x, y, sumando);
        printf("Resultados del rango:\n");
        //l_mostrar(rango);

        Iterador it = iterador(rango);
        while(hay_siguiente(it)){
            float c = *(float*)siguiente(it)->valor;
            printf("%f\n", c);
        }
        seguir = preguntarContinuar();
        system("cls");  
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
