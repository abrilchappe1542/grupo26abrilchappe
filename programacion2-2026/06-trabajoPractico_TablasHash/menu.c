#include "menu.h"
#include "tp_thash.h"
static int const TAMANO = 997;

void menuPunto4(){
    int opcion, indice, legajo;
    bool seguir = true;
    TipoElemento te;

    TablaHash tabla = th_crear(TAMANO, &funcion_hash_mod);
    FILE* archivo = fopen("Alumnos.dat","r+b"); //Abre o crea un archivo binario para lectura / escritura
    
    if(archivo == NULL){
        archivo = fopen("Alumnos.dat", "w+b");  //Crea un archivo binario para lectura / escritura
        fclose(archivo);
        archivo = fopen("Alumnos.dat","r+b");
    }
    indice = cargarTabla(tabla, archivo);

    while(seguir){
        printf("\n=== MENU DE PUNTO 4 ===\n");
        printf("1. Dar de alta un alumno\n");
        printf("2. Dar de baja un alumno\n");
        printf("3. Modificar datos de un alumno\n");
        printf("4. Buscar un alumno\n");
        printf("5. Mostrar alumnos\n");
        printf("6. Mostrar tabla hash \n");
        printf("0. Salir \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 6);
        system("cls");

        switch (opcion){    
            case 0:
                printf("Seguro que desea salir? (1-Si / 0-No)\n");
                seguir = !preguntarContinuar();   
                break;
            case 1:
                legajo = ingresando_Legajo_alumno();
                alta_alumno(tabla, archivo, legajo, &indice);
                printf("\n\n");
                break;
            case 2:
                legajo = ingresando_Legajo_alumno();
                te = th_recuperar(tabla,legajo);
                if(te != NULL){ //VERIFICAR QUE EL LEGAJO SE ENCUENTRE EN LA TABLA
                    //SI ESTA, DAR DE BAJA DE LA TABLA
                    baja_alumno(te->clave, tabla, archivo);
                }
                else{
                    printf("\nEl alumno no se encuentra dentro del archivo\n");
                }
                printf("\n\n");
                break;
            case 3:
                legajo = ingresando_Legajo_alumno();
                te = th_recuperar(tabla,legajo);
                if(te != NULL){ //VERIFICAR QUE EL LEGAJO SE ENCUENTRE EN LA TABLA
                    modificar_alumno(te->clave, tabla, archivo);
                }
                else{
                    printf("\nEl legajo no pertenece a un alumno\n");
                }
                printf("\n\n");
                break;
            case 4:
                legajo = ingresando_Legajo_alumno();
                te = th_recuperar(tabla,legajo);
                if(te != NULL){ //VERIFICAR QUE EL LEGAJO SE ENCUENTRE EN LA TABLA
                    buscar_alumno(*(int*)te->valor, archivo);
                }
                else{
                    printf("\nEl legajo no pertenece a un alumno\n");
                }
                printf("\n\n");
                break;
            case 5:
                mostrar_alumnos_activos(tabla, archivo);
                break;
            case 6:
                printf("\n=== ESTRUCTURA INTERNA DE LA TABLA HASH DE ALUMNOS ===\n");
                th_mostrar(tabla);
                break;
            default:
                printf("AVISO: Ingrese un numero parte de las opciones.\n");
                break;
        }
        printf("\n\n");
        system("pause");
        system("cls");
    }
    fclose(archivo);
}

void menuPunto5(){
    int opcion, clave, cant_nodo;
    int cant_claves, cant_rep, min, max;    
    bool seguir = true;

    while (seguir == 1){
        printf("\n=== MENU DE PUNTO 5 ===\n");
    
        printf("Ingrese la cantidad de claves a generar (1-2000): ");//preguntar cuantas claves (entre 1 y 2000)
        cant_claves = ingresoIntLimitado("Ingrese un valor adecuado!", 1, 2000);

        printf("\nIngrese el valor minimo para generar claves\n-> ");//rango minimo
        min = ingresoDatosNumericosPositivos("Ingrese un valor adecuado!");

        printf("\nIngrese el valor maximo para generar claves a partir de %d : \n-> ",(min + (cant_claves-1)));//rango maximo
        max = ingresoIntMinimo("Ingrese un valor adecuado!", (min + (cant_claves-1)));

        printf("\nIngrese la cantidad de repeticiones a realizar: ");//cuantas repeticiones
        cant_rep = ingresoDatosNumericosNoCero("Ingrese un valor adecuado!");
                    
        th_ej5_comparacion(cant_claves, cant_rep, min, max);
            
        seguir = preguntarContinuar();
        printf("\n\n");
        system("pause");
        system("cls");    
    }
}


void menuPunto6_v2(){
    TablaHash tabla = th_crear(TAMANO, &funcion_hash_mod);
    int opcion;
    bool seguir = true;

    while (seguir == 1){
        printf("\n=== MENU DE PUNTO 6 ===\n");
        printf("1. Cargar persona en ficha de vacunacion\n");
        printf("2. Eliminar persona de ficha de vacunacion. datos necesario: fecha y dni\n");
        printf("3. Modificar datos de una persona de vacunacion por fecha. datos necesario: fecha y dni\n");
        printf("4. Mostrar ficha de vacunacion por fecha\n");
        printf("5. Mostrar tabla hash \n");
        printf("0. Salir \n");
        printf("> Seleccione una opcion: ");
        opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 5);
        system("cls");

        switch (opcion){
            case 0:
                printf("Seguro que desea salir?");
                seguir = !preguntarContinuar();   
                break;
            case 1:
                cargar_vacunados(tabla);
                break;
            case 2:
                eliminar_vacunados(tabla);
                break;
            case 3:
                modificar_vacunados(tabla);
                break;
            case 4: 
                mostrar_vacunados(tabla);
                break;
            case 5:
                printf("\n=== ESTRUCTURA INTERNA DE LA TABLA HASH DE VACUNADOS ===\n");
                th_mostrar(tabla);
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