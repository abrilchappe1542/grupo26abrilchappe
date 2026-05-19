#include "menu.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_pilas.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
//EJERCICIO 2
void menuPunto2(){
    Pila p;
    Pila p_resultado = p_crear();
    int cantidad;
    int seguir = 1;
    int opcion;
    int clave, pos1, pos2, cant_elementos, valor;
    bool existe;
    TipoElemento x;

    while(seguir==1){
        printf("Ingrese la cantidad de elementos a cargar en la pila (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila original:\n");
        p = p_cargar(cantidad);
        if (p_es_vacia(p)) {
            printf("La pila esta vacia.\n");
        } else {
            printf("\nPILA ORIGINAL: \n");
            p_mostrar(p);

            printf("\n--- EJERCICIO 2 ---\n");
            printf("1. (a) Buscar una clave\n");
            printf("2. (b) Colocar elemento en posicion ordinal\n");
            printf("3. (c) Eliminar primera ocurrencia de clave\n");
            printf("4. (d) Intercambiar posiciones\n");
            printf("5. (e) Duplicar contenido\n");
            printf("6. (f) Contar elementos\n");
            printf("\nElija que inciso probar (1-6): ");
            
            opcion = ingresoIntLimitado("Opcion invalida, ingrese entre 1 y 6", 1, 6);
            printf("\n");

            switch (opcion) {
                case 1: // punto A
                    printf("Ingrese la clave a buscar: ");
                    clave = ingresoDatosNumericos("Por favor ingresa un numero valido");
                    existe = p_ej2_existeclave(p, clave);
                    if (existe) {
                        printf("-> RESULTADO: La clave %d SI existe en la pila.\n", clave);
                    } else {
                        printf("-> RESULTADO: La clave %d NO existe en la pila.\n", clave);
                    }
                    printf("\nVERIFICACION DE PILA ORIGINAL:\n");
                    p_mostrar(p);
                    break;

                case 2: // punto B
                    int cantidad = p_ej2_cantidadelementos(p);
                    
                    printf("Ingrese la posicion ordinal donde insertar (de 1 a %d): ", cantidad + 1);
                    pos1 = ingresoIntLimitado("Posicion fuera de rango. Intente de nuevo", 1, cantidad + 1);

                    printf("Ingrese el valor numerico del nuevo elemento: ");
                    valor = ingresoDatosNumericos("Numero invalido");
                    
                    x = te_crear(valor); 
                    
                    p_resultado = p_ej2_colocarelemento(p, pos1, x);
                    printf("-> RESULTADO DE LA INSERCION:\n");
                    p_mostrar(p_resultado);

                    printf("\nVERIFICACION DE PILA ORIGINAL:\n");
                    p_mostrar(p);
                    break;

                case 3: // punto C
                    printf("Ingrese la clave de la cual eliminar su primera ocurrencia: ");
                    clave = ingresoDatosNumericos("Numero invalido");

                    p_resultado = p_ej2_eliminarclave(p, clave);

                    printf("-> RESULTADO DE LA ELIMINACION:\n");
                    p_mostrar(p_resultado);

                    printf("\nVERIFICACION DE PILA ORIGINAL:\n");
                    p_mostrar(p);
                    break;

                case 4: // punto D
                    printf("Ingrese la primera posicion ordinal: ");
                    pos1 = ingresoDatosNumericos("Numero invalido");

                    printf("Ingrese la segunda posicion ordinal a intercambiar: ");
                    pos2 = ingresoDatosNumericos("Numero invalido");
                    
                    p_resultado = p_ej2_intercambiarposiciones(p, pos1, pos2);
                    printf("-> RESULTADO DEL INTERCAMBIO:\n");
                    p_mostrar(p_resultado);

                    printf("\nVERIFICACION DE PILA ORIGINAL:\n");
                    p_mostrar(p);
                    break;

                case 5: // punto E
                    p_resultado = p_ej2_duplicar(p);
                    printf("-> RESULTADO DE LA DUPLICACION:\n");
                    p_mostrar(p_resultado);

                    printf("\nVERIFICACION DE PILA ORIGINAL:\n");
                    p_mostrar(p);
                    break;

                case 6: // punto F
                    cant_elementos = p_ej2_cantidadelementos(p);
                    printf("-> RESULTADO: La pila contiene %d elementos en total.\n", cant_elementos);
                    printf("\nVERIFICACION DE PILA ORIGINAL:\n");
                    p_mostrar(p);
                    break;
            }
        }

        seguir = preguntarContinuar();
        system("cls");
    }
}

//EJERCICIO 3
void menuPunto3(){
    Pila p1 = p_crear();
    Pila p2 = p_crear();
    int cantidad_elementos_p1_y_p2;
    int seguir = 1;
    bool resultado;
    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en la Pila 1 y Pila 2(max 10) \n");
        cantidad_elementos_p1_y_p2 = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos Pila 1:\n");
        p1 = p_cargar(cantidad_elementos_p1_y_p2);
        printf("\nCargamos Pila 2:\n");
        p2 = p_cargar(cantidad_elementos_p1_y_p2);

        printf("\nPILA 1: \n");
        p_mostrar(p1);
        printf("\nPILA 2: \n");
        p_mostrar(p2);

        resultado = p_ej3_iguales(p1, p2);
        if(resultado == true){
            printf("\nLas dos pilas son iguales\n");
        }
        else{
            printf("\nLas dos pilas no son iguales\n");
        }
        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nEsta funcion es de orden lineal O(n), ya que posee un solo ciclo while el cual depende del tamanio n del problema.\n");
        seguir = preguntarContinuar();
        system("cls");
    }
}

