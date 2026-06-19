#include "tp_arboles.h"
#include <stdio.h>
#include <time.h>

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


//  EJERCICIO 3
//  A
NodoArbol buscarpadre(NodoArbol nodo, int clavehijo){
    if(a_es_rama_nula(nodo)){
        return NULL;
    }
    NodoArbol nhi = n_hijoizquierdo(nodo);
    NodoArbol nhd = n_hijoderecho(nodo);

    if((!a_es_rama_nula(nhi) && n_recuperar(nhi)->clave == clavehijo)
    || (!a_es_rama_nula(nhd) && n_recuperar(nhd)->clave == clavehijo)){
        return nodo;
    } // si alguna de las claves de los hijo del nodo es la clavehijo, retorno el nodo

    NodoArbol padre = buscarpadre(nhi, clavehijo);                      // busco al padre por los hijos izquierdos,
    return a_es_rama_nula(padre) ? buscarpadre(nhd, clavehijo) : padre; // si padre == NULL, por los hijos derechos.
}                                                                       // y padre se encontró (!=NULL), lo retorno

int a_ej3_clavepadre(ArbolBinario A, int clavehijo){
    NodoArbol raiz = a_raiz(A);
    if(a_es_vacio(A)){
        return -1;
    }
    if(n_recuperar(raiz)->clave == clavehijo){
        return -1;
    }else{
        NodoArbol res = buscarpadre(raiz, clavehijo);
    // si res = NULL porque no encontró la clave retorna la clave hijo y sino la clave padre
        return a_es_rama_nula(res) ? clavehijo : n_recuperar(res)->clave;
    }
    
}

//  B
void buscarhijos(NodoArbol nodo, int clave, Lista l_hijos){
    if(a_es_rama_nula(nodo)){
        return;
    }

    if(n_recuperar(nodo)->clave == clave){

        if(!a_es_rama_nula(n_hijoizquierdo(nodo))){
            l_agregar(l_hijos, n_recuperar(n_hijoizquierdo(nodo)));
        }

        if(!a_es_rama_nula(n_hijoderecho(nodo))){
            l_agregar(l_hijos, n_recuperar(n_hijoderecho(nodo)));
        }
    }
    else{
        buscarhijos(n_hijoizquierdo(nodo), clave, l_hijos);
        buscarhijos(n_hijoderecho(nodo), clave, l_hijos);
    }
}


Lista a_ej3_hijos(ArbolBinario A, int clavepadre){
    Lista l_resultados = l_crear();
    NodoArbol raiz = a_raiz(A);
    buscarhijos(raiz, clavepadre, l_resultados);
    return l_resultados;
}

//  C   Listar el hermano (solo la clave)

void buscarhermano(NodoArbol nodo, int *hermano, int clave){

    if(a_es_rama_nula(nodo)){
        return;
    }

    NodoArbol hi = n_hijoizquierdo(nodo);
    NodoArbol hd = n_hijoderecho(nodo);

    if(!a_es_rama_nula(hi)){
        if(n_recuperar(hi)->clave == clave){
            if(!a_es_rama_nula(hd)){
                *hermano = n_recuperar(hd)->clave;
            }
        }
    }

    if(!a_es_rama_nula(hd)){
        if(n_recuperar(hd)->clave == clave){
            if(!a_es_rama_nula(hi)){
                *hermano = n_recuperar(hi)->clave;
            }
        }
    }

    buscarhermano(hi, hermano, clave);
    buscarhermano(hd, hermano, clave);
}



int a_ej3_hermano(ArbolBinario A, int clave){
    NodoArbol nodo = a_raiz(A);
    int hermano = -1;

    buscarhermano(nodo, &hermano, clave);
    return hermano;
}


//  D  
int calcularnivel(NodoArbol nodo, int clave, int nivel){
    if(a_es_rama_nula(nodo)){
        return -1;  //ojo aca
    }
    if(n_recuperar(nodo)->clave == clave){
        return nivel;
    }
    int resp = calcularnivel(n_hijoizquierdo(nodo), clave, (nivel+1)); // busco al padre por los hijos izquierdos,
    return (resp != -1) ? resp : calcularnivel(n_hijoderecho(nodo), clave, (nivel+1));
}
int a_ej3_nivel(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz(A);
    return calcularnivel(raiz, clave, 0);
}

//  E 

void nodoABuscar(NodoArbol nodo, int clave, NodoArbol *resultado){

    TipoElemento te;

    if(a_es_rama_nula(nodo)){
        return;
    }

    te = n_recuperar(nodo);

    if(te->clave == clave){
        *resultado = nodo;
        return; // corto la búsqueda
    }

    nodoABuscar(n_hijoizquierdo(nodo), clave, resultado);
    nodoABuscar(n_hijoderecho(nodo), clave, resultado);
}


void calcularRama(NodoArbol nodo, int *altura, int nivel){

    if(a_es_rama_nula(nodo)){
        return;
    }

    if(nivel > *altura){
        *altura = nivel;
    }

    calcularRama(n_hijoizquierdo(nodo), altura, nivel+1);
    calcularRama(n_hijoderecho(nodo), altura, nivel+1);
}



