#include "tp_arboles.h"


//EJERCICIO 2
//Punto A
void nodoHojasAux(NodoArbol nodo, Lista lres){
    if (nodo == NULL)
    {
        return;
    }
    
    else
    {
        if (n_hijoizquierdo(nodo) == NULL && n_hijoderecho(nodo) == NULL)
        {
            l_agregar(lres,n_recuperar(nodo));
        }
        nodoHojasAux(n_hijoizquierdo(nodo),lres);
        nodoHojasAux(n_hijoderecho(nodo),lres);
    }   
}

Lista a_ej2_hojas(ArbolBinario a){
    Lista lres = l_crear();
    if (!a_es_vacio(a))
    {
        NodoArbol nodo = a_raiz(a);
        nodoHojasAux(nodo,lres);
    }
    return lres;
}

//!-------------------------------------------------------------------------------------------------------------------------------------
//                                                       PUNTO B
//!-------------------------------------------------------------------------------------------------------------------------------------



void NodosInternosAux(NodoArbol nodo, Lista lres){
    if (nodo == NULL)
    {
        return;
    }
    else
    {
        if (n_hijoizquierdo(nodo) != NULL || n_hijoderecho(nodo) != NULL)
        {
            l_agregar(lres,n_recuperar(nodo));
        }

        NodosInternosAux(n_hijoizquierdo(nodo),lres);
        NodosInternosAux(n_hijoderecho(nodo),lres);
    }
}

Lista a_ej2_interiores(ArbolBinario a){
    Lista lres = l_crear();
    if (!a_es_vacio(a))
    {
        NodoArbol raiz = a_raiz(a);
        NodosInternosAux(n_hijoizquierdo(raiz),lres);
        NodosInternosAux(n_hijoderecho(raiz),lres);
    }
    return lres;   
}

//!-------------------------------------------------------------------------------------------------------------------------------------
//                                                       PUNTO C
//!-------------------------------------------------------------------------------------------------------------------------------------

void punto2CAux(NodoArbol nodo, Lista lres, int clave){
    if (nodo == NULL)
    {
        return;
    }
    else
    {
        if (n_recuperar(nodo)->clave == clave)
        {
            l_agregar(lres, te_crear_con_valor(0,nodo));
        }
        punto2CAux(n_hijoizquierdo(nodo),lres,clave);
        punto2CAux(n_hijoderecho(nodo),lres,clave);
    }
    
}

Lista a_ej2_buscarclave(ArbolBinario A, int clave){
    Lista lres = l_crear();
    if (a_es_vacio(A))
    {
        return lres;
    }
    NodoArbol nodo = a_raiz(A);
    punto2CAux(nodo,lres,clave);
    return lres;
}



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
