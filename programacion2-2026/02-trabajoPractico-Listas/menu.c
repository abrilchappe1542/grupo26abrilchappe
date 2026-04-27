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
    int cantidad, cantidad2;
    char opcion;

    while (seguir == 1) {
        // --- 1. CARGA DE LISTAS (Variables y Dinámicas) ---
        printf("=== CARGA DE DATOS PARA EL EJERCICIO 2 ===\n");
        printf("Ingrese la cantidad de elementos para la lista 1: ");
        cantidad = ingresoDatosNumericosNoCero("Ingresa un numero valido!");
        printf("\nCargando Lista 1...\n");
        l1 = l_cargar(cantidad);

        printf("\nIngrese la cantidad de elementos para la lista 2: ");
        cantidad2 = ingresoDatosNumericosNoCero("Ingresa un numero valido!");
        printf("\nCargando Lista 2...\n");
        l2 = l_cargar(cantidad2);
        
        printf("\nLISTA 1: "); l_mostrar(l1);
        printf("\nLISTA 2: "); l_mostrar(l2);

        // --- 2. MENÚ DE OPCIONES DEL PUNTO 2 ---
        printf("\n=== OPCIONES DEL EJERCICIO 2 ===\n");
        printf("A. Elementos de L1 que no estan en L2\n");
        printf("B. Elementos de L2 que no estan en L1\n");
        printf("C. Elementos comunes en ambas listas\n");
        printf("D. Promedios de ambas listas\n");
        printf("E. Valores minimos encontrados\n");
        printf("\nElija una opcion (A, B, C, D o E): ");
        fflush(stdin);         
        scanf(" %c", &opcion);
        // Convertimos a mayúscula por si el usuario ingresa minúsculas
        if(opcion >= 'a' && opcion <= 'z') opcion = opcion - 32; 

        // --- 3. SWITCH DE EJECUCIÓN ---
        switch (opcion) {
            case 'A':
                printf("\n2.A Elementos de L1 que no estan en L2: \n");
                lresA = verElementosQueNoSeRepiten(l1, l2);
                if (l_es_vacia(lresA)) { //
                    printf("La lista esta vacia, todos los valores de L1 estan en L2\n");
                } else {
                    l_mostrar(lresA); //
                }
                break;

            case 'B':
                printf("\n2.B Elementos de L2 que no estan en L1: \n");
                // Excelente reutilización de la función invirtiendo los parámetros
                lresB = verElementosQueNoSeRepiten(l2, l1); 
                if (l_es_vacia(lresB)) { //
                    printf("La lista esta vacia, todos los valores de L2 estan en L1\n");
                } else {
                    l_mostrar(lresB); //
                }
                break;

            case 'C':
                printf("\n2.C Elementos comunes en ambas listas: \n");
                lresC = verElementosRepetidos(l1, l2);
                if (l_es_vacia(lresC)) { //
                    printf("No hay elementos comunes entre las listas.\n");
                } else {
                    l_mostrar(lresC); //
                }
                break;

            case 'D':
                printf("\n2.D Promedios:\n");
                printf("*Promedio L1: %.2f\n", promedio(l1));
                printf("*Promedio L2: %.2f\n", promedio(l2));
                break;

            case 'E':
                printf("\n2.E Valores minimos encontrados:\n");
                resvm = valorMinimo(l1, l2);
                printf("*L1: Minimo %d (Posicion %d)\n", resvm.valor, resvm.pos);
                printf("*L2: Minimo %d (Posicion %d)\n", resvm.valor_2, resvm.pos_2);
                break;

            default:
                printf("\nOpcion invalida.\n");
                break;
        }

        // --- 4. CONTROL DE REINICIO ---
        printf("\n------------------------------------------------\n");
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


void menuPunto6(){
    Lista lista1, lista2;
    int cantidad_elem1;
    int cantidad_elem2;
    int seguir = 1;
    bool resultado;
    
    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la lista 1\n-> ");
        cantidad_elem1 = ingresoDatosNumericosNoCero("Ingrese un numero valido!");
        printf("\nCargar lista 1: \n");
        lista1 = l_cargar(cantidad_elem1);
        
        printf("Ingrese la cantidad de elementos a cargar en la lista 2\n-> ");
        cantidad_elem2 = ingresoDatosNumericosNoCero("Ingrese un numero valido!");
        printf("\nCargar lista 2: \n");
        lista2 = l_cargar(cantidad_elem2);

        printf("\nLISTA 1 \n");
        l_mostrar(lista1);
        printf("\nLISTA 2 \n");
        l_mostrar(lista2);

        resultado = esSublista(lista1, lista2);

        if(resultado == true){
            printf("La lista 2 es sublista de la lista 1\n");
        }
        else{
            printf("La lista 2 NO es sublista de la lista 1\n");
        }
        printf("La complejidad algoritmica de la solucion es cuadratica");

        seguir = preguntarContinuar();
        system("cls");
    }
}
