#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "../../listas/headers/listas.h"
#include "../../tipoElemento/headers/tipo_elemento.h"
#include "../headers/validaciones.h"

bool esDigito(const char *c){
    if( strlen(c)>1 && (c[0] == '-') ) {
        c++;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        if (!isdigit(c[i])) {
            return false; 
        }
    }
    return true;
}

bool esDigito_positivo(const char *c){
    if( strlen(c)>1 && c[0] == '-' ) {
        return false;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        if(!isdigit(c[i])) {
            return false; 
        }
    }
    return true;
}

bool noEsCero(const char *c){
    bool esCero = false;
    while(c[0]!='\0' && !esCero){
        if(c[0] != '0'){
            esCero = true;
        }
        c++;
    }
    return esCero;
}

bool esFlotante(const char *c){
    bool puntoEncontrado = false;

    if( strlen(c)>1 && (c[0] == '-') ) {
        c++;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        if(c[i] == '.'){
            if(puntoEncontrado){
                return false;
            }
            puntoEncontrado = true;
        }
        else if (!isdigit(c[i])) {
            return false; 
        }
    }
    return true;
}

bool esFlotantePositivo(const char *c){
    bool puntoEncontrado = false;

    if( strlen(c)>1 && (c[0] == '-') ) {
        return false;
    }
    for (int i = 0; c[i] != '\0'; i++) {
        if(c[i] == '.'){
            if(puntoEncontrado){
                return false;
            }
            puntoEncontrado = true;
        }
        else if (!isdigit(c[i])) {
            return false; 
        }
    }
    return true;
}

bool esAlfabetico(const char *c) {
    for (int i = 0; c[i] != '\0'; i++) {
        if(!isalpha(c[i])) {
            return false; 
        }
    }
    return true;
}

bool soloEspacios(char* string){
    int i = 0;
    bool encontro_caracter = false;
    while (encontro_caracter == false && *(string + i) != '\0'){
        if(*(string + i) != ' '){
            encontro_caracter = true;
        }
        i++;
    }
    return encontro_caracter;
}

bool masDeUnCaracter(char* string){
    bool resultado = true;
    if(strlen(string) <= 1){
        resultado = false;
        return resultado;
    }
    return resultado;
}


bool contieneEspacios(const char *c){
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i]==' ') {
            return false; 
        }
    }
    return true;
}

bool soloHyL(char senial[]){    //si la señal solo contiene h o l retorna verdadero
    bool bandera = true, resultado = true;
    int i = 0;
    while(bandera == true && senial[i] != '\0'){
        if(senial[i] == 'L' || senial[i] == 'l'){
            i++;
        }
        else if(senial[i] == 'H' || senial[i] == 'h'){
            i++;
        }
        else{
            resultado = false;
            bandera = false;
        }
    }
    return resultado;  
}

bool verificandoSenial(char senial[]){  //si la señal es valida, retorna true
    bool resultado = true;
    
    if(soloEspacios(senial) == false){
        printf("Ingreso unicamente espacios. Solo debe ingresar letras H y L...:\n");
        resultado = false;
    }
    else if(soloHyL(senial) == false){
        printf("Solo debe ingresar letras H y L...:\n");
        system("pause");
        resultado = false;
    }
    return resultado;
}

char* ingresa_palabra(char* mensaje){
    char palabra[100];
    printf("%s", mensaje);
    
    fgets(palabra,100, stdin);
    int l = strlen(palabra);
    palabra[l-1]=0;

    char* pp = (char*)malloc(l * sizeof(char));
    if(pp == NULL){
        printf("error al solicitar memoria...");
    }
    strcpy(pp, palabra);

    return pp;
}

