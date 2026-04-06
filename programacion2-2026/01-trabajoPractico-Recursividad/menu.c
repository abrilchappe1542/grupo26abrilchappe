#include "menu.h"
#include "../libs/validaciones/headers/validaciones.h"

void menuPunto1(){
    int seguir = 1;
    char palabra[100];
    char palabralimpia[100];

    while(seguir == 1){
        bool bandera = false;

        printf("Ingrese una palabra o frase: ");
        fgets(palabra, sizeof(palabra), stdin); 

        palabra[strcspn(palabra, "\n")] = '\0';

        ingresarpalindromo(palabra, palabralimpia);

        // todoAMayusculas(palabra);
        bandera = palindromo(palabralimpia);  
        
        if(bandera == true){
            printf("La palabra o frase %s, es un palindromo\n",palabra);
        }

        else if(bandera == false){
            printf("La palabra o frase %s, NO es un palindromo\n",palabra);
        }

        printf(".\n.\n.\n>>>> Desea ingresar otro valor?\n");
        seguir = preguntarContinuar();
        system("cls");
    
    }
}


void menuPunto2(){
    char *m, *n;
    int resultado;
    int seguir = 1;
    
    while(seguir == 1){
        bool chequeo = false;

        while (!chequeo){
            m = ingresa_palabra("Ingrese el multiplicando 'm':\n-> ");
            chequeo = (esDigito(m) && soloEspacios(m));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n ACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(m);
            }
        }

        system("cls");
        chequeo = false;

        while (!chequeo){
            n = ingresa_palabra("Ingrese el multiplicador 'n':\n-> ");
            chequeo = (esDigito(n) && soloEspacios(n));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n-> ");
                free(n);
            }
        }

        resultado = producto(atoi(m), atoi(n));
        printf("\n%s * %s = %d\n", m, n, resultado);

        printf(".\n.\n.\n>>>> Desea realizar otra multiplicacion?\n");
        seguir = preguntarContinuar();

        free(n);
        free(m);
        system("cls");
    }

}


void menuPunto3(){
    int respuesta;
    char *entrada;
    int seguir = 1;
    
    while(seguir == 1){
        bool chequeo = false;

        while (!chequeo) {
            entrada = ingresa_palabra("Ingrese un numero 'k' para calcular el k-esimo numero de la serie Fibonacci:\n-> ");
            chequeo = (esDigito_positivo(entrada) && soloEspacios(entrada));
            if (!chequeo) {
                system("cls");
                printf(">> Entrada no valida, ingrese un entero.\n ACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(entrada);
            }
        }

        respuesta = terminoSeridFibonacci(atoi(entrada));
        printf("\nFibonacci(%d) = %d\n", atoi(entrada), respuesta);
        
        printf(".\n.\n.\n>>>> Quiere calcular otro valor de la serie Fibonacci?\n");
        seguir = preguntarContinuar();

        free(entrada); 
        system("cls");
    }
}



void menuPunto4(){
    char *m = NULL, *n = NULL, *d = NULL;
    float resultado;
    int seguir = 1;

    while(seguir == 1){
        bool chequeo = false;

        while (!chequeo){
            m = ingresa_palabra("Ingrese un dividendo 'm':\n-> ");
            chequeo = (esDigito(m) && soloEspacios(m));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n ACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(m);
                m = NULL;
            }
        }

        system("cls");
        chequeo = false;
        
        while (!chequeo){
            n = ingresa_palabra("Ingrese un divisor 'n':\n-> ");
            chequeo = (esDigito(n) && soloEspacios(n) && noEsCero(n));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(n);
                n = NULL;
            }
        }
        
        system("cls");
        chequeo = false;

        while (!chequeo){
            d = ingresa_palabra("Ingrese una cantidad de decimales 'd':\n-> ");
            chequeo = (esDigito(d) && soloEspacios(d) && noEsCero(d));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(d);
                d = NULL;
            }
        }

        resultado = division(atoi(m), atoi(n),atoi(d));
        printf("\n%d / %d = %.*f\n", atoi(m), atoi(n),atoi(d), resultado);

        printf(".\n.\n.\n.\n>>>> Desea calcular otra division?\n");
        seguir = preguntarContinuar();

        free(m);
        free(n);
        free(d);
        system("cls");
    }
}

void menuPunto5(){
    char numeroIngresado[100]; 
    int seguir = 1;

    while(seguir == 1){
        bool chequeo = false;

        printf("Ingrese un numero entero (puede ser negativo): ");
        ingresarNumeroStringSeguro(numeroIngresado, 100); 
            
        char *numeroFormateado = agregarSeparadorMiles(numeroIngresado);
            
        printf("\nResultado:\n");
        printf("El numero con puntos es: %s\n", numeroFormateado);

        printf(".\n.\n.\n>>>> Desea ingresar otro valor?\n");
        seguir = preguntarContinuar();

        free(numeroFormateado);
        system("cls");
    }
}

