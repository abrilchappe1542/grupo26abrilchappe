//#include "TP1_Recursividad.h"
#include "tp_1_recursividad.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../libs/validaciones/headers/validaciones.h"

//Ejercicio 1
bool palindromoaux(char *cadena, int inicio, int fin, bool bandera){
    if ((inicio >= fin) || (!bandera))
    {
        return bandera;
    }
    if (cadena[inicio] != cadena[fin]) 
    {
        bandera = false;
    }
    return palindromoaux(cadena, inicio + 1, fin - 1, bandera);
}


bool palindromo (char * cadena){
    int longitud = strlen(cadena); 
    bool bandera = true;
    bool res = palindromoaux(cadena,0,(longitud - 1),bandera);
    return res;
}


//Ejercicio 2
int producto(int m, int n){
    if(n == 0){
        return 0;
    }
    
    if(n<0){
        n = -n;
        return (m + producto(m, n-1))*(-1);
    }
    return m + producto(m, n-1);
}

//Ejercicio 3
int terminoSeridFibonacci(int k){
    if (k==0 || k==1){
        return 1;
    }
    else{
        return terminoSeridFibonacci((k-2)) + terminoSeridFibonacci((k-1));
    }
}


//Ejercicio 4
float divisionConCifras(int m, int n, int limitecifra){
    if(m == 0){
        return 0;
    }
        
    if(limitecifra >= 0){
        return (m - (m % n)) / n + divisionConCifras( (m % n) * 10, n, (limitecifra - 1)) / 10;
    }
    return 0;
}
            
float division(int m, int n, int d){
    return divisionConCifras(m, n, d);
}



//Ejercicio 5
void milesaux(char numero[],char *nuevoNumero, int contador, int i, int j,int limite){
    if (i == limite)
    {
        return;
    }
    
    if (contador == 3)
    {
        nuevoNumero[j] = '.';
        milesaux(numero,nuevoNumero,0, i, j-1,limite);         //no retrocedo en el numero ya que solamente tengo que modificar en el nuevo numero
    }
    else
    {
        nuevoNumero[j] = numero[i];
        milesaux(numero,nuevoNumero,contador+1,i-1,j-1,limite);
    }
    
}


char * agregarSeparadorMiles(char numero[]){
    int limite = -1;         //si es positivo el numero, entonces que vea todo hasta llegar al final
    if (numero[0] == '-')
    {
        limite = 0;         //si es negativo, que vea hasta antes del -
    }

    int longitud = strlen(numero);
    int cantdigitos;

    if (limite == 0)       //el numero es negativo
    { 
        cantdigitos = longitud - 1; //descuento el -    
    }
    else
    {
        cantdigitos = longitud;
    }
    
    
    int cantidadpuntos = (cantdigitos - 1) / 3;
    int nuevalong = longitud + cantidadpuntos;
    char *nuevoNunero = (char *)malloc((nuevalong+1) * sizeof(char));
    nuevoNunero[nuevalong] = '\0';
    if (limite == 0)
    {
        nuevoNunero[0] = '-';
    }
    
    milesaux(numero,nuevoNunero,0,longitud-1,nuevalong-1,limite);


    return nuevoNunero;
}




//Ejercicio 6
void chino(int n,char * resultado_reunionChina,int posicion_chino,int posicion){
    if (n==1){
        resultado_reunionChina[posicion]='(';
        resultado_reunionChina[posicion+1]='-';
        resultado_reunionChina[posicion+2]='.';
        resultado_reunionChina[posicion+3]='-';
        resultado_reunionChina[posicion+4]=')';
        resultado_reunionChina[posicion+5]='\0';
        return;
    }
    else {
        if(posicion_chino-1==n*2-2){
            resultado_reunionChina[posicion]='\0';
            return;
        }
        if (posicion_chino<n-1){
            resultado_reunionChina[posicion]='(';
            resultado_reunionChina[posicion+1]='-';
            resultado_reunionChina[posicion+2]='.';
            return chino(n,resultado_reunionChina,posicion_chino+1,posicion+3);
        }
        else if (posicion_chino==n-1){
            resultado_reunionChina[posicion]='(';
            resultado_reunionChina[posicion+1]='-';
            resultado_reunionChina[posicion+2]='.';
            resultado_reunionChina[posicion+3]='-';
            resultado_reunionChina[posicion+4]=')';
            return chino(n,resultado_reunionChina,posicion_chino+1,posicion+5);
        }
        else{
            resultado_reunionChina[posicion]='.';
            resultado_reunionChina[posicion+1]='-';
            resultado_reunionChina[posicion+2]=')';
            return chino(n,resultado_reunionChina,posicion_chino+1,posicion+3);
        }
    }
}
char * reunionMafia(int nivel){
    int cantidad=(((nivel-1)*2)*3)+6;
    char *resultado_reunionChina=(char*)malloc(sizeof(char)*cantidad);
    chino(nivel,resultado_reunionChina,0,0);
    return resultado_reunionChina;
}




