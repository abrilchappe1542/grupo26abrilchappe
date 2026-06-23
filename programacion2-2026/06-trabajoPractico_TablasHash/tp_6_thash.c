#include "tp_thash.h"
#include "menu.h"

static int const TAMANO = 997;


/**
4.  Desarrollar un algoritmo que dado un archivo que contendrá los datos de alumnos  (legajo, apellido, nombres, domicilio, TE) 
    genere una tabla hash donde la clave será el legajo y se guardará como dato la posición física 
    del registro para realizar accesos directos.  
    Hacer un ABM para poder cargar manualmente el archivo.  El “legajo" es un valor de 6 dígitos.
*/

int funcion_hash_mod(int clave){
    return clave % 997;
}

int cargarTabla(TablaHash tabla, FILE* archivo){ //retorna el indice de la ultima posicion a cargar
    Alumnos alumno;
    int contador = 0; //indice inicial
    
    while(fread(&alumno, sizeof(Alumnos), 1, archivo) != 0){
        int* contador2 = malloc(sizeof(int));
        *contador2 = contador;  //actualiza el indice en un puntero para que coincida con los parametros de th_insetar
        th_insertar(tabla, te_crear_con_valor(alumno.legajo, contador2));
        contador++;
    }
    return contador;
}

void cargando_alumno(Alumnos* alumno){
    char *nombre, *apellido, *domicilio, *telefono;
    ingresarString_noEspaciado("\nIngrese el nombre del alumno: ", alumno->nombre,20);
    ingresarString_noEspaciado("\nIngrese el apellido del alumno: ", alumno->apellido,20);
    ingresarString_char_y_numeros("\nIngrese el domicilio del alumno: ", alumno->domicilio,20);
    ingresarEnteros_char("\nIngrese el numero de telefono: ",alumno->TE,15);
    alumno->Estado = true;
}

void alta_alumno(TablaHash tabla, FILE* archivo, int legajo, int* indice){
    TipoElemento te = th_recuperar(tabla, legajo);
    Alumnos alumno;

    if(te != NULL){ //si ya existe legajo, verificar alta o baja
        int contador = *((int*)te->valor);
        if(fseek(archivo, sizeof(Alumnos) * contador, SEEK_SET) != 0){
            printf("Error al posicionar para alta logica\n");
            return;
        }

        fread(&alumno, sizeof(Alumnos), 1, archivo);
        if(alumno.Estado){
            printf("El alumno ya esta dado de alta.\n");
        }
        else
        {
            alumno.Estado = true;
            fseek(archivo, -(long)sizeof(Alumnos), SEEK_CUR); //retrocedo en el archivo

            if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){
                printf("Error al escribir en el archivo\n");
            }
            else{
                printf("Alumno dado de alta nuevamente.\n");
            }
        }
    }
    else
    { // Nuevo alumno
        int* contador2 = malloc(sizeof(int));
        *contador2 = *indice;
        cargando_alumno(&alumno);
        
        alumno.legajo = legajo;
        alumno.Estado = true;
        th_insertar(tabla, te_crear_con_valor(alumno.legajo, contador2));

        if(fseek(archivo, sizeof(Alumnos) * (*indice), SEEK_SET) != 0){
            printf("Error al posicionar para escritura\n");
            free(contador2);
            return;
        }

        if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){
            printf("Error al escribir en el archivo\n");
            free(contador2);
            return;
        }
        (*indice)++;
        printf("Alumno dado de alta correctamente.\n");
    }
}  

void baja_alumno(int clave, TablaHash tabla, FILE* archivo){
    TipoElemento te = th_recuperar(tabla, clave); //buscar el alumno en la tabla
    if(te == NULL){
        printf("No existe un alumno con ese legajo\n");
        return;
    }

    Alumnos alumno;
    int indice = *((int*)te->valor);

    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("Error al posicionarse en el archivo\n");
        return;
    }

    fread(&alumno, sizeof(Alumnos), 1, archivo);   
    if(alumno.Estado){
        alumno.Estado = false;
        fseek(archivo, -(long)sizeof(Alumnos), SEEK_CUR); //retrocede en el archivo

        if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){
            printf("Error al escribir en el archivo\n");
            return;
        }
        printf("\nSe dio de baja al alumno con legajo %d\n", alumno.legajo);
    }
    else{
        printf("\nEl alumno ya estaba dado de baja\n");
    }
}