// Permite ingresar un entero o un punto "." (como string). Si se ingresa un entero, lo guarda en *num y retorna true.
// Si se ingresa un punto ".", retorna false y no modifica *num. Si se ingresa cualquier otro valor, retorna false.
bool ingresoDatosNumericosEnter(const char *mensaje_error, int *num) {
    char *c = ingresa_palabra("");
    if (strlen(c) == 0) {
        free(c);
        return false;
    }

    while (!esDigito(c)) {
        printf("%s\n-> ", mensaje_error);
        free(c);
        c = ingresa_palabra("");
        if (strlen(c) == 0) {
            free(c);
            return false;
        }
    }
    *num = atoi(c);
    free(c);
    return true;
}

int ingresoDatosNumericos(char * mensaje_error){
    bool chequeo = false;
    char * c;
    int num;
    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito(c) && soloEspacios(c));
        if(!chequeo){
            printf("%s\n-> ", mensaje_error);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    num = atoi(c);
    free(c);
    return num;
}

int ingresoDatosNumericosPositivos(char * mensaje_error){
    bool chequeo = false;
    char * c;
    int num;
    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito_positivo(c) && soloEspacios(c));
        if(!chequeo){
            printf("%s", mensaje_error);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    num = atoi(c);
    return num;
}

int ingresoDatosNumericosNoCero(char * mensaje_error){
    bool chequeo = false;
    char * c;
    int num;
    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito_positivo(c) && soloEspacios(c) && noEsCero(c));
        if(!chequeo){
            system("cls");
            printf("%s\n-> ", mensaje_error);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    num = atoi(c);
    return num;
}

int ingresoIntLimitado(char * mensaje_error, int minimo, int maximo){
    bool chequeo = false;
    char * c;
    int num;

    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito(c) && soloEspacios(c));
        if (chequeo) {
            num = atoi(c);
            if (num < minimo || num > maximo) {
                chequeo = false;
            }
        }
        if(!chequeo){
            printf("%s\n-> ", mensaje_error);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    free(c);

    return num;
}

int ingresoIntMinimo(char * mensaje_error, int minimo){
    bool chequeo = false;
    char * c;
    int num;

    while (!chequeo){
        c = ingresa_palabra("");
        chequeo = (esDigito(c) && soloEspacios(c));
        if (chequeo) {
            num = atoi(c);
            if (num < minimo) {
                chequeo = false;
            }
        }
        if(!chequeo){
            printf("%s, minimo: %d\n-> ", mensaje_error, minimo);
            free(c);
            c = NULL;
        }
    }
    chequeo = false;
    free(c);

    return num;
}

double ingresoDatosFloat(char *mensaje_error) {
    bool chequeo = false;
    char *c;
    double num;

    while (!chequeo) {
        c = ingresa_palabra("");
        reemplazarComasPorPuntos(c);
        chequeo = esFlotante(c) && soloEspacios(c);
        if (!chequeo) {
            system("cls");
            printf("%s", mensaje_error);
            free(c);
        }
    }

    num = atof(c);
    free(c);
    return num;
}

double ingresoDatosFloatPositivos(char *mensaje_error) {
    bool chequeo = false;
    char *c;
    double num;

    while (!chequeo) {
        c = ingresa_palabra("");
        reemplazarComasPorPuntos(c);
        chequeo = esFlotantePositivo(c) && soloEspacios(c);
        if (!chequeo) {
            system("cls");
            printf("%s", mensaje_error);
            free(c);
        }
    }

    num = atof(c);
    free(c);
    return num;
}

char* sacarEspacios(char* string){
    int i = 0, f = strlen(string) - 1;      //i = posicion primer elemento || f = posicion ultimo elemento
    while (*(string + i) == ' '){   
        i++;
    }                                   //i = posicion del primer caracter distinto a un espacio || f = posicion del ultimo caracter distinto a un espacio
    while (*(string + f) == ' '){
        f--;
    }
    
    char* string_aux = (char*)malloc((f - i) + 2 * sizeof(char));   
    
    for(int j = 0; j <= (f - i);j++){
        *(string_aux + j) = *(string + (i + j));    //i+j sirve para copiar a partir del primer caracter != ' ' de la cadena
    }
    *(string_aux + (f - i + 1)) = '\0';
    
    string = (char*)realloc(string_aux,((f - i) + 1) * sizeof(char));
    *(string + (f - i + 1)) = '\0';
    //free(string_aux);
    return string;
}

