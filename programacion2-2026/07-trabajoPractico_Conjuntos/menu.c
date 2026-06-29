#include "menu.h"
#include "tp_conjunto.h"

// EJERCICIO 2
void menuPunto2(){
    int opcion;
    bool seguir = true;
    Conjunto A, B, C;

    printf("CARGA CONJUNTO A:\n");
    A = cto_modo_carga();

    printf("CARGA CONJUNTO B:\n");
    B = cto_modo_carga();

    while(seguir){
        printf("\n=== MENU DE PUNTO 2 ===\n");
        printf("1. Realizar la operacion de union\n");
        printf("2. Realizar la operacion de interseccion\n");
        printf("3. Realizar la operacion de diferencia\n");
        printf("4. Realizar la operacion de pertenencia\n");
        printf("0. Salir \n");
        printf("-1. Cargar nuevos conjuntos \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", -1, 4);
        system("cls");

        printf("\nCONJUNTO A:\n");
        cto_mostrar(A);
        printf("\nCONJUNTO B:\n");
        cto_mostrar(B);
        printf("\n\n");

        switch (opcion){
            case -1:
                free(A);
                free(B);
                printf("CARGA CONJUNTO A:\n");
                A = cto_modo_carga();

                printf("CARGA CONJUNTO B:\n");
                B = cto_modo_carga();
                break;
            case 0:
                printf("Seguro que desea salir? (1-Si / 0-No)\n");
                seguir = !preguntarContinuar();   
                break;
            case 1:
                C = c_ej2_union(A, B);
                printf("\nUNION DE LOS CONJUNTOS:\n");
                cto_mostrar(C);
                free(C);
                break;
            case 2:
                C = c_ej2_interseccion(A, B);
                if(cto_es_vacio(C)){
                    printf("\nLos conjuntos no presentaban intersecciones\n");
                }
                else{
                    printf("\nINTERSECCION DE LOS CONJUNTOS:\n");
                    cto_mostrar(C);
                }
                free(C);
                // printf("\n\n");
                break;
            case 3:
                printf("ACLARACION: tal como dijo Mario en el foro, este ejercicio no funciona con la implementacion de listas");
                printf("\ncon punteros o cursores, por lo que hay que usar las otras (AVL o Listas con arreglos)\n\n");
                C = c_ej2_diferencia(A, B);
                if(cto_es_vacio(C)){
                    printf("\nLos conjuntos no presentaban diferencias o el conjunto A estaba vacio\n");
                }
                else{
                    printf("\nDIFERENCIAS DE LOS CONJUNTOS:\n");
                    cto_mostrar(C);
                }
                free(C);
                // printf("\n\n");
                break;
            case 4:
                printf("ingrese la clave que desea averiguar si pertenece a los conjuntos\n");
                int clave = ingresoDatosNumericos("Clave invalida!");
                if(c_ej2_pertenencia(A,clave)){
                    printf("\nLa clave pertenece al conjunto A\n");
                }
                else{
                    printf("\nLa clave NO pertenece al conjunto A\n");
                }
                if(c_ej2_pertenencia(B,clave)){
                    printf("\nLa clave pertenece al conjunto B\n");
                }
                else{
                    printf("\nLa clave NO pertenece al conjunto B\n");
                }
                // printf("\n\n");
                break;
            default:
                printf("AVISO: Ingrese un numero parte de las opciones.\n");
                break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
}

// EJERCICIO 3
void menuPunto3(){
    int opcion;
    bool seguir = true;
    Lista lista_conjuntos;
    Conjunto cto_res;

    printf("CARGA DE LA LISTA DE CONJUNTOS:\n");
    lista_conjuntos = ej3cto_modo_carga();

    while(seguir){
        printf("\n=== MENU DE PUNTO 3 ===\n");
        printf("1. Realizar la operacion de union\n");
        printf("2. Realizar la operacion de interseccion\n");
        printf("0. Salir \n");
        printf("-1. Cargar nuevos conjuntos \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", -1, 2);
        system("cls");

        printf("LISTA DE CONJUNTOS:\n");
        if(l_es_vacia(lista_conjuntos)){
            printf("\nLa lista de conjuntos estaba vacia\n\n");
        }
        else{
            Iterador ite = iterador(lista_conjuntos);
            while(hay_siguiente(ite)){
                TipoElemento te = siguiente(ite);
                printf("Conjunto %d\n", te->clave);
                cto_mostrar((Conjunto)te->valor);
                printf("\n");
            }
        }

        switch (opcion){
            case -1:
                free(lista_conjuntos);
                printf("CARGA DE LA LISTA DE CONJUNTOS:\n");
                lista_conjuntos = ej3cto_modo_carga();
                break;
            case 0:
                printf("Seguro que desea salir? (1-Si / 0-No)\n");
                seguir = !preguntarContinuar();   
                break;
            case 1:
                cto_res = c_ej3_uniones(lista_conjuntos);
                if(cto_es_vacio(cto_res)){
                    printf("\nLa lista de conjuntos o estos mismos estaban vacios\n");
                }
                else{
                    printf("\n\nConjunto resultante de las uniones:\n");
                    cto_mostrar(cto_res);
                }
                free(cto_res);
                break;
            case 2:
                cto_res = c_ej3_intersecciones(lista_conjuntos);
                if(l_es_vacia(lista_conjuntos)){
                    printf("\nLa lista de conjuntos estaba vacia\n");
                }
                else if(cto_es_vacio(cto_res)){
                    printf("\nLos conjuntos estaban vacios o no existian claves en comun\n");
                }
                else{
                    printf("\n\nConjunto resultante de las intersecciones:\n");
                    cto_mostrar(cto_res);
                }
                free(cto_res);
                break;
            default:
                printf("AVISO: Ingrese un numero parte de las opciones.\n");
                break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
}

// EJERCICIO 4
void menuPunto4() {
    printf("CARGA CONJUNTO A:\n");
    Conjunto A = cto_modo_carga();

    printf("CARGA CONJUNTO B:\n");
    Conjunto B = cto_modo_carga();
    
    printf("CARGA CONJUNTO C:\n");
    Conjunto C = cto_modo_carga();

    printf("\nConjunto A\n");
    cto_mostrar(A);
    printf("\nConjunto B\n");
    cto_mostrar(B);
    printf("\nConjunto C\n");
    cto_mostrar(C);

    if(c_ej4_transitividad(A,B,C)){
        printf("\nPara estos conjuntos se cumple la propiedad de transitividad\n");
    }
    else{
        printf("\nPara estos conjuntos NO se cumple la propiedad de transitividad\n");
    }
    
    system("pause");
}

// EJERCICIO 5
void menuPunto5() {
    printf("CARGA CONJUNTO A:\n");
    Conjunto A = cto_modo_carga();

    printf("CARGA CONJUNTO B:\n");
    Conjunto B = cto_modo_carga();

    printf("\nConjunto A\n");
    cto_mostrar(A);
    printf("\nConjunto B\n");
    cto_mostrar(B);

    Conjunto cto_res = c_ej5_dif_simetrica(A, B);
    if(cto_es_vacio(cto_res)){
        printf("\nLos conjuntos estaban vacios o no presentaban diferencias simetricas\n");
    }
    else if(cto_es_vacio(A) || cto_es_vacio(B)){
        printf("\nUno de los conjuntos estaba vacio, por lo que el resultado es:\n");
        cto_mostrar(cto_res);
    }
    else{
        printf("\nConjunto resultante de la diferencia simetrica de ambos conjuntos:\n");
        cto_mostrar(cto_res);
    }
}

// EJERCICIO 6
void menuPunto6() {
    printf("CARGA CONJUNTO A:\n");
    Conjunto A = cto_modo_carga_ej6yej8();

    printf("CARGA CONJUNTO B:\n");
    Conjunto B = cto_modo_carga_ej6yej8();

    printf("\nConjunto A\n");
    cto_mostrar(A);
    printf("\nConjunto B\n");
    cto_mostrar(B);

    if(c_ej6_subconjuntopropio(A,B)){
        printf("\nEl conjunto A es subconjunto de B\n");
    }
    else{
         printf("\nEl conjunto A NO es subconjunto de B\n");
    }
    if(c_ej6_subconjuntopropio(B,A)){
        printf("\nEl conjunto B es subconjunto de A\n");
    }
    else{
         printf("\nEl conjunto B NO es subconjunto de A\n");
    }
    printf("\n\nDesea ver la complejidad de la resolucion? 1: SI | 0: NO\n\n");
    int opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 1);
    system("cls");

    if(opcion == 1){
        printf("\n\t\t\tCOMPLEJIDAD\n");
        printf("La complejidad algoritmica de la solucion del ejercicio va a depende de la implementación usada\n");
        printf("Si se utiliza la implementacion de Conjuntos con AVL, su complejidad sera O(n log n) Orden Lineal * Logaritmo n\n");
        printf("Si se utiliza la implementacion de Conjuntos con listas, su complejidad sera O(n^2) Orden Cuadratico\n");   
    }
    system("pause");
}

// EJERCICIO 7
void menuPunto7() {
    printf("CARGA CONJUNTO A:\n");
    Conjunto A = cto_modo_carga();

    printf("CARGA CONJUNTO B:\n");
    Conjunto B = cto_modo_carga();
    
    printf("CARGA CONJUNTO C:\n");
    Conjunto C = cto_modo_carga();

    printf("\nConjunto A\n");
    cto_mostrar(A);
    printf("\nConjunto B\n");
    cto_mostrar(B);
    printf("\nConjunto C\n");
    cto_mostrar(C);
    c_ej7_subconjtotalparcial(A, B, C);

    printf("\n\nDesea ver la complejidad de la resolucion? 1: SI | 0: NO\n\n");
    int opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 1);
    system("cls");

    if(opcion == 1){
        printf("\n=== COMPLEJIDAD ALGORITMICA CON ARBOL AVL ===\n");
        printf("Sabiendo que las comparaciones maximas necesarias para localizar cualquier elemento no exceden log(n), siendo n el numero de nodos total del arbol AVL.\n");
        printf("El codigo recorre todos los elementos de A (supongamos n elementos) y para cada uno verifica si esta en B (m elementos), es O(n log m).\n");
        printf("Esto se repite un total de 6 veces debido a la comparacion de un conjunto con los demas, pero la constante 6 no afecta la complejidad.\n");
        printf("Por lo que resulta ser: O(n log m)");

        printf("\n\n=== COMPLEJIDAD ALGORITMICA CON LISTAS ===\n");
        printf("El codigo recorre todos los elementos de A (supongamos n elementos) y para cada uno verifica si esta en B (m elementos), es O(n x m).\n");
        printf("Esto se repite un total de 6 veces debido a la comparacion de un conjunto con los demas, pero la constante 6 no afecta la complejidad.\n");
        printf("Por lo que resulta ser: O(n x m). Donde n y m son la cantidad de elementos de los conjuntos involucrados.");
        printf("\n\n");
    }
    system("pause");
}

// EJERCICIO 8

void menuPunto8() {
    printf("CARGA CONJUNTO A:\n");
    Conjunto A = cto_modo_carga_ej6yej8();

    printf("CARGA CONJUNTO B:\n");
    Conjunto B = cto_modo_carga_ej6yej8();

    printf("\nConjunto A\n");
    cto_mostrar(A);
    printf("\nConjunto B\n");
    cto_mostrar(B);

    if(c_ej8_soniguales(A,B)){
        printf("\nLos conjuntos si son iguales\n");
    }
    else{
        printf("\nLos conjuntos no son iguales...\n");
    }

    printf("\n\nDesea ver la complejidad de la resolucion? 1: SI | 0: NO\n\n");
    int opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 1);
    system("cls");

    if(opcion == 1){
        printf("\n\t\t\tCOMPLEJIDAD\n");
        printf("La complejidad de la solucion del ejercicio dependera de la implementacion de conjuntos que se utilice\n");
        printf("Si se usa la implementacion de Conjuntos con AVL, la complejidad sera O(n log(n)) Orden Lineal * Logaritmo\n");
        printf("Si se usa la implementacion de Conjuntos con listas, la complejidad sera O(n^2) Orden Cuadratico\n");
    }
    system("pause");
}