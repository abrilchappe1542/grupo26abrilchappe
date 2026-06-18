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

// EJERCICIO 3
void menuPunto3(){
    int opcion, cant_nodo;
    bool seguir = true;
    int clave1, clave2;
    Lista l;
    Iterador iter;
    TipoElemento te;

    ArbolBinario arbolito = a_modo_carga();
    system("cls");
    printf("\n|| GRAFICO DEL ARBOL ||\n\n");
    a_mostrar_normal(arbolito);
    if(a_es_vacio(arbolito)) printf("\n\n");
    
    while (seguir == 1){
        printf("\n=== MENU DEL PUNTO 3 ===\n");
        printf("1. Ejercicio A  (Indicar el nombre del nodo padre (clave))\n");
        printf("2. Ejercicio B (Listar los hijos (solo las clave/s)) \n");
        printf("3. Ejercicio C (Listar el hermano (solo la clave)) \n");
        printf("4. Ejercicio D (Calcular el nivel en el que se encuentra.) \n");
        printf("5. Ejercicio E (Calcular la altura de su rama (Altura del Subárbol)) \n");
        printf("6. Ejercicio F (Listar todos los nodos que estan en el mismo nivel (solo la clave)) \n");
        printf("0. Salir \n");
        printf("-1. Cargar nuevo arbol \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", -1, 6);
        system("cls");
        
        l = l_crear();
        switch (opcion){
            case -1:
                arbolito = a_modo_carga();
                system("cls");
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n"); 
                break;

            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;

            case 1: // ejercicio a
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo que desee averiguar su padre... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                clave2 = a_ej3_clavepadre(arbolito, clave1);
                if(clave2 == -1){
                    printf("\nLa raiz no tiene padre o el arbol estaba vacio");
                }
                else if(clave2 == clave1){
                    printf("\nNo se encontro la clave esperada...");
                }
                else{
                    printf("\nEL NODO %d ES PADRE DE %d\n", clave2, clave1);
                }
                break;

            case 2:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo que desee averiguar sus hijos... ");
                clave2 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                l = a_ej3_hijos(arbolito, clave2);
                if(l_es_vacia(l)){
                    printf("\nNo se encontraron hijos de la clave...");
                }
                else{
                    l_mostrar(l);
                }
                break;

            case 3:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo que desee averiguar su hermano... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                clave2 = a_ej3_hermano(arbolito, clave1);
                if(clave2 == -1){
                     printf("\nEste nodo no tiene hermano\n");
                }
                else{
                    printf("\nEl hermano de %d es %d\n", clave1, clave2);
                }
                break;

            case 4:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo al que desee averiguar el nivel al que se encuentra... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                clave2 = a_ej3_nivel(arbolito, clave1);
                if(clave2 == -1){
                    printf("\nNo se encontro la clave...\n"); 
                }
                else{
                    printf("\nEl nivel del nodo %d es %d\n", clave1, clave2);
                }
                break;

            case 5:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese un nodo el cual desee averiguar la altura de su rama... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                clave2 = a_ej3_alturarama(arbolito, clave1);
                if(clave2 == -1){
                    printf("\nNo se encontro la clave...\n"); 
                }
                else{
                    printf("\nLa altura de la rama del nodo %d es %d\n", clave1, clave2);
                }
                break;

            case 6:
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                printf("\nIngrese el nivel que desee averiguar todo los nodos... ");
                clave1 = ingresoDatosNumericos("Ingrese un valor adecuado!");
                l = a_ej3_clavesmismonivel(arbolito, clave1);
                if(l_es_vacia(l)){
                    printf("\n\nNo se encontraron nodos en ese nivel o el arbol estaba vacio");
                }
                else{
                    printf("\nLos nodos en el nivel %d son...", clave1);
                    l_mostrar(l);
                }
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

// EJERCICIO 8
void menuPunto8(){
    int opcion, cant_nodo, altura, nivel, clave;
    Lista l_res;
    bool seguir = true;

    ArbolBinario arbolito = nArio_modo_carga();
    system("cls");
    printf("\n|| GRAFICO DEL ARBOL ||\n\n");
    a_mostrar_normal(arbolito);
    if(a_es_vacio(arbolito)) printf("\n\n"); 

    while (seguir == 1){
        printf("\n=== MENU DEL PUNTO 8 ===\n");
        printf("1. Ejercicio A (Determinar la altura del n-ario)\n");
        printf("2. Ejercicio B (Determinar el nivel de un nodo)\n");
        printf("3. Ejercicio C (Listar todos los nodos internos (solo las claves))\n");
        printf("4. Ejercicio D (Determinar si todas las hojas estan al mismo nivel)\n");
        printf("0. Salir \n");
        printf("-1. Cargar nuevo arbol \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", -1, 4);
        system("cls");

        switch (opcion){
            case 1: // ejercicio a
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");
                altura = a_ej8_altura(arbolito);
                if(altura == 0){
                    printf("\n\nEl arbol ingresado estaba vacio...");
                }
                else if(altura == 1){
                    printf("\n\nEl arbol ingresado solo tenia la raiz...");
                }
                printf("\nALTURA DEL ARBOL N-ARIO: %d\n", altura);
                break;
            
            case 2: // ejercicio b
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");

                printf("\n\nIngrese la clave del nodo que desea saber su nivel\n-> ");
                clave = ingresoDatosNumericos("Ingrese un valor adecuado!");

                nivel = a_ej8_nivel(arbolito, clave);
                if(nivel == -1){
                    printf("\n\nNo se encontro el nodo...");
                }
                else{
                    if(nivel == 0){
                        printf("\n\nEl nodo era la raiz...");
                    }
                    printf("\nNIVEL DEL NODO %d EN EL ARBOL N-ARIO: %d\n", clave, nivel);
                }
                break;

            case 3: // ejercicio c
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");

                l_res = a_ej8_internos(arbolito);
                if(l_es_vacia(l_res)){
                    printf("\nNODOS INTERIORES DEL N-ARIO:\n");
                    printf("\nLa lista esta vacia...");
                }
                else{
                    printf("\nNODOS INTERIORES DEL N-ARIO:\n");
                    l_mostrar(l_res);
                } 

                break;

            case 4: // ejercicio d
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n");

                bool res = a_ej8_hojasmismonivel(arbolito);
                if(!a_es_vacio(arbolito)){
                    printf(res ? "\nLas hojas son del mismo nivel" : "\nLas hojas NO son del mismo nivel");
                }
                else{
                    printf("\nEl arbol ingresado estaba vacio...");
                }

                break;
            
            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;

            case -1:
                arbolito = nArio_modo_carga();
                system("cls");
                printf("\n|| GRAFICO DEL ARBOL ||\n\n");
                a_mostrar_normal(arbolito);
                if(a_es_vacio(arbolito)) printf("\n\n"); 
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