void buscar_alumno(int indice, FILE* archivo){
    Alumnos alumno;
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("Error al posicionarse en el archivo\n");
        return;
    }

    fread(&alumno, sizeof(Alumnos), 1, archivo);
    if(!alumno.Estado){
        printf("No se encontro el alumno dentro del archivo\n");
        return;
    }

    printf("\n=========== informacion del alumno ===========\n");
    printf("Legajo: %d\n",alumno.legajo);
    printf("Apellido: %s\n",alumno.apellido);
    printf("Nombre: %s\n",alumno.nombre);
    printf("Domicilio: %s\n",alumno.domicilio);
    printf("Telefono: %s\n", alumno.TE);
    printf("\n==============================================\n");
}

void modificar_alumno(int legajo,TablaHash tabla,FILE* archivo){
    Alumnos alumno;
    bool seguir = true;
    int opcion;
    TipoElemento te = th_recuperar(tabla, legajo);

    if(te == NULL){
        printf("No existe un alumno con ese legajo...\n");
        return;
    }

    while(seguir){
        printf("=========== Modificaciones ===========\n");
        printf("Seleccione el campo a modificar\n");
        printf("1. Modificar nombre\n");
        printf("2. Modificar apellido\n");
        printf("3. Modificar telefono\n");
        printf("4. Modificar direccion\n");
        printf("0. Salir\n");
        opcion = ingresoDatosNumericosPositivos("\nEntrada erronea.\n-> ");
        system("cls");
        switch(opcion) {
            case 0:
                seguir = false;
                break;
            case 1:
                modificar_alumno_nombre(archivo, *((int*)te->valor));
                break;
            case 2:
                modificar_alumno_apellido(archivo,*((int*)te->valor));
                break;
            case 3:
                modificar_alumno_telefono(archivo,*((int*)te->valor));
                break;
            case 4:
                modificar_alumno_direccion(archivo,*((int*)te->valor));
                break;
            default:
                printf("AVISO: Ingrese un numero parte de las opciones.\n");
                break;
        }
    }
}

void modificar_alumno_nombre(FILE* archivo, int indice){
    Alumnos alumno;
    char nombre_nuevo[21];
    ingresarString_noEspaciado("Ingrese el nuevo nombre del alumno\n",nombre_nuevo,20);
    
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("Error al posicionarse en el archivo\n");
        return;
    }

    fread(&alumno, sizeof(Alumnos), 1, archivo);
    strcpy(alumno.nombre, nombre_nuevo); //copio el nuevo telefono

    fseek(archivo, -(long)sizeof(Alumnos), SEEK_CUR); //retrocede en el archivo
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("Error al escribir en el archivo\n");
        return;
    }
    printf("Ahora el nombre del alumno es %s\n", alumno.nombre);
    system("pause");
}

void modificar_alumno_apellido(FILE* archivo, int indice){
    Alumnos alumno;
    char apellido_nuevo[21];
    ingresarString_noEspaciado("Ingrese el nuevo apellido del alumno\n",apellido_nuevo,20);
    
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("Error al posicionarse en el archivo\n");
        return;
    }

    fread(&alumno, sizeof(Alumnos), 1, archivo);
    strcpy(alumno.apellido, apellido_nuevo); //copio el nuevo telefono

    fseek(archivo, -(long)sizeof(Alumnos),SEEK_CUR); //retrocede en el archivo
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("Error al escribir en el archivo\n");
        return;
    }
    printf("Ahora el apellido del alumno es %s\n", alumno.apellido);
    system("pause");
}

void modificar_alumno_direccion(FILE* archivo, int indice){
    Alumnos alumno;
    char domicilio_nuevo[21];
    ingresarString_char_y_numeros("Ingrese la nueva direccion del alumno\n",domicilio_nuevo,20);
    
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("Error al posicionarse en el archivo\n");
        return;
    }

    fread(&alumno, sizeof(Alumnos), 1, archivo);
    strcpy(alumno.domicilio, domicilio_nuevo); //copio la nueva direccion

    fseek(archivo, -(long)sizeof(Alumnos),SEEK_CUR);  //retrocede en el archivo, dejandolo en la posicion que lo leyo antes 
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("Error al escribir en el archivo\n");
        return;
    }
    printf("Ahora el domicilio del alumno es %s\n", alumno.domicilio);
    system("pause");
}

