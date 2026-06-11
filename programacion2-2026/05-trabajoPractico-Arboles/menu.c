#include "menu.h"

void menuPunto2(){
    int opcion, cant_nodo, clave;
    bool seguir = true, resultado;
    while (seguir == 1){
        printf("\n=== PUNTO 2 ===\n");

        printf("\nCargamos el arbol\n\n");
        ArbolBinario arbolito1 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 
        
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 
        
        printf("\nIngrese el punto que quiera ejecutar (1,2 o 3):");
        opcion = ingresoIntLimitado("Opcion invalida, ingrese entre 1 y 3", 1, 3);
        printf("\n");
        Lista lres1,lres2,lres3;
        switch (opcion) {        
            case 1:
                lres1 = a_ej2_hojas(arbolito1);
                if (l_es_vacia(lres1))
                {
                    printf("No hay nodos hojas, solo la raiz");
                }
                else
                {
                    printf("Los nodos terminales/hojas son:\n");
                    l_mostrar(lres1);
                }
                break;                
            case 2:
                lres2 = a_ej2_interiores(arbolito1);

                if (l_es_vacia(lres2))
                {
                    printf("No hay nodos internos, solo la raiz.\n");
                }
                else
                {
                    printf("Los nodos internos son:\n");
                    l_mostrar(lres2);
                }
                break;
            case 3:
                printf("Ingrese el valor que quiere buscar en el arbol:");
                clave = ingresoDatosNumericos("Ese valor no es valido, ingrese un numero.");
                lres3 = a_ej2_buscarclave(arbolito1,clave);



                if (l_es_vacia(lres3))
                {
                    printf("La clave no se encontraba en el arbol");
                }
                else
                {
                    Iterador ite = iterador(lres3);
                    int contador = 1;
                    while (hay_siguiente(ite)) {
                        TipoElemento elemLista = siguiente(ite);
                        NodoArbol nodoGuardado = (NodoArbol) elemLista->valor;
                        TipoElemento elemArbol = n_recuperar(nodoGuardado);
                        printf("Ocurrencia %d -> Clave: %d (Direccion del Nodo: %p)\n", contador, clave, (void*)nodoGuardado);
                        contador++;
                    }
                break;
                }
            }
        seguir = preguntarContinuar();
        system("cls");
    }
}

//PUNTO 4
void menuPunto4() {
    bool seguir = true;
    while (seguir) {
        printf("\n=== PUNTO 4 (N-arios) ===\n");
        printf("\n--- Cargando el Arbol Principal ---\n");
        ArbolBinario arbol = a_modo_carga();
        system("cls");
        
        printf("\na. Recorrido en Anchura:\n");
        Lista anchura = a_ej4_anchura(arbol);
        l_mostrar(anchura);
        
        printf("\nb. Cantidad de hojas N-arias: %d\n", a_ej4_q_hojas(arbol));
        
        printf("\nIngrese una clave para ver su padre y hermanos: ");
        int clave = ingresoDatosNumericos("Invalido.\n");
        TipoElemento padre = a_ej4_padre(arbol, clave);
        if (padre) printf("d. Padre: %d\n", padre->clave); else printf("d. No tiene padre.\n");
        
        Lista hermanos = a_ej4_hermanos(arbol, clave);
        printf("e. Hermanos: ");
        if (!l_es_vacia(hermanos)) l_mostrar(hermanos); else printf("Ninguno\n");

        printf("\n------------------------------------------------\n");
        printf("c. Comprobacion de Arboles Similares\n");
        printf("Vamos a cargar un segundo arbol para comparar su estructura.\n");
        printf("Cargamos segundo arbol:\n\n");
        ArbolBinario arbol2 = a_modo_carga();
        
        if (a_ej4_similares(arbol, arbol2)) {
            printf("\n=> RESULTADO: Los arboles SON similares en estructura.\n");
        } else {
            printf("\n=> RESULTADO: Los arboles NO son similares en estructura.\n");
        }

        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 7
void menuPunto7(){
    int opcion, cant_nodo;
    bool seguir = true, resultado;
    while (seguir == 1){
        printf("\n=== PUNTO 7 ===\n");

        printf("\nCargamos primer arbol\n\n");
        ArbolBinario arbolito1 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 

        printf("\nCargamos segundo arbol\n\n");
        ArbolBinario arbolito2 = a_modo_carga();
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 2 ||\n\n");
        a_mostrar_normal(arbolito2);
        if(a_es_vacio(arbolito2)) printf("\n\n"); 
        
        system("cls");
        printf("\n|| GRAFICO DEL ARBOL 1 ||\n\n");
        a_mostrar_normal(arbolito1);
        if(a_es_vacio(arbolito1)) printf("\n\n"); 
        printf("\n\n\n|| GRAFICO DEL ARBOL 2 ||\n\n");
        a_mostrar_normal(arbolito2);
        if(a_es_vacio(arbolito2)) printf("\n\n"); 

        resultado = a_ej7_equivalente(arbolito1, arbolito2);
        if(resultado == true){
            if(a_es_vacio(arbolito1) && a_es_vacio(arbolito2)){
                printf("\n\nLos dos arboles estaban vacios\n");
            }
            printf("\n=== LOS ARBOLES SON EQUIVALENTES ===\n");
        }
        else{
            printf("\n=== LOS ARBOLES NO SON EQUIVALENTES ===\n");
        }
        seguir = preguntarContinuar();
        system("cls");
    }
}

//EJERCICIO 9
void menuPunto9() {
    bool seguir = true;
    while (seguir) {
        printf("\n=== PUNTO 9 ===\n");
        printf("\n");
        printf("Ingrese la cantidad de repeticiones del proceso (N): ");
        int repeticiones = ingresoDatosNumericos("Invalido.\n");
        
        printf("Ingrese la cantidad de claves aleatorias a generar por arbol: ");
        int cantidad = ingresoDatosNumericos("Invalido.\n");
        
        printf("Ingrese el valor minimo del rango aleatorio: ");
        int minimo = ingresoDatosNumericos("Invalido.\n");
        
        printf("Ingrese el valor maximo del rango aleatorio: ");
        int maximo = ingresoDatosNumericos("Invalido.\n");

        system("cls");
        
        printf("\n=== RESULTADOS DE LA COMPARACION ===\n");
        printf("Generando %d rondas de arboles con %d claves unicas...\n", repeticiones, cantidad);
        
        Lista resultados = a_ej10_comparacionarboles(repeticiones, minimo, maximo, cantidad);
        
        printf("\nLista de diferencias de altura:\n");
        if (!l_es_vacia(resultados)) {
            l_mostrar(resultados);
        } else {
            printf("No se generaron resultados.\n");
        }
        
        printf("CONCLUSION ESPERADA:\n");
        printf("La diferencia suele ser >= 0. El arbol AVL, al estar balanceado, \n");
        printf("siempre tendra una altura menor o igual a la de un ABB con los mismos datos.\n");

        seguir = preguntarContinuar();
        system("cls");
    }
}