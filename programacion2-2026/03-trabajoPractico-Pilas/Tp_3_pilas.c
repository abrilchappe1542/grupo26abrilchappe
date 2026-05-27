#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_pilas.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


//punto 2
//pnt. A
bool p_ej2_existeclave(Pila p, int clave){
    Pila p_aux = p_crear();
    bool existe_clave = false;
    while(!p_es_vacia(p) && !existe_clave){  //corta si se vacia la pila o si se encuentra la clave, para no recorrer de mas
        TipoElemento elem = p_desapilar(p);
        if (elem->clave == clave){
            existe_clave = true;
        }
        p_apilar(p_aux, elem);
    }
    while(!p_es_vacia(p_aux)){
        TipoElemento elem1 = p_desapilar(p_aux);
        p_apilar(p, elem1);
    }

    return existe_clave;
}
//pnt. B
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    Pila p_aux = p_crear();
    Pila p_res = p_crear();
    while(!p_es_vacia(p)){
        TipoElemento elem = p_desapilar(p);
        p_apilar(p_aux, elem);
    }

    while(!p_es_vacia(p_aux)){
        TipoElemento elem1 = p_desapilar(p_aux);
        p_apilar(p, elem1);
        TipoElemento clon = te_crear(elem1->clave); 
        p_apilar(p_res, clon); 
    }

    Pila p_aux_insercion = p_crear();
    int pos_actual = 0;
    
    while(!p_es_vacia(p_res) && pos_actual < posicionordinal){
        TipoElemento elem_res = p_desapilar(p_res);
        p_apilar(p_aux_insercion, elem_res);
        pos_actual++;
    }
    
    if(pos_actual == posicionordinal){
        p_apilar(p_res, x); 
    }

    while(!p_es_vacia(p_aux_insercion)){
        TipoElemento elem_res = p_desapilar(p_aux_insercion);
        p_apilar(p_res, elem_res);
    }

    return p_res;
}

// pnt. C
Pila p_ej2_eliminarclave(Pila p, int clave){
    Pila p_aux = p_crear();
    Pila p_res = p_crear();
    bool primera_ocurrencia = false;

    while(!p_es_vacia(p)){
        TipoElemento elem = p_desapilar(p);
        p_apilar(p_aux, elem);
    }

    while(!p_es_vacia(p_aux)){
        TipoElemento elem1 = p_desapilar(p_aux);
        p_apilar(p, elem1);

        if(elem1->clave == clave && !primera_ocurrencia) {
            primera_ocurrencia = true; 
        } else {
            TipoElemento clon = te_crear(elem1->clave);
            p_apilar(p_res, clon);
        }
    }

    if((p_es_vacia(p_aux)) && (primera_ocurrencia == false)){
        printf("\nNo se encontro la Clave a eliminar!\n\n");
    }
    
    return p_res;
}

//pnt. D

Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    Pila p_aux = p_crear();
    Pila p_res = p_crear();
    while(!p_es_vacia(p)){
        TipoElemento elem = p_desapilar(p);
        p_apilar(p_aux, elem);
    }

    while(!p_es_vacia(p_aux)){
        TipoElemento elem1 = p_desapilar(p_aux);
        p_apilar(p, elem1); 
        TipoElemento clon = te_crear(elem1->clave); 
        p_apilar(p_res, clon); 
    }
    Pila p_aux_int = p_crear(); 
    int pos_actual = 0;
    TipoElemento e1 = NULL;
    TipoElemento e2 = NULL;
    while(!p_es_vacia(p_res)){
        TipoElemento elem = p_desapilar(p_res);
        if(pos_actual == pos1){
            e1 = elem;
        }
        if (pos_actual == pos2){
            e2 = elem;
        }
        p_apilar(p_aux_int, elem);  
        pos_actual++;
    }
    while(!p_es_vacia(p_aux_int)){
        TipoElemento elem = p_desapilar(p_aux_int);
        if(e1 != NULL && e2 != NULL){
            if(elem == e1){
                p_apilar(p_res, e2);
            }else if(elem == e2){
                p_apilar(p_res, e1);
            }else{
                p_apilar(p_res, elem);
            }
        }
    }
    return p_res;
}

//pnt. E
Pila p_ej2_duplicar(Pila p){
    Pila p_aux = p_crear();
    
    while(!p_es_vacia(p)){
        TipoElemento elem = p_desapilar(p);
        p_apilar(p_aux, elem);
    }
    while(!p_es_vacia(p_aux)){
        TipoElemento elem1 = p_desapilar(p_aux);
        p_apilar(p, elem1);
        TipoElemento clon = te_crear(elem1->clave); //creo otro tipo elemento con el mismo, para apilarlo duplicado
        p_apilar(p, clon);
    }
    return p;
}

// pnt. F
int p_ej2_cantidadelementos(Pila p){
    Pila p_aux = p_crear();
    int contador = 0;
    while(!p_es_vacia(p)){
        TipoElemento elem = p_desapilar(p);
        contador++;
        p_apilar(p_aux, elem);
    }
    while(!p_es_vacia(p_aux)){
        TipoElemento elem1 = p_desapilar(p_aux);
        p_apilar(p, elem1);
    }
    return contador;
}

//PUNTO 3
bool p_ej3_iguales(Pila p1, Pila p2){
    Pila p_aux = p_crear();
    TipoElemento nodo, nodo2;
    bool es_igual = true;
    while((!p_es_vacia(p1)) && (!p_es_vacia(p2)) && (es_igual == true)){
        nodo = p_desapilar(p1);
        nodo2 = p_desapilar(p2);
        if(nodo->clave != nodo2->clave){
            es_igual = false;
        }
        p_apilar(p_aux, nodo2);
        p_apilar(p_aux, nodo);
    }
    while(!p_es_vacia(p_aux)){
        nodo = p_desapilar(p_aux);
        p_apilar(p1, nodo);
        nodo2 = p_desapilar(p_aux);
        p_apilar(p2, nodo2);
    }
    return es_igual;
}