void modificar_alumno_telefono(FILE* archivo, int indice){
    Alumnos alumno;
    char telefono_nuevo[16];
    ingresarEnteros_char("Ingrese el nuevo telefono del alumno\n",telefono_nuevo,15);
    
    if(fseek(archivo, sizeof(Alumnos) * indice, SEEK_SET) != 0){
        printf("Error al posicionarse en el archivo\n");
        return;
    }

    fread(&alumno, sizeof(Alumnos), 1, archivo);
    strcpy(alumno.TE, telefono_nuevo); //copio el nuevo telefono

    fseek(archivo, -(long)sizeof(Alumnos),SEEK_CUR); //retrocede en el archivo 
    if(fwrite(&alumno, sizeof(Alumnos), 1, archivo) != 1){ //escribre el archivo
        printf("Error al escribir en el archivo\n");
        return;
    }
    else
    {
        printf("Ahora el telefono del alumno es %s\n", alumno.TE);
    }
}

void carga_archivo(Alumnos* alumno){
    int clave = funcion_hash_mod(alumno->legajo);
    alumno->Estado=true;
    FILE* archivo=fopen("Alumnos.dat","rb+"); //abre el archivo, lo crea en caso de que no exista
    fseek(archivo,clave * sizeof(alumno),SEEK_SET); //pos 0, hasta la pos de la clave
    fwrite(alumno,sizeof(alumno),1,archivo);    //escribe la linea
    fclose(archivo);
}

void mostrar_alumnos_activos(TablaHash tabla, FILE* archivo) {
    printf("\n=========== Alumnos Activos ===========\n");
    for (int i=0; i<TAMANO; i++) {
        TipoElemento te = th_recuperar(tabla,i);
        if(te != NULL){
            int pos = *((int*)te->valor);
            Alumnos alumno;
            if (fseek(archivo, sizeof(Alumnos) * pos, SEEK_SET) == 0 &&
                fread(&alumno, sizeof(Alumnos), 1, archivo) == 1){
                if(alumno.Estado){
                    printf("Legajo: %d\n",alumno.legajo);
                    printf("Apellido: %s\n", alumno.apellido);
                    printf("Nombre: %s\n", alumno.nombre);
                    printf("Domicilio: %s\n", alumno.domicilio);
                    printf("Telefono: %s\n", alumno.TE);
                    printf("\n\n");
                }
            }
        }
    }
    printf("\n=======================================\n");
}

void th_ej4_abm(){
    menuPunto4();
}


/**
5.  Realizar una comparación de los tiempos de accesos a las claves entre un árbol AVL y una Tabla Hash. 
    El operador debe poder indicarle cuantas claves se deben generar (entre 1 y 2000), cuantas repeticiones 
    se realizaran y cuál es el rango de las claves a generar.   
    Luego se tomarán claves al azar dentro del mismo rango y se buscaran en ambas estructuras.  
    El proceso se repetirá “n” veces (repeticiones a ingresar por el operador).  
    Documentar la conclusión final respecto a los tiempos de accesos de ambas estructuras. 
*/

int funcion_hash_mod2003(int clave){
    return clave % 2003;
}

int cargarHashAVL(int q_claves, int rango_desde, int rango_hasta, ArbolAVL arvl, TablaHash thash){
    if ((rango_hasta - rango_desde + 1) < q_claves){
        printf("El rango es demasiado pequeño para la cantidad de claves...\n");
        return 0;
    }
    int i = 0;
    while(i < q_claves){
        int random = rand() % (rango_hasta - rango_desde + 1) + rango_desde;
        if(avl_buscar(arvl, random) == NULL){ 
            avl_insertar(arvl, te_crear(random));
            th_insertar(thash, te_crear(random));
            i++;
        }
    }
    return i;
}

