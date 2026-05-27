#include "..\libs\colas\headers\colas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_colas.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


/**
    2.	Resolver los siguientes puntos:
 */

//  a.	Informar si un elemento dado se encuentra en la cola.
// Si la encuentra retorna true, caso contrario false
bool c_ej2_existeclave(Cola c, int clave){
    if (c_es_vacia(c))
    {
        return false;
    }
    Cola caux = c_crear();
    TipoElemento elem;
    bool res = false;
    while (!c_es_vacia(c))
    {
        elem = c_desencolar(c);
        c_encolar(caux,elem);
        if (elem->clave == clave)
        {
            res = true;
        }
        
    }
    while (!c_es_vacia(caux))
    {
        c_encolar(c,c_desencolar(caux));
    }
    return res;
}



//  b.	Agregar un nuevo elemento en una posición dada (colarse).
// Retorna la nueva cola con el elemento insertado, caso contrario la cola original recibida.
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){      
    Cola caux = c_crear();
    Cola cres = c_crear();
    TipoElemento elem;
    int pos = 1;
    if (c_es_llena(c))
    {
        printf("\nLa cola esta llena, se retorna la original\n");   //*cambio
        return c;
    }
    else
    {
        while (!c_es_vacia(c))
        {
            elem = c_desencolar(c);
            if (pos == (posicionordinal))
            {
                c_encolar(cres,X);
            }
            c_encolar(cres,elem);
            c_encolar(caux,elem);
            pos++;
        }

        if (pos+1 == posicionordinal+1)
        {
            c_encolar(cres,X);
        }
        

        while (!c_es_vacia(caux))
        {
            c_encolar(c,c_desencolar(caux));
        }
        return cres;
    }
}

//  c.	Dado un elemento sacarlo de la cola todas las veces que aparezca.
// Retorna la nueva cola sin el/los elemento/s, caso contrario la cola original recibida.
Cola c_ej2_sacarelemento(Cola c, int clave){
    if (c_es_vacia(c))
    {
        return c;
    }
    TipoElemento elem;
    Cola caux = c_crear();
    Cola cres = c_crear();
    while (!c_es_vacia(c))
    {
        elem = c_desencolar(c);
        if (elem->clave != clave)
        {
            c_encolar(cres,elem);
        }
        c_encolar(caux,elem);
    }

    while (!c_es_vacia(caux))
    {
        c_encolar(c,c_desencolar(caux));
    }
    return cres;
}

//  d.	Contar los elementos de la cola.
// Retorna la cantidad de elementos de la cola, o 0 (cero) si esta vacia.
int c_ej2_contarelementos(Cola c){
    int contador = 0;
    if (c_es_vacia(c))
    {
        return contador;
    }
    TipoElemento elem; 
    Cola caux = c_crear();
    while (!c_es_vacia(c))
    {
        elem = c_desencolar(c);
        c_encolar(caux,elem);
        contador++;
    }

    while (!c_es_vacia(caux))
    {
        c_encolar(c,c_desencolar(caux));
    }
    return contador;
}


//  e.	Realizar una función que realice una copia de una cola.
// Retorna la cola copia tal cual la original, no debe perserse la original.  Si es vacia retorna vacia.
Cola c_ej2_copiar(Cola c){
    Cola cres = c_crear();
    if (c_es_vacia(c))
    {
        return cres;
    }
    TipoElemento elem;
    Cola caux = c_crear();
    while (!c_es_vacia(c))
    {
        elem = c_desencolar(c);
        c_encolar(cres,elem);
        c_encolar(caux,elem);
    }
    
    while (!c_es_vacia(caux))
    {
        c_encolar(c,c_desencolar(caux));
    }

    return cres;
}

//  f.	Invertir el contenido de una cola sin destruir la cola original.
// Retorna la cola al reves (invertida), no debe perserse la original. Si es vacia retorna vacia.
Cola c_ej2_invertir(Cola c){
    Cola cres = c_crear();
    if (c_es_vacia(c))
    {
        return cres;
    }
    
    TipoElemento elem;
    Pila paux = p_crear();
    Cola caux = c_crear();
    while (!c_es_vacia(c))
    {
        elem = c_desencolar(c);
        c_encolar(caux,elem);
        p_apilar(paux,elem);
    }
    
    while (!p_es_vacia(paux))
    {
        c_encolar(cres,p_desapilar(paux));
    }

    while (!c_es_vacia(caux))
    {
        c_encolar(c,c_desencolar(caux));
    }
    return cres;
}
