#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_pilas.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



//punto 6
Pila p_ej6_eliminarclave(Pila p, int clave){
    Pila paux = p_crear();
    Pila pauxres = p_crear();
    Pila paux2 = p_crear();
    TipoElemento elem;
    while (!p_es_vacia(p))
    {   
        elem = p_desapilar(p);
        if (elem->clave != clave)
        {
            p_apilar(paux,elem);
        }
        p_apilar(paux2,elem);       //esto es para no perder la original
    }
    
    while (!p_es_vacia(paux2))
    {
        elem = p_desapilar(paux2);
        p_apilar(p,elem);
    }
    return paux;
}

//---------------------------------------------------DE FORMA RECURSIVA----------------------------------

void p_ej6_eliminarclaveRecursivoAux(Pila p, int clave,Pila pres){
    if (p_es_vacia(p))
    {
        return;
    }
    TipoElemento elem = p_desapilar(p);
    p_ej6_eliminarclaveRecursivoAux(p,clave,pres);

    p_apilar(p,elem);
    if (elem->clave != clave)
    {
        p_apilar(pres,elem); //reconstruyo la lista;
    }
}

Pila p_ej6_eliminarclaveRecursivo(Pila p, int clave){
    Pila pres = p_crear();
    p_ej6_eliminarclaveRecursivoAux(p,clave,pres);
    return pres;
}



// 7.
Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    TipoElemento nodo1, nodo2, nodoaux2;
    Pila aux1=p_crear(), aux2=p_crear(), en_comun=p_crear();
    bool encontrado=false;
    while(!p_es_vacia(p1)){
        nodo1=p_desapilar(p1);
        while(!p_es_vacia(p2)){
            nodo2=p_desapilar(p2);
            if (nodo1->clave==nodo2->clave && !encontrado){
                nodoaux2 = te_crear(nodo2->clave);
                encontrado = p_apilar(en_comun, nodoaux2);
            }
            p_apilar(aux2, nodo2);
        }
        p_intercambio(aux2, p2);
        p_apilar(aux1, nodo1);
        encontrado=false;
    }
    p_intercambio(aux1,p1);
    return en_comun;//complejidad cuadratica
}
