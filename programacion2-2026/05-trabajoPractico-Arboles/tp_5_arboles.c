#include "tp_arboles.h"
#include <stdio.h>
#include <time.h>

// EJERCICIO 7
bool determinarEquivalencia(NodoArbol nodo1, NodoArbol nodo2){

    TipoElemento te1= n_recuperar(nodo1), te2= n_recuperar(nodo2);

    if(te1->clave == te2->clave){
        if(n_hijoizquierdo(nodo1) != NULL && n_hijoizquierdo(nodo2) != NULL){
            //tienen un hijo izquierdo para seguir comparando y son iguales en la clave
            determinarEquivalencia(n_hijoizquierdo(nodo1), n_hijoizquierdo(nodo2));
        }
        else if(n_hijoizquierdo(nodo1) == NULL && n_hijoizquierdo(nodo2) == NULL);
        else{
            return false;   //NO COMPARTEN ESTRUCTURA
        }        
        if(n_hijoderecho(nodo1) != NULL && n_hijoderecho(nodo2) != NULL){
            determinarEquivalencia(n_hijoderecho(nodo1), n_hijoderecho(nodo2));
        }
        else if(n_hijoderecho(nodo1) == NULL && n_hijoderecho(nodo2) == NULL);
        else{
            return false;
        }
    }
    else{
        return false;
    }
    return true;
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){

    if(a_es_vacio(A) || a_es_vacio(B)){
        return (a_es_vacio(A) && a_es_vacio(B));
    }

    NodoArbol raiz1 = a_raiz(A), raiz2 = a_raiz(B);
    bool equivalencia;
    equivalencia = determinarEquivalencia(raiz1, raiz2);

    return equivalencia;
}

//EJERCICIO 9
Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo) {
    Lista l = l_crear(); 
    int generados = 0;

    while (generados < cantidadclavesagenerar) {
        int numero_azar = (rand() % (valormaximo - valorminimo + 1)) + valorminimo;
        if (l_buscar(l, numero_azar) == NULL) { 
            TipoElemento te = te_crear(numero_azar); 
            l_agregar(l, te); 
            generados++;
        }
    }
    return l;
}

ArbolBinarioBusqueda a_ej10_crearABB(Lista L) {
    ArbolBinarioBusqueda abb = abb_crear();
    Iterador iter = iterador(L);

    while (hay_siguiente(iter)) {
        TipoElemento te = siguiente(iter);
        abb_insertar(abb, te);
    }
    return abb;
}

ArbolAVL a_ej10_crearAVL(Lista L) {
    ArbolAVL avl = avl_crear();
    Iterador iter = iterador(L);

    while (hay_siguiente(iter)) {
        TipoElemento te = siguiente(iter);
        avl_insertar(avl, te);
    }
    return avl;
}

Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar) {
    Lista resultados_diferencias = l_crear();

    for (int i = 0; i < N_repeticiones; i++) {
        Lista claves = a_ej10_generarlistaclaves(cantidaclavesagenerar, valorminimo, valormaximo);

        ArbolBinarioBusqueda abb = a_ej10_crearABB(claves);
        ArbolAVL avl = a_ej10_crearAVL(claves);

        int diferencia = a_ej10_difalturas(abb, avl);

        TipoElemento te_dif = te_crear(diferencia);
        l_agregar(resultados_diferencias, te_dif);
    }
    return resultados_diferencias;
}