int a_ej3_alturarama(ArbolBinario A, int clave){

    int resultado = 0;
    NodoArbol nodoActual = NULL;

    nodoABuscar(a_raiz(A), clave, &nodoActual);

    if(nodoActual == NULL){
        return -1;
    }

    calcularRama(nodoActual, &resultado, 0);

    return resultado;
}

// F Listar todos los nodos que están en el mismo nivel (solo la clave).
void mismonivel(NodoArbol nodo, int nivel, int nivelactual, Lista l_resultado){

    if(a_es_rama_nula(nodo) || nivelactual > nivel){
        return;
    }

    if(nivel == nivelactual){
        l_agregar(l_resultado, n_recuperar(nodo));
        return;
    }

    mismonivel(n_hijoizquierdo(nodo),nivel,nivelactual + 1,l_resultado);
    mismonivel(n_hijoderecho(nodo),nivel,nivelactual + 1,l_resultado);
}

Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel){
    Lista l_resultados = l_crear();
    NodoArbol raiz = a_raiz(A);
    mismonivel(raiz, nivel, 0, l_resultados);
    return l_resultados;

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



// EJERCICIO 8
// A
void alturaN_ario(NodoArbol nodo, int *altura, int nivel){
    if(a_es_rama_nula(nodo)){
        return;
    }

    if(nivel > *altura){
        *altura = nivel;
    }

    alturaN_ario(n_hijoizquierdo(nodo),altura,nivel+1);
    alturaN_ario(n_hijoderecho(nodo),altura,nivel);
}


int a_ej8_altura(ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    if(a_es_rama_nula(raiz)){
        return -1;
    }
    int altura=0;
    alturaN_ario(raiz,&altura,0);
    return altura;
}



// B
int nivelN_ario(NodoArbol nodo, int clave, int nivel_actual){
    if(a_es_rama_nula(nodo)) return -1; // no se encontró
    
    if(n_recuperar(nodo)->clave == clave) return nivel_actual;
    
    int nivel = nivelN_ario(n_hijoizquierdo(nodo), clave, nivel_actual+1);
    if (nivel != -1) return nivel;
    return nivelN_ario(n_hijoderecho(nodo), clave, nivel_actual);
}


int a_ej8_nivel(ArbolBinario A, int clave){
    NodoArbol raiz = a_raiz(A);
    return nivelN_ario(raiz, clave, 0);
}


// C
void internosN_ario(NodoArbol nodo1, Lista l_res){
    if(a_es_rama_nula(nodo1)) return;

    if(!a_es_rama_nula(n_hijoizquierdo(nodo1))){
        TipoElemento te = te_crear(n_recuperar(nodo1)->clave);
        l_agregar(l_res, te);
    }
    internosN_ario(n_hijoizquierdo(nodo1), l_res);
    internosN_ario(n_hijoderecho(nodo1), l_res);
}


Lista a_ej8_internos(ArbolBinario A){
    Lista l_resultado = l_crear();
    NodoArbol raiz = a_raiz(A);

    if(a_es_rama_nula(raiz)){
        return l_resultado;
    }

    NodoArbol nhi = n_hijoizquierdo(raiz);
    internosN_ario(nhi, l_resultado);

    if(l_es_vacia(l_resultado)){
        printf("\nEl arbol no tiene nodos interiores...\n");
    }
    return l_resultado;
}


// D
bool mismo_nivelhojasN_ario(NodoArbol nodo,int nivel_actual,int *nivel_primera_hoja){

    if(a_es_rama_nula(nodo)){
        return true;
    }

    // hoja
    if(a_es_rama_nula(n_hijoizquierdo(nodo))){

        if(*nivel_primera_hoja == -1){
            *nivel_primera_hoja = nivel_actual;
        }
        else if(nivel_actual != *nivel_primera_hoja){
            return false;
        }

        return true;
    }

    if(!mismo_nivelhojasN_ario(n_hijoizquierdo(nodo),nivel_actual+1,nivel_primera_hoja)){
        return false;
    }
    if(!mismo_nivelhojasN_ario(n_hijoderecho(nodo),nivel_actual,nivel_primera_hoja)){
        return false;
    }
    return true;
}

bool a_ej8_hojasmismonivel(ArbolBinario A){
    NodoArbol raiz = a_raiz(A);
    int nivel_primera=-1;
    return mismo_nivelhojasN_ario(raiz,0,&nivel_primera);
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

int calcular_altura_nodo(NodoArbol nodo) {
    if (nodo == NULL) {
        return -1; 
    }
    int alt_izq = calcular_altura_nodo(n_hijoizquierdo(nodo));
    int alt_der = calcular_altura_nodo(n_hijoderecho(nodo));
    
    return (alt_izq > alt_der ? alt_izq : alt_der) + 1;
}

int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL) {
    int altura_abb = calcular_altura_nodo(abb_raiz(ABB));
    int altura_avl = calcular_altura_nodo(avl_raiz(AVL));
    return altura_abb - altura_avl;
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
