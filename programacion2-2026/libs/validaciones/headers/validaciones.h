#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "../../listas/headers/listas.h"
#include "../../tipoElemento/headers/tipo_elemento.h"



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




#endif