//EJERCICIO 4
void menuPunto4(){
    int nrobasedecimal, nrootrabase;
    char* resultado;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese un numero en base decimal: \n-> ");
        nrobasedecimal = ingresoDatosNumericos("\nEntrada erronea.\n-> ");
        printf("Ingrese la base a la que desea convertir (entre 2 y 16): \n-> ");
        nrootrabase = ingresoIntLimitado("\nEntrada erronea.\n-> ", 2, 16);
        resultado = p_ej4_cambiarbase(nrobasedecimal, nrootrabase);
        printf("El numero %d en base %d es: %s\n", nrobasedecimal, nrootrabase, resultado);
        free(resultado);
        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nEsta funcion es de orden logaritmico: O(log(n)) donde n es el numero en base decimal.");
        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 5
void menuPunto5() {
    Pila p, p_invertida;
    int cantidad;
    int seguir = 1;

    while (seguir == 1) {
        printf("Ingrese la cantidad de elementos a cargar en la pila (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila original:\n");
        p = p_cargar(cantidad);
        
        if (p_es_vacia(p)) {
            printf("La pila esta vacia.\n");
        } else {
            printf("\nPILA ORIGINAL: \n");
            p_mostrar(p);

            p_invertida = p_ej5_invertir(p);

            printf("\nPILA INVERTIDA RESULTANTE: \n");
            p_mostrar(p_invertida);

            printf("\nVERIFICACION DE PILA ORIGINAL (No debe haberse perdido): \n");
            p_mostrar(p);

            printf("\nCOMPLEJIDAD ALGORITMICA:\nLa funcion es de orden lineal O(n) teniendo en cuenta las TADS. \nSe realizan dos ciclos while que recorren los n elementos de forma secuencial.\n");
        }
        
        seguir = preguntarContinuar();
        system("cls");
    }
}

void menuPunto6(){
    Pila p;

    int cantidad;
    int seguir = 1;
    while (seguir == 1)
    {
        printf("Ingrese la cantidad de elementos a cargar en las pilas (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila 1:\n");
        p = p_cargar(cantidad);
    
    
    if (p_es_vacia(p))
    {
        printf("La pila esta vacia\n");
    }

    else
    {
        Pila pres;
        printf("\nLa pila original:\n");
        p_mostrar(p);
        printf("\nIngrese el valor que quiere eliminar: ");
        int valor = ingresoDatosNumericos("Ese valor no es posible ingresar. Porfavor ingresa un numero valido");
     
        printf("\nIngrese si quiere el caso (1).Iterativo o (2).Recursivo:");
        int ite_rec = ingresoIntLimitado("Valor invalido, 1. Iteartivo, 2. Recursivo\n",1,2);

        if (ite_rec == 1)
        {
            pres = p_ej6_eliminarclave(p,valor);
            printf("\nDe forma iterativa\nLa pila sin el valor %d quedo asi:\n|\n|\n",valor);
            p_mostrar(pres);
        }
        else
        {
            pres = p_ej6_eliminarclaveRecursivo(p,valor);
            printf("\nDe forma recursiva\nLa pila sin el valor %d quedo asi:\n|\n|\n",valor);
            p_mostrar(pres);
        }

    
        printf("\nLa complejidad algoritmica de la funcion iterativa como de la recursiva es de orden lineal O(n) teniendo en cuenta las tads ya que el tiempo de ejecucion \nse ajustara en base al tamanio del programa");
    }
    
    
    seguir = preguntarContinuar();
    system("cls");
    }
}

// EJERCICIO 7
void menuPunto7(){
    Pila pilon1, pilon2, p_resultado;
    int cantidad;
    bool seguir = 1;

    while(seguir == 1){
        printf("Ingrese la cantidad de elementos a cargar en las pilas (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);
        
        printf("\nCargamos pila 1:\n");
        pilon1 = p_cargar(cantidad);
        printf("\nCargamos pila 2:\n");
        pilon2 = p_cargar(cantidad);

        printf("\nPILA 1: \n");
        p_mostrar(pilon1);
        printf("\nPILA 2: \n");
        p_mostrar(pilon2);

        p_resultado = p_ej7_elementoscomunes(pilon1, pilon2);
        printf("\nELEMENTOS EN COMUN: \n");
        p_mostrar(p_resultado);

        printf("\n\nCOMPLEJIDAD ALGORITMICA:\nEsta funcion es de orden cuadratico: O(n * m) donde n es el tamanio de la pila 1, \ny m es el tamanio de la pila 2.");
        seguir = preguntarContinuar();
        system("cls");
    }
}

// EJERCICIO 8
void menuPunto8(){
    Pila p, pres;
    bool seguir = 1;
    int cantidad;
    while (seguir == 1)
    {
        printf("Ingrese la cantidad de elementos a cargar en las pilas (max 10)\n-> ");
        cantidad = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 10);

        if (cantidad == 0)
        {
            printf("La pila ingresada esta vacia, no se ejecutara la funcion.");
        }
        
        else
        {
            printf("\nCargamos pila 1:\n");
            p = p_cargar(cantidad);
    
            printf("\nPILA 1: \n");
            p_mostrar(p);
    
            pres = p_ej8_sacarrepetidos(p);
            TipoElemento elem;
            while (!p_es_vacia(pres))
            {
                elem = p_desapilar(pres);
                int cantidad = *((int*) elem->valor);
                printf("\nEl valor %d aparece %d veces.",elem->clave,cantidad);        
            }    
        }
        printf("\nLa complejidad algoritmica de este ejercicio es de orden cuadratico O(n*n) ya que con un ciclo recorro la pila original y con otro ciclo anidado recorro la segunda pila donde voy viendo si el numero ya estaba contado");
        seguir = preguntarContinuar();
        system("cls");        
    }
    
}
