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

//PUNTO 3
bool c_ej3_iguales(Cola c1, Cola c2){
    Cola aux = c_crear();
    TipoElemento nodo1, nodo2, nodo_aux;
    bool esIgual = true;
    while(!c_es_vacia(c1) && !c_es_vacia(c2) && esIgual == true){
        nodo1 = c_desencolar(c1);
        nodo2 = c_desencolar(c2);
        if(nodo1->clave != nodo2->clave){
            esIgual = false;
        }
        c_encolar(aux, nodo2);
        c_encolar(aux, nodo1);
    }
    while(!c_es_vacia(aux)){
        nodo_aux = c_desencolar(aux);
        c_encolar(c1, nodo_aux);
        nodo_aux = c_desencolar(aux);
        c_encolar(c2, nodo_aux);
    }
    return esIgual;
}

//punto 4:
Cola  c_ej4_colanorepetidos(Cola c){
    TipoElemento elemento1, elemento2;
    Cola c_aux = c_crear();
    Cola c_resultado = c_crear();
    Cola c_copia = c_ej2_copiar(c);
    bool seguir = true, repite = false;

    if(c_es_vacia(c)){
        return c_resultado;
    }
    while(seguir == true){  
        elemento1 = c_desencolar(c_copia);
        while(c_es_vacia(c_copia) == false){
            elemento2 = c_desencolar(c_copia);
            
            if(elemento1->clave != elemento2->clave){   //si son distintos los agrega a la cola auxiliar
                c_encolar(c_aux,elemento2);
            }
            else{
                repite = true;
            }
        }
        if(repite != true){ //si el elemento a comparar no se repite, lo agrega a la cola de resultado
            c_encolar(c_resultado,elemento1);   
        }
        else{
            repite = false;
        }
        
        if(c_es_vacia(c_aux)){  //si no se agrega ningun elemento, es porque todos los elementos fueron distintos y sale del while
            seguir = false; 
        }
        else{
            c_copia = c_ej2_copiar(c_aux);
            c_aux = c_crear(); // cola auxiliar vuelve a 0
        }
    }
    return c_resultado;
}

/*
PUNTO 6.	
    Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
    y en qué posición ordinal se encontró cada uno en su estructura.  
	Si existe mas de una vez la primer posicion encontrada, se retornará cada ocurrencia.
	No se deben destruir las estructuras originales.
	Ejemplo: si “P” = (2,5,8,19,3,4,5) y “C” = (4, 18, 12, 5, 4, 6) 
	la lista tendría L = (5:2:4, 4:6:1, 4:6:5, 5:7:4, ).
    retornar una lista con los valores comunes segun las especificaciones del ejercicio.
    Si no existen valores comunes retornar la lista vacia.   
*/

Lista c_ej6_comunesapilaycola(Pila p, Cola c){
    Pila p_aux = p_crear();
    Pila p_clon = p_crear();

    Cola c_aux = c_crear();
    Cola c_clon = c_crear();
    while(!p_es_vacia(p)){
        TipoElemento elem = p_desapilar(p);  
        p_apilar(p_aux, elem);
    }
    while(!p_es_vacia(p_aux)){
        TipoElemento elem = p_desapilar(p_aux);  
        p_apilar(p, elem);
        TipoElemento clon = te_crear(elem->clave); 
        p_apilar(p_clon, clon);
    }

    while(!c_es_vacia(c)){
        TipoElemento elem = c_desencolar(c);
        c_encolar(c_aux, elem);
    }
    while(!c_es_vacia(c_aux)){
        TipoElemento elem = c_desencolar(c_aux);  
        c_encolar(c, elem);
        TipoElemento clon = te_crear(elem->clave);  
        c_encolar(c_clon, clon);
    }
    
    int pos_pila = 0;
    int pos_cola = 0;
    Lista resultado = l_crear();
    
    while(!p_es_vacia(p_clon)){
        TipoElemento elem = p_desapilar(p_clon);
        pos_pila++;
        while(!c_es_vacia(c_clon)){
            TipoElemento elem_c = c_desencolar(c_clon);
            pos_cola++;
            if(elem->clave == elem_c->clave){
                char* formato = malloc(50);
                sprintf(formato, "%d:%d:%d", elem->clave, pos_pila, pos_cola);
                TipoElemento match = te_crear(elem->clave);
                match->valor = formato;

                l_agregar(resultado, match);
            }
            c_encolar(c_aux, elem_c);
        }
        pos_cola = 0;
        
        while(!c_es_vacia(c_aux)){
            TipoElemento elem_retorno = c_desencolar(c_aux);
            c_encolar(c_clon, elem_retorno);
        }
    }

    return resultado;
}