void menuPunto6(){
    char *n;
    int seguir = 1;

    while(seguir == 1){
        bool chequeo = false;
        chequeo = false;
        while (!chequeo){
            n = ingresa_palabra("Ingrese el nivel del grupo de la mafia china (1 - 10.000):\n-> ");
            chequeo = (esDigito_positivo(n) && soloEspacios(n));
            if(chequeo){
               if(atoi(n) == 0 || atoi(n) > 10000){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\nACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                chequeo = false;
               }
            }
            else{
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\nACLARACION!! numeros positivos sin el '+' al principio.\n\n");
                free(n);
            }
        }
    
        char *grupo = reunionMafia(atoi(n));
        printf("%s\n",grupo);
        free(grupo);
        printf("\n");
        seguir = preguntarContinuar();

        free(n);
        system("cls");
    }
}


void menuPunto7(){
    char* senial;
    int n, seguir = 1;

    while(seguir == 1){
        bool bandera = false;
        while (!bandera)    //hasta que la palabra ingresada no sea valida, no sale del while
        {   
            senial = ingresa_palabra("Ingrese una senial: ");
            bandera = verificandoSenial(senial);
            if(!bandera){   //si no es valido el ingreso del string, libera la memoria utilizada
                printf("\nIngrese una senial valida! Que no contenga espacios y sean solo H y/o L.\n");
                free(senial);
            }
        }

        todoAMayusculas(senial);
        printf("\nLas ondas digitales en formato L y H: %s\n", senial);
        ondaDigital(senial);

        printf("\nDesea volver a formatear ondas digitales?\n");
        free(senial);
        seguir = preguntarContinuar();
        system("cls");
    }
    printf("Presione ENTER para continuar...");
    getchar();
}


void menuPunto8(){
    int tamano, n, continuar;

    do {
        tamano = leerEnteroPositivo("Numero de elementos en el conjunto: ");
        int* conjunto = (int*)malloc(tamano * sizeof(int));

        if (conjunto == NULL) {
            printf("Error al asignar memoria.\n");
            return;
        }

        printf("Por favor ingrese %d numeros enteros positivos:\n", tamano);

        
        for (int i = 0; i < tamano; i++) {
            conjunto[i] = leerEnteroPositivo("Ingrese un numero: ");
        }

        n = leerEnteroPositivo("Ingrese un valor objetivo a alcanzar: ");
        
        
        char *output[100] = {NULL};
        
        
        subconjuntosQueSumanN(conjunto, tamano, n, output);

        
        printf("Subconjuntos que suman %d:\n", n);
        int i = 0;

        
        if (output[0] == NULL) {
            printf("No se encontraron subconjuntos que sumen %d.\n", n);
        } else {
            
            while (i < 100 && output[i] != NULL) {
                printf("{ %s }\n", output[i]);
                free(output[i]);  
                output[i] = NULL;  
                i++;
            }
        }

        free(conjunto);  

        continuar = preguntarContinuar();

    } while (continuar == 1); 

}


void menuPunto9(){
    bool resultado;
    char *numero=NULL;
    bool seguir = true;
    while (seguir){
        bool chequeo=false;
        while(!chequeo){
            numero=ingresa_palabra("Ingrese el posible 'N' divisible por 7:\n-> ");
            chequeo = (esDigito_positivo(numero) && soloEspacios(numero) && noEsCero(numero));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(numero);
                numero=NULL;
            }
        }
        int n_int=atoi(numero);
        resultado=divisiblePor7(n_int);
        if(resultado==true){
            printf("El numero %d es divisible por 7",n_int);
        }
        else{
            printf("El numero %d no es divisible por 7",n_int);
        }
        free(numero);
        printf("\n\n>>>> Desea realizar otra division? SI = 1, NO = 0: ");
        while(scanf("%d", &seguir) !=1 || (seguir !=0 && seguir !=1)){
            printf("Ingrese 1 para SI o 0 para NO: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        printf("\n\n");
    }
}


void menuPunto10(){
    char *n=NULL, *b=NULL;
    int * resultado=NULL;
    bool seguir = true;

    while(seguir){
        bool chequeo = false;

        while (!chequeo){
            n = ingresa_palabra("Ingrese un numero 'N':\n-> ");
            chequeo = (esDigito_positivo(n) && soloEspacios(n) && noEsCero(n));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(n);
                n=NULL;
            }
        }

        system("cls");
        chequeo = false;

        while (!chequeo){
            b = ingresa_palabra("Ingrese una bomba 'B':\n-> ");
            chequeo = (esDigito_positivo(b) && soloEspacios(b) && noEsCero(b));
            if(!chequeo){
                system("cls");
                printf(">> Entrada no valida, ingrese un entero!\n");
                free(b);
                b=NULL;
            }
        }
        int n_int=atoi(n);
        int b_int=atoi(b);

        if (b_int <= 1)
        {
            printf("El numero no puede ser menor o igual a 1, se genera un bucle infinito ya que no se puede achicar la bomba dividiendo por 1.");
        }
        
        else if (b_int>=n_int){
            printf("La bomba debe ser menor al Numero explosivo.\n");
        }
        else{
            resultado = explosion(n_int, b_int);
        }
        free(n);
        free(b);
        free(resultado);

        printf(".\n.\n.\n.\n>>>> Desea hacer otro intento? SI = 1, NO = 0: ");
        while (scanf("%d", &seguir) != 1 || (seguir != 0 && seguir != 1)) {
            printf("Ingrese 1 para SI o 0 para NO: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        system("cls");
    }
}