void todoAMayusculas(char* string){
    
    while (*string) //se ejecuta mientras este apuntando al string
    {
        *string = toupper(*string);
        string++;   //avanza en memoria
    }
}

int preguntarContinuar() {
    int continuar;
    char buffer[10];

    while (1) {
        printf("\n\nIngresa 1 para SEGUIR, 0 para NO SEGUIR: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &continuar) == 1 && (continuar == 0 || continuar == 1)) {
                return continuar;
            } else {
                printf("Entrada no valida. Por favor, ingresa 1 para continuar o 0 para salir.\n");
            }
        }
    }
}

int leerEnteroPositivo(const char* mensaje) {
    char buffer[100];
    int valor;
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';  
            if (esDigito_positivo(buffer)) {
                valor = atoi(buffer);
                if (valor > 0) {
                    return valor;
                } else {
                    printf("Entrada no valida. Solo se permiten numeros enteros positivos.\n");
                }
            } else {
                printf("Entrada no valida. Solo se permiten numeros enteros positivos.\n");
            }
        } else {
            printf("Error en la lectura. Intenta de nuevo.\n");
            while (getchar() != '\n');  
        }
    }
}

void reemplazarComasPorPuntos(char *c) {
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == ',') {
            c[i] = '.';
        }
    }
}

void mostrarComparacion(int respuesta){
    if(respuesta == 1){
        printf("por lo cual la lista 1 es MAYOR a la lista 2\n");
    }
    else if(respuesta == 2){
        printf("por lo cual la lista 1 es MENOR a la lista 2\n");
    }
    else{
        printf("ambas listas son iguales\n");
    }
}

// mostrar polinomio (tiene errores)
int intersarEspacios(char* poli, int pos){
    poli[++pos] = ' ';
    poli[++pos] = '+';
    poli[++pos] = ' ';

    return ++pos;
}


void ingresarNumeroStringSeguro(char destino[], int tamanoMaximo) { //punto5
    char entrada[200]; 
    bool esValido = false;

    while (!esValido) {
        esValido = true;

        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0'; 

        int longitud = strlen(entrada);

        if (longitud == 0) {
            printf("Error: No ingresaste nada. Intenta de nuevo: ");
            esValido = false;
            continue; 
        }

        if (longitud == 1 && entrada[0] == '-') {
            printf("Error: Ingresaste solo un signo. Escribe un numero: ");
            esValido = false;
            continue; 
        }

        for (int i = 0; i < longitud; i++) {
            
            if (i == 0 && entrada[i] == '-') {
                continue;
            }

            if (!isdigit(entrada[i])) {
                printf("Error: Solo se permiten numeros (sin espacios ni letras). Intenta de nuevo: ");
                esValido = false;
                break; 
            }
        }

        if (esValido) {
            strncpy(destino, entrada, tamanoMaximo - 1);
            destino[tamanoMaximo - 1] = '\0'; 
        }
    }
}

void ingresarpalindromo(char original[], char limpia[]) { //tp1 punto1
    int i = 0;
    int j = 0;

    while (original[i] != '\0') {
        
        if (isalnum(original[i]) || original[i] == ' ') {
            limpia[j] = tolower(original[i]);
            j++;
        }
        
        i++;
    }

    limpia[j] = '\0';
}


/*-----------------------------------------------------------
  >>>>>>>>>>>>>>>>>>>>>>     LISTAS    <<<<<<<<<<<<<<<<<<<<<
-----------------------------------------------------------*/

Lista l_cargar(int cantidad){
    Lista list = l_crear();
    int num, guia = 0;
    TipoElemento nodo;

    while(!l_es_llena(list) && guia<cantidad){
        printf("  | CLAVE NODO %d | ->\t", guia+1);
        num = ingresoDatosNumericos("Ingrese una clave valida!");
        nodo = te_crear(num);
        l_agregar(list, nodo);
        guia++;
    }

    return list;
}