void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta){
    int opcion;
    double totalavl = 0, totalhash = 0;
    clock_t inicioavl, iniciohash, finavl, finhash;

    double* tiempo_avl = (double*)malloc(sizeof(double) * q_repeticiones);
    double* hash_tiempo = (double*)malloc(sizeof(double) * q_repeticiones);
    //Arreglos para almacenar el tiempo usado de las estructuras en cada repetición

    ArbolAVL arvl = avl_crear();// --------> CREO ARBOL AVL
    TablaHash thash = th_crear(2003, funcion_hash_mod2003);// --------> CREO TABLA HASH

    int claves_cargadas = cargarHashAVL(q_claves, rango_desde, rango_hasta, arvl, thash);
    //función que carga tanto el avl como la hash con las mismas claves aleatorias

    printf("\nClaves cargadas: %d\n", claves_cargadas);
    printf("\n\n");  
    //pregunta morstar
    
    printf("\n\nDesea ver el arbol y tabla hash generada? 1: SI | 0: NO\n\n");
    opcion = ingresoIntLimitado("Ingrese un valor adecuado!", 0, 1);
    system("cls");

    if(opcion == 1){
    a_mostrar_normal((ArbolBinario) arvl);
    printf("\n\n");
    th_mostrar(thash);
}
    

    printf("Cuantas claves desea buscar?\n-> ");
    int cant_claves = ingresoIntMinimo("Ingrese un valor adecuado!", 1);

    // Se crea urreglo de claves aleatorias a buscar, para que ambas estructuras busquen las mismas claves
    int* claves_busqueda = (int*)malloc(sizeof(int) * cant_claves);
    for (int i = 0; i < cant_claves; i++) {
        claves_busqueda[i] = rand() % (rango_hasta - rango_desde + 1) + rango_desde;
    }

    for(int j = 0; j < q_repeticiones; j++){
        /* -------------------------------------------------------------------------------*/
        /* ACLARACION: La función clock mide el tiempo de CPU utilizado por el programa.  */
        /*--------------------------------------------------------------------------------*/

        /*-------------------*/
        /*     ARBOL AVL     */
        /*-------------------*/
        inicioavl = clock(); // inicio contador de tiempo del arbol avl
        for(int i = 0; i < cant_claves; i++) {
            avl_buscar(arvl, claves_busqueda[i]);
        }
        finavl = clock(); // finalizo
        double *tiempousadoavl = (double*)malloc(sizeof(double));
        *tiempousadoavl = (double)(finavl - inicioavl) / CLOCKS_PER_SEC;
        totalavl += *tiempousadoavl;
        tiempo_avl[j] = *tiempousadoavl;

        // -------------------
        //    TABLA HASH
        // -------------------
        iniciohash = clock(); // inicio contador de tiempo de la tabla hash
        for(int i = 0; i < cant_claves; i++) {
            th_recuperar(thash, claves_busqueda[i]);
        }
        finhash = clock(); // finalizo
        double *tiempousadohash = (double*)malloc(sizeof(double));
        *tiempousadohash = (double)(finhash - iniciohash) / CLOCKS_PER_SEC;
        totalhash += *tiempousadohash;
        hash_tiempo[j] = *tiempousadohash;
    }
    free(claves_busqueda);

    printf("\n\nLISTADO DE TIEMPOS DE BUSQUEDA DEL ARBOL AVL POR CADA REPETICION:\n");
    for(int i = 0; i<q_repeticiones; i++){
        double tiempo1 = tiempo_avl[i];
        printf("%f ", tiempo1);
    }

    printf("\n\nLISTADO DE TIEMPOS DE BUSQUEDA DE LA TABLA HASH POR CADA REPETICION:\n");
    for(int i = 0; i<q_repeticiones; i++){
        double tiempo2 = hash_tiempo[i];
        printf("%f ", tiempo2);
    }

    printf("\n\n");
    printf("\nTiempo promedio AVL: %f segundos\n", totalavl / q_repeticiones);
    printf("Tiempo total AVL: %f segundos\n", totalavl);
    printf("\nTiempo promedio Hash: %f segundos\n", totalhash / q_repeticiones);
    printf("Tiempo total Hash: %f segundos\n", totalhash);

    printf("\n\n====== CONCLUSION ======\n\n");
    printf("Luego de muchas pruebas con distintos rangos de repeticiones para ambas implementaciones,\n");
    printf("se evidencio que la TABLA HASH con lista de colisiones tenia tiempos de acceso mas eficaces a comparacion que los del arbolAVL.\n");
    printf("sin embargo, en la implementacion de zona de overflow, sucedia lo contrario, el ArbolAVL fue mas eficaz que la tabla hash.");
    // lista_colisiones = tablas hash + rapido
    // zona overflow = arbol avl + rapido
    free(tiempo_avl);
    free(hash_tiempo);
}


