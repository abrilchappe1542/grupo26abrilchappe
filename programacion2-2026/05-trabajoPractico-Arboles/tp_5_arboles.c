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

// =====================================================================
//                           EJERCICIO 4 (N-arios en LCRS)
// Transformacion de Knuth: Primer hijo = Hijo Izquierdo,
// Siguientes hermanos = Hijos Derechos del primer hijo.
// =====================================================================

// Funcion auxiliar necesaria para el punto 'e' (buscar hermanos)
// Recorre el arbol binario buscando un nodo especifico por su clave.
NodoArbol buscarNodoAux(NodoArbol nodo, int clave) {
    if (nodo == NULL) return NULL;
    if (n_recuperar(nodo)->clave == clave) return nodo;
    
    NodoArbol izq = buscarNodoAux(n_hijoizquierdo(nodo), clave);
    if (izq != NULL) return izq;
    
    return buscarNodoAux(n_hijoderecho(nodo), clave);
}

// a. Dado un arbol n-ario, devolver en forma de lista el resultado del recorrido en anchura.
Lista a_ej4_anchura(ArbolBinario A) {
    Lista lres = l_crear();
    if (a_es_vacio(A)) return lres;

    Lista cola = l_crear();
    l_agregar(cola, te_crear_con_valor(0, a_raiz(A))); // Encolamos la raiz

    while (!l_es_vacia(cola)) {
        TipoElemento te_nodo = l_recuperar(cola, 1);
        NodoArbol nodo = (NodoArbol) te_nodo->valor;
        l_eliminar(cola, 1); // Desencolamos

        // Agregamos la clave del nodo actual a la lista de resultado
        l_agregar(lres, te_crear(n_recuperar(nodo)->clave));

        // En un arbol N-ario representado como LCRS, los hijos de un nodo son:
        // Su hijo izquierdo, y toda la cadena de hermanos derechos de este hijo izquierdo.
        NodoArbol hijo = n_hijoizquierdo(nodo);
        while (hijo != NULL) {
            l_agregar(cola, te_crear_con_valor(0, hijo)); // Encolamos cada hijo
            hijo = n_hijoderecho(hijo); // Pasamos al siguiente hermano
        }
    }
    l_destruir(cola);
    return lres;
}

// b. Funcion auxiliar recursiva para contar la cantidad de hojas en el arbol N-ario.
int a_ej4_q_hojas_aux(NodoArbol nodo) {
    if (nodo == NULL) return 0;
    
    // En LCRS, si un nodo no tiene hijo izquierdo, significa que no tiene hijos N-arios.
    // Por lo tanto, ES una hoja. Sumamos 1 y seguimos evaluando a sus hermanos (hijo derecho).
    if (n_hijoizquierdo(nodo) == NULL) {
        return 1 + a_ej4_q_hojas_aux(n_hijoderecho(nodo));
    }
    
    // Si tiene hijo izquierdo (tiene hijos N-arios), no es hoja. 
    // Sumamos las hojas de su descendencia y las hojas de sus hermanos.
    return a_ej4_q_hojas_aux(n_hijoizquierdo(nodo)) + a_ej4_q_hojas_aux(n_hijoderecho(nodo));
}

// b. Devuelve el numero (cantidad) de hojas de dicho arbol n-ario.
int a_ej4_q_hojas(ArbolBinario A) {
    return a_ej4_q_hojas_aux(a_raiz(A));
}

// c. Funcion auxiliar para determinar si dos arboles tienen la misma estructura.
bool a_ej4_similares_aux(NodoArbol n1, NodoArbol n2) {
    if (n1 == NULL && n2 == NULL) return true; // Ambos vacios en esta rama
    if (n1 == NULL || n2 == NULL) return false; // Uno vacio y el otro no
    
    // Comparamos recursivamente que ambos tengan/no tengan las mismas ramas izquierdas y derechas
    return a_ej4_similares_aux(n_hijoizquierdo(n1), n_hijoizquierdo(n2)) &&
           a_ej4_similares_aux(n_hijoderecho(n1), n_hijoderecho(n2));
}

// c. Determina si tienen la misma estructura, sin importar los datos.
bool a_ej4_similares(ArbolBinario A, ArbolBinario B) {
    return a_ej4_similares_aux(a_raiz(A), a_raiz(B));
}

// d. Funcion auxiliar para buscar el padre en un arbol N-ario (LCRS).
TipoElemento a_ej4_padre_aux(NodoArbol nodo, int clave) {
    if (nodo == NULL) return NULL;
    
    // Verificamos si alguno de los "hijos N-arios" directos de este nodo es el que buscamos.
    // Los hijos directos son el hijo izquierdo y toda su cadena de hijos derechos.
    NodoArbol hijo = n_hijoizquierdo(nodo);
    while (hijo != NULL) {
        if (n_recuperar(hijo)->clave == clave) return n_recuperar(nodo); // Encontramos al hijo, retornamos el padre
        hijo = n_hijoderecho(hijo);
    }
    
    // Si no es hijo directo de este nodo, buscamos recursivamente en su descendencia
    TipoElemento izq = a_ej4_padre_aux(n_hijoizquierdo(nodo), clave);
    if (izq != NULL) return izq;
    
    return a_ej4_padre_aux(n_hijoderecho(nodo), clave); // Buscamos en la rama de los hermanos
}

// d. Retorna el padre de un nodo del arbol (tipo_elemento).
TipoElemento a_ej4_padre(ArbolBinario A, int clave) {
    // La raiz no tiene padre, o si el arbol es vacio
    if (a_es_vacio(A) || n_recuperar(a_raiz(A))->clave == clave) return NULL;
    return a_ej4_padre_aux(a_raiz(A), clave);
}

// e. Retorna los hermanos de un nodo del arbol (lista de hermanos).
Lista a_ej4_hermanos(ArbolBinario A, int clave) {
    Lista lres = l_crear();
    if (a_es_vacio(A) || n_recuperar(a_raiz(A))->clave == clave) return lres; // La raiz no tiene hermanos

    // Paso 1: Buscamos quien es el padre del nodo buscado
    TipoElemento te_padre = a_ej4_padre(A, clave);
    if (te_padre == NULL) return lres;
    
    // Paso 2: Obtenemos el puntero real al nodo padre
    NodoArbol nodo_padre = buscarNodoAux(a_raiz(A), te_padre->clave);
    
    // Paso 3: Iteramos sobre todos los hijos del padre (que son el nodo buscado y sus hermanos)
    NodoArbol hijo = n_hijoizquierdo(nodo_padre);
    while (hijo != NULL) {
        // Si el hijo actual NO es el nodo que buscamos, entonces es un hermano. Lo agregamos.
        if (n_recuperar(hijo)->clave != clave) {
            l_agregar(lres, te_crear(n_recuperar(hijo)->clave));
        }
        hijo = n_hijoderecho(hijo);
    }
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
