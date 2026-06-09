#include "menu.h"

void menuPunto2(){
    int opcion, cant_nodo, clave;
    bool seguir = true, resultado;
    while (seguir == 1){
        printf("\n=== PUNTO 2 ===\n");

        printf("\nCargamos el arbol\n\n");
        ArbolBinario arbolito1 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 
        
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 
        
        printf("\nIngrese el punto que quiera ejecutar (1,2 o 3):");
        opcion = ingresoIntLimitado("Opcion invalida, ingrese entre 1 y 3", 1, 3);
        printf("\n");
        Lista lres1,lres2,lres3;
        switch (opcion) {        
            case 1:
                lres1 = a_ej2_hojas(arbolito1);
                if (l_es_vacia(lres1))
                {
                    printf("No hay nodos hojas, solo la raiz");
                }
                else
                {
                    printf("Los nodos terminales/hojas son:\n");
                    l_mostrar(lres1);
                }
                break;                
            case 2:
                lres2 = a_ej2_interiores(arbolito1);

                if (l_es_vacia(lres2))
                {
                    printf("No hay nodos internos, solo la raiz.\n");
                }
                else
                {
                    printf("Los nodos internos son:\n");
                    l_mostrar(lres2);
                }
                break;
            case 3:
                printf("Ingrese el valor que quiere buscar en el arbol:");
                clave = ingresoDatosNumericos("Ese valor no es valido, ingrese un numero.");
                lres3 = a_ej2_buscarclave(arbolito1,clave);



                if (l_es_vacia(lres3))
                {
                    printf("La clave no se encontraba en el arbol");
                }
                else
                {
                    Iterador ite = iterador(lres3);
                    int contador = 1;
                    while (hay_siguiente(ite)) {
                        TipoElemento elemLista = siguiente(ite);
                        NodoArbol nodoGuardado = (NodoArbol) elemLista->valor;
                        TipoElemento elemArbol = n_recuperar(nodoGuardado);
                        printf("Ocurrencia %d -> Clave: %d (Direccion del Nodo: %p)\n", contador, clave, (void*)nodoGuardado);
                        contador++;
                    }
                break;
                }
            }
        seguir = preguntarContinuar();
        system("cls");
    }
}

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