/**
6.  Se desea poder implementar una solución para encontrar de forma rápida los datos de las personas que a una fecha
    determinada se presentaron a vacunar contra el COVID.  
    Es decir dada una fecha determinada debería obtener quienes se vacunaron. 
    De cada persona se guarda básicamente el DNI, Apellido y Nombre.  
    Se debe además hacer una pantalla de carga donde se pueda especificar la fecha y los datos de las personas 
    que se vacunaron en esa fecha. 
*/
int ingresando_fecha(){
    int dia, mes, anio;
    printf("\nIngrese la fecha en formato aaaammdd (primero el anio, luego el mes, luego el dia)");

    printf("\nAnio [2020-2025]: ");
    anio = ingresoIntLimitado("Ingrese un anio adecuado! Que sea desde el covid y no exceda el presente", 2020, 2025);

    printf("\nMes [1-12]: ");
    mes = ingresoIntLimitado("Ingrese un mes adecuado!", 1, 12);

    if(mes == 2 && anio != 2024)
    { //si es febrero no bisiesto
        printf("\nDia [1-28]: ");
        dia = ingresoIntLimitado("Ingrese un dia adecuado!", 1, 28);
    }
    else if(mes == 2 && anio == 2024)
    { //si es febrero bisiesto
        printf("\nDia [1-29]: ");
        dia = ingresoIntLimitado("Ingrese un dia adecuado!", 1, 29);
    }
    else if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
    { //si es mes de 30 dias
        printf("\nDia [1-30]: ");
        dia = ingresoIntLimitado("Ingrese un dia adecuado!", 1, 30);
    }
    else
    { //si es mes de 31 dias
        printf("\nDia [1-31]: ");
        dia = ingresoIntLimitado("Ingrese un dia adecuado!", 1, 31);
    }

    int fecha = dia*1000000 + mes*10000 + anio;
    return fecha;
}

int ingresando_dni(){
    int dni_num;
    printf("\nIngrese el DNI de la persona: ");
    dni_num = ingresoIntLimitado("Ingrese un DNI adecuado!", 1000000, 99999999); //DNI 8 digitos
    return dni_num;
}

void ingresando_vacunado(FichaVacunados *ficha){
    char *nombre = (char*)malloc(21 * sizeof(char));
    char *apellido = (char*)malloc(21 * sizeof(char));
    int dni_num;
    
    ingresarString_noEspaciado("\nIngrese el nuevo nombre del vacunado: ",nombre,20);
    ingresarString_noEspaciado("\nIngrese el apellido de la persona: ", apellido ,20);
    printf("\nIngrese el DNI de la persona: ");
    dni_num = ingresoIntLimitado("Ingrese un DNI adecuado!", 1000000, 99999999);

    strcpy(ficha->nombre,nombre);
    strcpy(ficha->apellido,apellido);
    ficha->DNI = dni_num;
}

void cargar_vacunados(TablaHash tabla){
    ArbolAVL avl;
    FichaVacunados *ficha = (FichaVacunados*)malloc(sizeof(FichaVacunados));;
    TipoElemento te;

    ficha->fecha = ingresando_fecha();
    ingresando_vacunado(ficha);
    te = th_recuperar(tabla, ficha->fecha);
    
    if(te != NULL){ //si se encuentra en la tabla
        avl = (ArbolAVL)(te->valor);
        if(avl_buscar(avl, ficha->DNI) == NULL){ //si no existe el dni en determinada fecha
            avl_insertar(avl, te_crear_con_valor(ficha->DNI,ficha));    
            printf("\nLa persona se cargo correctamente y habian otras personas vacunadas en la misma fecha\n");
        }
        else
        {
            printf("\nLa persona ya se encontraba cargada en la misma fecha\n");
            printf("Vuelva a intentarlo\n");
            free(ficha); //libero la memoria de ficha
        }
    }
    else
    { //caso contrario
        avl = avl_crear(); //creo el arbol avl para determinada fecha
        avl_insertar(avl, te_crear_con_valor(ficha->DNI, ficha));
        th_insertar(tabla, te_crear_con_valor(ficha->fecha, avl)); // nueva fecha en la tabla
        printf("\nLa persona se cargo correctamente y fue la primera cargada en esta fecha\n");
    }
}

