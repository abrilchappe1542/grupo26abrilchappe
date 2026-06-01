#include "menu.h"
#include "..\libs\colas\headers\colas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_colas.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
//EJERCICIO 2
void menuPunto2(){
    Cola c;
    Cola c_resultado = c_crear();
    int cantidad;
    int seguir = 1;
    int opcion;
    int clave, pos1, pos2, cant_elementos, valor;
    bool existe;
    TipoElemento x;

    while(seguir==1){
        printf("Ingrese la cantidad de elementos a cargar en la cola (max %d)\n-> ",TAMANIO_MAXIMO);
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, TAMANIO_MAXIMO);
        
        printf("\nCargamos cola original:\n");
        c = c_cargar(cantidad);
        
        printf("\nCOLA ORIGINAL: \n");
        c_mostrar(c);

        printf("\n--- EJERCICIO 2 ---\n");
        printf("1. (a) Buscar una clave\n");
        printf("2. (b) Colocar elemento en posicion ordinal\n");
        printf("3. (c) Eliminar todas las ocurrencias de una clave\n");
        printf("4. (d) Contar elementos\n");
        printf("5. (e) Copiar contenido\n");
        printf("6. (f) Invertir contenido\n");
        printf("\nElija que inciso probar (1-6): ");
        
        opcion = ingresoIntLimitado("Opcion invalida, ingrese entre 1 y 6", 1, 6);
        printf("\n");

            switch (opcion) {
                case 1: // punto A
                    if (c_es_vacia(c)) {
                        printf("La pila esta vacia, por lo tanto el elemento no se encuentra en la lista.\n");      //!cambiooooo
                        break;
                    }
                    printf("Ingrese la clave a buscar: ");
                    clave = ingresoDatosNumericos("Por favor ingresa un numero valido");
                    existe = c_ej2_existeclave(c, clave);
                    if (existe) {
                        printf("-> RESULTADO: La clave %d SI existe en la cola.\n", clave);
                    } 
                    if (!existe){
                        printf("-> RESULTADO: La clave %d NO existe en la cola.\n", clave);
                    }
                    printf("\nVERIFICACION DE COLA ORIGINAL:\n");
                    c_mostrar(c);
                    break;

                case 2: // punto B
                    cantidad = c_ej2_contarelementos(c);
                    
                    printf("Ingrese la posicion ordinal donde insertar (de 1 a %d): ", cantidad+1);       //*cambio
                    pos1 = ingresoIntLimitado("Posicion fuera de rango. Intente de nuevo", 1, cantidad+1);

                    printf("Ingrese el valor numerico del nuevo elemento: ");
                    valor = ingresoDatosNumericos("Numero invalido");
                    
                    x = te_crear(valor); 
                    
                    c_resultado = c_ej2_colarelemento(c, pos1, x);
                    printf("-> RESULTADO DE LA INSERCION:\n");
                    c_mostrar(c_resultado);

                    printf("\nVERIFICACION DE COLA ORIGINAL:\n");
                    c_mostrar(c);
                    break;

                case 3: // punto C
                    printf("Ingrese la clave de la cual quiera eliminar todas sus ocurrencias: ");
                    clave = ingresoDatosNumericos("Numero invalido");

                    c_resultado = c_ej2_sacarelemento(c, clave);

                    printf("-> RESULTADO DE LA ELIMINACION:\n");
                    c_mostrar(c_resultado);

                    printf("\nVERIFICACION DE COLA ORIGINAL:\n");
                    c_mostrar(c);
                    break;

                case 4: // punto D
                    if (c_es_vacia(c)) {
                        printf("La cola esta vacia, por lo tanto tiene 0 elementos.\n");   
                        break;
                    }
                    cantidad = c_ej2_contarelementos(c);                
                    
                    printf("\nLa cola tiene %d elementos.\n",cantidad);

                    printf("\nVERIFICACION DE COLA ORIGINAL:\n");
                    c_mostrar(c);
                    break;

                case 5: // punto E
                    c_resultado = c_ej2_copiar(c);
                    printf("-> RESULTADO DE LA COPIA:\n");
                    c_mostrar(c_resultado);

                    printf("\nVERIFICACION DE COLA ORIGINAL:\n");
                    c_mostrar(c);
                    break;

                case 6: // punto F
                    c_resultado = c_ej2_invertir(c);
                    
                    printf("\n->La cola invertida:\n");
                    c_mostrar(c_resultado);
                    
                    printf("\nVERIFICACION DE COLA ORIGINAL:\n");
                    c_mostrar(c);
                    break;
            
        }

        seguir = preguntarContinuar();
        system("cls");
    }
}

