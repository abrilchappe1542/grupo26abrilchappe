#include "tp_2_listas.h"

//ejercicio 3:
ResultadosMul multiplo(Lista l1, Lista l2){
    TipoElemento nodo1 = l_recuperar(l1,1), nodo2 = l_recuperar(l2,1);
    int x=nodo2->clave/nodo1->clave;
    ResultadosMul multiplo_resultado = { .esMultiplo = true, .escalar = true, .numEscalar = x };
    Iterador ite =iterador(l1), ite2 =iterador(l2);
    while(hay_siguiente(ite)){
        nodo1=siguiente(ite);
        nodo2=siguiente(ite2);
        if ((nodo2->clave%nodo1->clave) != 0){
            multiplo_resultado.esMultiplo = false, multiplo_resultado.escalar = false, multiplo_resultado.numEscalar = 0;
            return multiplo_resultado;
        }
        if (nodo2->clave/nodo1->clave != x){
            multiplo_resultado.escalar = false;
        }
    }
    return multiplo_resultado;
}
