#include "tp_conjunto.h"

// EJERCICIO 2

Conjunto c_ej2_union(Conjunto A, Conjunto B) {
    Conjunto C = cto_crear();
    C = cto_union(A,B);
    return C;
}

// b
Conjunto c_ej2_interseccion(Conjunto A, Conjunto B) {
    Conjunto C = cto_crear();
    C = cto_interseccion(A,B);
    return C;
}

// c
Conjunto c_ej2_diferencia(Conjunto A, Conjunto B) {
    Conjunto C = cto_crear();
    C = cto_diferencia(A,B);
    return C;
}

bool c_ej2_pertenencia(Conjunto A, int clave){
    return cto_pertenece(A,clave);
}

// EJERCICIO 3
Conjunto c_ej3_uniones(Lista l_de_conjuntos){
    Conjunto ctoUnion = cto_crear();
    if(l_es_vacia(l_de_conjuntos)){
        return ctoUnion;
    }
    Iterador itelist = iterador(l_de_conjuntos);

    while(hay_siguiente(itelist)){
        TipoElemento te_cto = siguiente(itelist);
        Conjunto ctoaux = (Conjunto)te_cto->valor;
        cto_aniadir(ctoaux, ctoUnion);
    }
    
    return ctoUnion;
}

Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){
    Conjunto ctoInterseccion;
    if(l_es_vacia(l_de_conjuntos)){
        return cto_crear();
    }

    Iterador itelist = iterador(l_de_conjuntos);
    Conjunto ctoaux = cto_union(cto_crear(), (Conjunto)siguiente(itelist)->valor);

    while(hay_siguiente(itelist)){
        ctoInterseccion = cto_interseccion(ctoaux, (Conjunto)siguiente(itelist)->valor);
        if(hay_siguiente(itelist)){
            free(ctoaux);
            ctoaux = ctoInterseccion;
        }
    }
    
    return ctoInterseccion;
}


// EJERCICIO 4

bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C) {
    int cant_cto_A = cto_cantidad_elementos(A);
    int cant_cto_B = cto_cantidad_elementos(B);
    int cant_cto_C = cto_cantidad_elementos(C);
    bool resultado;
    if(cant_cto_A > cant_cto_B){    //conjunto A tiene mas elementos que el conjunto B, por lo cual no es subconjunto
        printf("\nEl conjunto A contiene mas elementos que el conjunto B, por lo que el primero no puede ser un subconjunto del segundo...\n");
        system("pause");
        return false;
    }
    if(cant_cto_B > cant_cto_C){    //conjunto B tiene mas elementos que el conjunto C, por lo cual no es subconjunto
        printf("\nEl conjunto B contiene mas elementos que el conjunto C, por lo que el primero no puede ser un subconjunto del segundo...\n");
        system("pause");
        return false;
    }

    resultado = c_ej6_subconjuntopropio(A, B);
    if(resultado == true){
        printf("\nEl conjunto A es un subconjunto del conjunto B\n");
    }
    else{
        printf("\nEl conjunto A NO es un subconjunto del conjunto B\n");
        //system("pause");
        return resultado;
    }
    resultado = c_ej6_subconjuntopropio(B, C);
    if(resultado == true){
        printf("\nEl conjunto B es un subconjunto del conjunto C\n");
    }
    else{
        printf("\nEl conjunto B NO es un subconjunto del conjunto C\n");
        //system("pause");
        return resultado;
    }
    resultado = c_ej6_subconjuntopropio(A, C);
    return resultado;
}

// EJERCICIO 5
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){
    return cto_union(cto_diferencia(A, B), cto_diferencia(B, A));
}

// EJERCICIO 6

bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B) {
    int cant_cto_A = cto_cantidad_elementos(A);
    int cant_cto_B = cto_cantidad_elementos(B);
    bool comp_cto_A = false;
    Conjunto subconjunto1;

    if(cant_cto_A > cant_cto_B){
        printf("\nEl primer conjunto contiene mas elementos que el segundo conjunto, por lo que el primero no puede ser un subconjunto del segundo...\n");
    }
    else{
        //comparar
        subconjunto1 = cto_interseccion(A,B);
        if(cto_cantidad_elementos(subconjunto1) == cant_cto_A){
            comp_cto_A = true;
        }
    }

    return comp_cto_A;
}

// EJERCICIO 7

int cont_intersec(Conjunto A, Conjunto B){
    Conjunto ctoaux = cto_interseccion(A, B);
    return cto_cantidad_elementos(ctoaux);
}

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C){
    Conjunto conjuntos[] = {A, B, C};
    char nombres[] = {'A', 'B', 'C'};

    for(int i = 0; i < 3; i++){
        int cant_elementos = cto_cantidad_elementos(conjuntos[i]);

        for(int j = 0; j < 3; j++){
            if(i == j){
                continue; // salteo los conjuntos iguales
            }

            int contador_intersecciones = cont_intersec(conjuntos[i], conjuntos[j]);
            if(contador_intersecciones == cant_elementos){
                printf("\nEl conjunto %c es un subconjunto total del conjunto %c\n", nombres[i], nombres[j]);
            }
            else if(contador_intersecciones >= (cant_elementos + 1) / 2){
                printf("\nEl conjunto %c es un subconjunto parcial del conjunto %c\n", nombres[i], nombres[j]);
            }
        }
    }
}

// EJERCICIO 8

bool c_ej8_soniguales(Conjunto A, Conjunto B) {
    Conjunto cto1, cto2;
    bool resultado = true;
    
    if(cto_cantidad_elementos(A) != cto_cantidad_elementos(B)){
        printf("La cantidad de elementos de ambos conjuntos no coincide...\n");
        return false;
    }
    
    cto1 = cto_diferencia(A, B);
    cto2 = cto_diferencia(B, A);
    
    if(cto_cantidad_elementos(cto1) != 0 || cto_cantidad_elementos(cto2) != 0){
        resultado = false;
    }

    return resultado;
}
