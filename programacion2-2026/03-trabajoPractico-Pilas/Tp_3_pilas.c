#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_3_pilas.h"
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
    while (!p_es_vacia(paux))
    {
        elem = p_desapilar(paux);
        p_apilar(pauxres,elem);         //aca hago la lista para retornar en el mismo orden
    }
    return pauxres;
    //agregar al main = printf("La complejidad algoritmica de la funcion iterativa como de la recursiva es de orden lineal O(n) teniendo en cuenta las tads ya que el tiempo de ejecucion se ajustara en base al tamanio del programa")
}

//---------------------------------------------------DE FORMA RECURSIVA----------------------------------

void p_ej6_eliminarclaveRecursivoAux(Pila p, int clave){
    if (p_es_vacia(p))
    {
        return;
    }
    TipoElemento elem = p_desapilar(p);
    p_ej6_eliminarclaveRecursivoAux(p,clave);

    if (elem->clave != clave)
    {
        p_apilar(p,elem);
    }
    p_apilar(p,elem); //reconstruyo la lista;
}

Pila p_ej6_eliminarclaveRecursivo(Pila p, int clave){
    p_ej6_eliminarclaveRecursivoAux(p,clave);
    return p;
}