//Ejercicio 7
void senal(char low_high[],int posicion_senal,int posicion_resultado,char *resultado_senial,int largo){
    if (posicion_senal >=largo){
        resultado_senial[posicion_resultado]='\0';
        return;
    }
    else if (posicion_senal==0){
        if (low_high[posicion_senal]=='H'){
            resultado_senial[posicion_resultado]='-';
        }
        else{
            resultado_senial[posicion_resultado]='_';
        }
        return senal(low_high,posicion_senal+1,posicion_resultado+1,resultado_senial,largo);
    }
    else {
        if (low_high[posicion_senal]=='H'){
            if (low_high[posicion_senal-1]=='H'){
                resultado_senial[posicion_resultado]='-';
                return senal(low_high,posicion_senal+1,posicion_resultado+1,resultado_senial,largo);
            }
        else{
            resultado_senial[posicion_resultado]='|';
            resultado_senial[posicion_resultado+1]='-';
            return senal(low_high,posicion_senal+1,posicion_resultado+2,resultado_senial,largo);
        }
    }
    else if (low_high[posicion_senal]=='L'){
        if (low_high[posicion_senal-1]=='L'){
            resultado_senial[posicion_resultado]='_';
        return senal(low_high,posicion_senal+1,posicion_resultado+1,resultado_senial,largo);
        }
        else{
            resultado_senial[posicion_resultado]='|';
            resultado_senial[posicion_resultado+1]='_';
            return senal(low_high,posicion_senal+1,posicion_resultado+2,resultado_senial,largo);
            }
        }
    }
}
char * ondaDigital(char seniales[]){
    int largo=strlen(seniales);
    char *resultado_senial=(char*)malloc(sizeof(char)*(largo*2));
    senal(seniales,0,0,resultado_senial,largo);
    printf("Las ondas digitales en formato _ y -: %s\n", resultado_senial);
    return resultado_senial;
}




//Ejercicio 8
void encontrarCombinaciones(int conjunto[], int suma_actual, int tamano, int indice, int combinacion[], int longitud, int n, char **output, int *output_index) {
    
    if (suma_actual == n) {
        if (longitud > 0) {  
            char *combinacion_str = (char *)malloc((longitud * 3 + 1) * sizeof(char));  
            int pos = 0;

            
            for (int i = 0; i < longitud; i++) {
                pos += sprintf(combinacion_str + pos, "%d ", combinacion[i]);
            }

            output[*output_index] = combinacion_str;
            (*output_index)++;
        }
        return;
    }
    if (indice == tamano || suma_actual > n) {
        return;
    }
    combinacion[longitud] = conjunto[indice];
    encontrarCombinaciones(conjunto, suma_actual + conjunto[indice], tamano, indice + 1, combinacion, longitud + 1, n, output, output_index);
    while (indice + 1 < tamano && conjunto[indice] == conjunto[indice + 1]) {
        indice++;
    }
    encontrarCombinaciones(conjunto, suma_actual, tamano, indice + 1, combinacion, longitud, n, output, output_index);
}



void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output) {
    int combinacion_actual[tamano];
    int output_index = 0;
    for (int i = 0; i < tamano - 1; i++) {
        for (int j = i + 1; j < tamano; j++) {
            if (conjunto[i] > conjunto[j]) {
                int temp = conjunto[i];
                conjunto[i] = conjunto[j];
                conjunto[j] = temp;
            }
        }
    }

    encontrarCombinaciones(conjunto, 0, tamano, 0, combinacion_actual, 0, n, output, &output_index);
    
    if (output_index == 0) {
        output[0] = NULL;
    }
}


//Ejercicio 9
bool divisiblePor7(int n){
    int auxiliar;
    if(n<70){
            return (n%7)==0;
    }
    auxiliar = n %10*2;
    n = n /10;
    return divisiblePor7(n-auxiliar);
}


//Ejercicio 10
int* explosivo(int n,int b,int *vector_p_10,int i){
    int n1=n/b;
    int n2=n-n1;
    vector_p_10[i]=n1;
    i++;
    if(n1>b){
        return explosivo(n1,b,vector_p_10,i);
    }
    else if (n2>b){
        return explosivo(n2,b,vector_p_10,i);
    }
    if (n>b){
        vector_p_10[i]=b;
        return vector_p_10;
    }
}
void mostrarExplosivo(int *vector_p_10,int b,int i){
    if ((vector_p_10[i]==b) && (i!=0)){
        printf("%d",vector_p_10[i]);
        return;
    }
    else{
        printf("%d - ",vector_p_10[i]);
        return mostrarExplosivo(vector_p_10,b,i+1);
    }
}


int* explosion (int n, int b){
    int* vector_p_10=(int*)malloc(sizeof(int) * 100);
    if (!vector_p_10){
        printf("Error al asignar memoria.\n");
        return NULL;
    }
    explosivo(n, b, vector_p_10, 0);
    mostrarExplosivo(vector_p_10,b,0);
    return vector_p_10;
}
