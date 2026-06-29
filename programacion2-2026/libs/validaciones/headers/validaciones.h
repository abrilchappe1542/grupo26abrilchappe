
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "../../listas/headers/listas.h"
#include "../../tipoElemento/headers/tipo_elemento.h"
#include "../../pilas/headers/pilas.h"
#include "../../colas/headers/colas.h"
#include "../../arboles/headers/arbol_binario.h"
#include "../../arboles/headers/arbol_binario_busqueda.h"
#include "../../arboles/headers/arbol_avl.h"
#include "../../tablashash/headers/tabla_hash.h"
#include "../../../06-trabajoPractico_TablasHash\tp_thash.h"
#include "../../conjuntos/headers/conjuntos.h"

#ifndef VALIDACIONES_H
#define VALIDACIONES_H

/* >>>>> VALIDACIONES DE STRINGS DE NUMEROS <<<<< */

bool esDigito(const char * cadena); // Retorna TRUE si el string representa solo números enteros.

bool esDigito_positivo(const char * cadena); // Retorna TRUE si el string representa solo números enteros positivos.

bool noEsCero(const char * cadena); // Retorna TRUE si el string representa un numero distinto de cero.

bool esFlotante(const char *c);

bool esFlotantePositivo(const char *c);

void ingresarNumeroStringSeguro(char destino[], int tamanoMaximo);


/* >>>>> VALIDACIONES DE STRINGS <<<<< */

bool esAlfabetico(const char *c); // Retorna TRUE si el string representa solo valores alfabeticos.

bool soloEspacios(char* ); // Retorna TRUE si el string contiene al menos un caracter.

bool masDeUnCaracter(char*); // Retorna TRUE si el string contiene mas de a un caracter.

bool contieneEspacios(const char *);    //Retorna TRUE si el string NO contiene espacios.

bool soloHyL(char senial[]);    //si la señal solo contiene h o l retorna verdadero.

bool verificandoSenial(char senial[]);  //si la señal solo contiene h o l retorna verdadero.


/* >>>>> INGRESOS <<<<< */

char* ingresa_palabra(char* );  // Facilita el ingreso de un string. 

bool ingresoDatosNumericosEnter(const char *mensaje_error, int *num);

int ingresoDatosNumericos(char * mensaje_error); // Facilita el ingreso y la validacion de valores numericos.

int ingresoDatosNumericosPositivos(char * mensaje_error); // Facilita el ingreso y la validacion de valores numericos positivos >= 0.

int ingresoDatosNumericosNoCero(char * mensaje_error); // Facilita el ingreso y la validacion de valores numericos positivos > 0.

int ingresoIntLimitado(char * mensaje_error, int minimo, int maximo); // Ingreso de valores 'int' estableciento un rango.

int ingresoIntMinimo(char * mensaje_error, int minimo); // Ingreso de valores 'int' estableciento un minimo (incluido).

double ingresoDatosFloat(char *mensaje_error); // Facilita el ingreso y la validacion de valores float.

double ingresoDatosFloatPositivos(char *mensaje_error); // Facilita el ingreso y la validacion de valores float positivos >= 0.

void ingresarpalindromo(char original[], char limpia[]);

Lista l_cargar_sin_ceros(int cantidad, int numero_lista);

/* >>>>> HERRAMIENTAS <<<<< */

char* sacarEspacios(char* ); // Elimina los espacios de un string.

void todoAMayusculas(char* string); // Convierte un string a mayusculas.

int preguntarContinuar(); // Pregunta si se desea continuar

int leerEnteroPositivo(const char* mensaje);

void reemplazarComasPorPuntos(char *c);

void mostrarComparacion(int respuesta);




/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>>     LISTAS    <<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

Lista l_cargar(int nodos); // Carga por teclado la lista según la cantidad recibida.

Lista l_cargar_con_valores(int nodos, Lista list); // Carga por teclado la lista según la cantidad recibida, pero además de la clave, carga un valor float para cada nodo.


/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>>     PILAS    <<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

Pila p_cargar(int cantidad); // Carga por teclado la pila según la cantidad recibida.

Pila p_intercambio(Pila auxiliar, Pila p_original); // recibe pila auxiliar, devuelve pila original.


/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>>     PILAS    <<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

Cola c_cargar(int cantidad);

Cola c_cargar_ej5(int cantidad);



/*-------------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>     ARBOLES      <<<<<<<<<<<<<<<<<<<<<
---------------------------------------------------------------*/


void a_mostrar_normal(ArbolBinario arbol);

ArbolBinario a_modo_carga();

ArbolBinario a_cargar_azar(int cantidad_nodos); // carga un arbol con valores 'X' UNICOS, NO REPETIDOS X=[1-100]

ArbolBinario a_cargar_anchura();

ArbolBinario a_cargar_azar_rep(int cantidad_nodos); // carga un arbol con valores 'X' que PUEDEN SER REPETIDOS X=[1-100]

ArbolBinario nArio_modo_carga();

ArbolBinario nArio_cargar_anchura();

ArbolBinario nArio_cargar_azar(int cantidad_nodos);

ArbolBinario nArio_cargar_azar_rep(int cantidad_nodos);

/*-------------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>    TABLAS HASH    <<<<<<<<<<<<<<<<<<<<<
---------------------------------------------------------------*/

int ingresando_Legajo_alumno();

void ingresarString_char_y_numeros(char *mensaje, char buffer[], int Max);

void ingresarString_noEspaciado(char *mensaje, char buffer[], int Max);

void ingresarString_Espaciado(char *mensaje, char buffer[], int Max);

void ingresarEnteros_char(char *mensaje, char buffer[], int Max);

/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>    conjuntos    <<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

Conjunto cto_cargar_manual(int cant_claves);

Conjunto cto_cargar_aleatorio(int cant_claves, int clave_min, int clave_max);

void cto_aniadir(Conjunto origen, Conjunto destino); // copia el contenido de un conjunto hacia otro de destino, sin importar si este no está vacío

Lista l_cargar_ctos_rand(int cant_conjuntos, int cant_te_x_cto, int clave_min, int clave_max); // lista con x cantidad de conjuntos cargados aleatoriamente

Lista l_cargar_ctos_manual(int cant_conjuntos);

Conjunto cto_modo_carga();

Lista ej3cto_modo_carga();

Conjunto cto_modo_carga_ej6yej8();

bool c_ej2_pertenencia(Conjunto A, int clave);

#endif // VALIDACIONES_H