void eliminar_vacunados(TablaHash tabla){
    int fecha = ingresando_fecha();
    TipoElemento te = th_recuperar(tabla, fecha); //recupero el arbol de la fecha

    if(te != NULL){ //si el arbol se encuentra en la tabla
        ArbolAVL avl = (ArbolAVL)(te->valor);
        int dni = ingresando_dni();
        TipoElemento te2 = avl_buscar(avl, dni); //recupero el nodo con el dni ingresado

        if(te2 == NULL){
            printf("\nNo hubo personas vacunadas en dicha fecha con dicho DNI\n");
        }
        else
        {
            if(!avl_eliminar(avl, dni)){ //si no se pudo eliminar
                printf("Hubo un error al eliminar la ficha de la persona\n");
            }
            else
            { //si se pudo eliminar
                printf("\nLa persona fue eliminada con exito\n");
                if(avl_es_vacio(avl)){
                    th_eliminar(tabla, fecha);
                }
            }
        }
    }
    else
    { //si el arbol no se encuentra en la tabla
        printf("No hubo personas vacunadas en dicha fecha\nPor favor vuelva a intentarlo\n");
    }
}

void modificar_vacunados(TablaHash tabla){
    int fecha = ingresando_fecha();
    TipoElemento te = th_recuperar(tabla, fecha); //recupero el arbol de la fecha

    if(te != NULL){ //si el arbol se encuentra en la tabla
        ArbolAVL avl = (ArbolAVL)(te->valor);
        int dni = ingresando_dni();
        TipoElemento te2 = avl_buscar(avl, dni); //recupero el nodo con el dni ingresado

        if(te2 == NULL){
            printf("No hubo personas vacunadas en dicha fecha con dicho DNI\n");
        }
        else
        {
            if(!avl_eliminar(avl, dni)){ //si no se pudo eliminar
                printf("Hubo un error al modificar la ficha de la persona\n");
            }
            else
            { //si se pudo eliminar
                FichaVacunados *ficha = (FichaVacunados*)malloc(sizeof(FichaVacunados));
                ficha->fecha = fecha;

                printf("\nIngrese los nuevos datos de la persona\n");
                ingresando_vacunado(ficha);
                avl_insertar(avl, te_crear_con_valor(ficha->DNI, ficha));
                printf("\nDatos modificados con exito!\n");
            }
        }
    }
    else //si el arbol no se encuentra en la tabla
    {
        printf("No hubo personas vacunadas en dicha fecha\nPor favor vuelva a intentarlo\n");
    }
}

void mostrar_vacunados(TablaHash tabla){
    ArbolAVL avl;
    NodoArbol raiz;
    int fecha = ingresando_fecha();
    TipoElemento te = th_recuperar(tabla, fecha); //recupero los datos de la fecha ingresada

    if(te != NULL){
        avl = (ArbolAVL)(te->valor);
        raiz = avl_raiz(avl);
        if(avl_es_vacio(avl)){
            printf("\nNo se encontraron resultados para la fecha ingresada\n");
        }
        else{
            imprimir_listado_vacunados(raiz);
        }
        
    }
    else
    {
        printf("\nNo se encontraron resultados para la fecha ingresada\n");
    }
}

void imprimir_listado_vacunados(NodoArbol nodo){
    if(a_es_rama_nula(nodo)){
        return; //caso base
    }

    TipoElemento te = n_recuperar(nodo);
    FichaVacunados *ficha = (FichaVacunados*)(te->valor);
    printf("\n=========== Vacunado ===========\n");
    printf("Apellido: %s\n",ficha->apellido);
    printf("nombre:   %s\n",ficha->nombre);
    printf("DNI:      %d\n",ficha->DNI);
    
    imprimir_listado_vacunados(n_hijoizquierdo(nodo));
    imprimir_listado_vacunados(n_hijoderecho(nodo));
}

int th_ej6_covid(){
    menuPunto6_v2();
    return 0;
}