//Punto 4
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){
    if (nrootrabase < 2 || nrootrabase > 16){return NULL;};
    Pila R = p_crear();
    int a;
    if (nrobasedecimal <0){
        a = (nrobasedecimal * -1);
    }
    else { a = nrobasedecimal;};
    while (a >= nrootrabase){
        int b = 0;
        if (a%nrootrabase < 10){
            b = a%nrootrabase + 48;} 
        else {
            b = a%nrootrabase + 55;
        }
        p_apilar(R, te_crear(b));
        a = a/nrootrabase;
    }
    if (a < 10){
        a = a + 48;} 
    else {
        a = a + 55;
    }
    p_apilar(R, te_crear(a));
    char* texto = (char*)malloc(sizeof(char)*100);
    int i = 0;
    if (nrobasedecimal < 0){
        texto[i] = '-';
        i++;
    }
    while (!p_es_vacia(R)){
        TipoElemento elem = p_desapilar(R);
        texto[i] = elem->clave;
        i++;
    }
    texto[i] = '\0';
    return texto;
}

//punto 5
Pila p_ej5_invertir(Pila p) {
    Pila p_res = p_crear();
    Pila p_aux = p_crear();
    TipoElemento elem;

    while (!p_es_vacia(p)) {
        elem = p_desapilar(p);
        p_apilar(p_res, elem);
        p_apilar(p_aux, elem);
    }

    while (!p_es_vacia(p_aux)) {
        p_apilar(p, p_desapilar(p_aux));
    }

    return p_res;
}

//punto 6 iterativo
Pila p_ej6_eliminarclave(Pila p, int clave){
    Pila paux = p_crear();
    Pila pauxres = p_crear();
    Pila paux2 = p_crear();
    TipoElemento elem;
    while (!p_es_vacia(p)) {
        elem = p_desapilar(p);
        if (elem->clave != clave) {
            p_apilar(paux, elem);
        }
        p_apilar(paux2, elem);
    }
    while (!p_es_vacia(paux2)) {
        elem = p_desapilar(paux2);
        p_apilar(p, elem);
    }
    while (!p_es_vacia(paux)) {
        elem = p_desapilar(paux);
        p_apilar(pauxres, elem);
    }
    return pauxres;
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

Pila p_ej6_eliminarclaverecursiva(Pila p, int clave){
    Pila pres = p_crear();
    p_ej6_eliminarclaveRecursivoAux(p,clave,pres);
    return pres;
}


bool existe_en_pila(Pila p, int clave){
    Pila aux = p_crear();
    TipoElemento nodo;
    bool existe = false;

    while(!p_es_vacia(p)){
        nodo = p_desapilar(p);

        if(nodo->clave == clave){
            existe = true;
        }

        p_apilar(aux, nodo);
    }

    p_intercambio(aux, p);

    return existe;
}

// 7.
Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    TipoElemento nodo1, nodo2;
    Pila aux1 = p_crear();
    Pila aux2 = p_crear();
    Pila en_comun = p_crear();
    bool encontrado = false;
    while(!p_es_vacia(p1)){
        nodo1 = p_desapilar(p1);
        while(!p_es_vacia(p2)){
            nodo2 = p_desapilar(p2);
            if(nodo1->clave == nodo2->clave && !encontrado){
                if(!existe_en_pila(en_comun, nodo1->clave)){
                    p_apilar(en_comun, te_crear(nodo1->clave));
                }
                encontrado = true;
            }
            p_apilar(aux2, nodo2);
        }
        p_intercambio(aux2, p2);
        p_apilar(aux1, nodo1);
        encontrado = false;
    }
    p_intercambio(aux1, p1);
    return en_comun;
}



//8
Pila p_ej8_sacarrepetidos(Pila p) {
    Pila paux = p_crear();       
    Pila pres = p_crear();       
    Pila pres_aux = p_crear();   
    TipoElemento elem, elem_res;
    bool encontrado;

    while (!p_es_vacia(p)) {
        elem = p_desapilar(p);
        p_apilar(paux, elem); 

        encontrado = false;
        
        while (!p_es_vacia(pres)) {     //busco si en pres la clave ya existia
            elem_res = p_desapilar(pres);
            
            if (elem_res->clave == elem->clave) {   //ya existia en pres
                int* cantidad_actual = (int*)elem_res->valor;; // Asigna memoria para el contador
                (*cantidad_actual)++;
                p_apilar(pres_aux, te_crear_con_valor(elem->clave, elem_res->valor));                
                encontrado = true;
                break; //corto la ejecucion porque aca no tengo que bsucar mas si hay repetidos
            } 
            else {
                p_apilar(pres_aux, elem_res);       //en caso de que no sea igual, lo guardo en la aux
            }
        }
    
        // el numero no estaba repetido, lo guardo por primera vez
        if (!encontrado) {
            int* nueva_cant = (int*) malloc(sizeof(int));
            *nueva_cant = 1;
            p_apilar(pres_aux, te_crear_con_valor(elem->clave, nueva_cant));
        }

        while (!p_es_vacia(pres_aux)) {
            p_apilar(pres, p_desapilar(pres_aux));
        }
    }

    while (!p_es_vacia(paux)) {
        p_apilar(p, p_desapilar(paux));
    }

    return pres;
}