//EJERCICIO 3:
void menuPunto3(){
    int cantidad_elementos_c1;
    int cantidad_elementos_c2;
    bool seguir = 1;
    Cola c1, c2;
    bool resu;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la Cola 1(max %d)\n-> ",TAMANIO_MAXIMO);
        cantidad_elementos_c1 = ingresoIntLimitado("Ingrese un valor adecuado!", 0, TAMANIO_MAXIMO);
        printf("Ingrese la cantidad de elementos a cargar en la Cola 1(max %d)\n-> ",TAMANIO_MAXIMO);
        cantidad_elementos_c2 = ingresoIntLimitado("Ingrese un valor adecuado!", 0, TAMANIO_MAXIMO);

        printf("\nCargamos Cola 1:\n");
        c1 = c_cargar(cantidad_elementos_c1);
        printf("\nCargamos Cola 2:\n");
        c2 = c_cargar(cantidad_elementos_c2);

        printf("\nCOLA 1 ORIGINAL: \n");
        c_mostrar(c1);
         printf("\nCOLA 2 ORIGINAL: \n");
        c_mostrar(c2);

        if(cantidad_elementos_c1 != cantidad_elementos_c2){
            printf("El tamaño de ambas colas es distinto, por lo tanto las colas no seran iguales partiendo desde la base.\n");
        }
        else{
            resu = c_ej3_iguales(c1, c2);
            if(resu == true){
                printf("\nAmbas colas son iguales.\n");
            }
            else{
                printf("\nLas colas no son iguales.\n");
            }
            printf("\nCOMPLEJIDAD ALGORITMICA: La complejidad algoritmica es lineal O(n) ya que posee en while el cual depende del tamanio del problema.\n");
        }
        seguir = preguntarContinuar();
        system("cls");
    }
}

//EJERCICIO 4:
void menuPunto4(){
    int cantidad;
    bool seguir = 1;
    Cola cola, cola_resultado;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la cola (max %d)\n-> ",TAMANIO_MAXIMO);
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, TAMANIO_MAXIMO);
        
        printf("\nCargamos cola original:\n");
        cola = c_cargar(cantidad);
        
        printf("\nCOLA ORIGINAL: \n");
        c_mostrar(cola);

        cola_resultado = c_ej4_colanorepetidos(cola);
        printf("\nELEMENTOS NO REPETIDOS:\n");
        c_mostrar(cola_resultado);

        seguir = preguntarContinuar();
        system("cls");
    }    
}

// EJERCICIO 5:
void menuPunto5(){
    int cantidad;
    bool seguir = 1;
    Cola cola, cola_resultado;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la cola (max %d)\n-> ", TAMANIO_MAXIMO);
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, TAMANIO_MAXIMO);
        
        printf("\nCargamos cola original (valores >= 2 y no repetidos):\n");
        cola = c_cargar_ej5(cantidad); //funcion nueva de valores mayores a 2
        
        printf("\nCOLA ORIGINAL: \n");
        c_mostrar(cola);

        cola_resultado = c_ej5_divisortotal(cola);

        printf("\nRESULTADO (Divisores Totales y Parciales):\n");
        if(c_es_vacia(cola_resultado)){
            printf("No se encontraron divisores totales ni parciales.\n");
        } else {
            Cola c_aux = c_crear();
            while(!c_es_vacia(cola_resultado)){
                TipoElemento elem = c_desencolar(cola_resultado);
                bool* esTotal = (bool*)elem->valor;
                
                if(*esTotal == true){
                    printf("Clave %d: Divisor Total\n", elem->clave);
                } else {
                    printf("Clave %d: Divisor Parcial\n", elem->clave);
                }
                c_encolar(c_aux, elem);
            }
            while(!c_es_vacia(c_aux)){
                c_encolar(cola_resultado, c_desencolar(c_aux));
            }
            
        }
        printf("Complejidad algorítmica: es cuadrática O(n^2) ya que posee dos bucles anidados);
        seguir = preguntarContinuar();
        system("cls");
    }    
}

//EJERCICIO 6
void menuPunto6(){
    Cola c;
    Pila p;
    Lista resultado;
    int cantidad;
    int seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la Pila (max %d) \n",TAMANIO_MAXIMO);
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, TAMANIO_MAXIMO);
        printf("\nCargando pila original...\n");
        p = p_cargar(cantidad);

        printf("Ingrese la cantidad de elementos a cargar en la cola (max %d)\n-> ",TAMANIO_MAXIMO);
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, TAMANIO_MAXIMO);
        
        printf("\nCargando cola original...\n");
        c = c_cargar(cantidad);

        if (p_es_vacia(p))
        {
            printf("La pila esta vacia!\n");
        }
        if (c_es_vacia(c))
        {
            printf("La cola esta vacia!\n");
        }

        printf("\nPILA ORIGINAL: \n");
            p_mostrar(p);

        printf("\nCOLA ORIGINAL: \n");
            c_mostrar(c);

        resultado = c_ej6_comunesapilaycola(p,c);

        printf("\nLISTA DE RESULTADOS: \n");
        if (l_es_vacia(resultado)) {
            printf("No hubo coincidencias entre la Pila y la Cola.\n");
        } else {
            int cant_nodos = l_longitud(resultado);
            printf("("); 
            for (int i = 1; i <= cant_nodos; i++) {
                TipoElemento nodo_lista = l_recuperar(resultado, i);
                printf(" %s ", (char*)nodo_lista->valor);
            }
            printf(")");
            printf("\n");
        }
        seguir = preguntarContinuar();
        system("cls");
    }
}
