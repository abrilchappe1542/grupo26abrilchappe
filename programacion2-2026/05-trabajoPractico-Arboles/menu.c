#include "menu.h"

// EJERCICIO 7
void menuPunto7(){
    int opcion, cant_nodo;
    bool seguir = true, resultado;
    while (seguir == 1){
        printf("\n=== PUNTO 7 ===\n");

        printf("\nCargamos primer arbol\n\n");
        ArbolBinario arbolito1 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 

        printf("\nCargamos segundo arbol\n\n");
        ArbolBinario arbolito2 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 2 ||\n\n");
        a_mostrar_normal(arbolito2);
        if(a_es_vacio(arbolito2)) printf("\n\n"); 
        
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 
        printf("\n\n\n|| GRAFICO DEL ARBOL 2 ||\n\n");
        a_mostrar_normal(arbolito2);
        if(a_es_vacio(arbolito2)) printf("\n\n"); 

        resultado = a_ej7_equivalente(arbolito1, arbolito2);
        if(resultado == true){
            if(a_es_vacio(arbolito1) && a_es_vacio(arbolito2)){
                printf("\n\nLos dos arboles estaban vacios\n");
            }
            printf("\n=== LOS ARBOLES SON EQUIVALENTES ===\n");
        }
        else{
            printf("\n=== LOS ARBOLES NO SON EQUIVALENTES ===\n");
        }
        seguir = preguntarContinuar();
        system("cls");
    }
}
