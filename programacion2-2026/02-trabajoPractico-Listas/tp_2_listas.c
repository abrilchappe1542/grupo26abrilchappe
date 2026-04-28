#include "tp_2_listas.h"
//EJERCICIO 2
// PUNTO A Y B
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2)
{
    Lista resultado = l_crear(); //lista para los resultados
    Iterador it = iterador(l1); //para recorrer la lista
    while (hay_siguiente(it))
    {
        TipoElemento elem = siguiente(it);
        if (l_buscar (l2, elem->clave) == NULL) //para ver si no se repiten
        {
            l_agregar(resultado, te_crear(elem->clave));  //si no se repiten lo agrego en la lista nueva
        }
    }
    return resultado;
}
// PUNTO C
Lista verElementosRepetidos(Lista l1, Lista l2)
{
    Lista resultado = l_crear(); //lista para los resultados
    Iterador it = iterador(l1);

    while(hay_siguiente(it)) //mientras haya elementos en la lista sigo en el bucle
    {
        TipoElemento elem = siguiente(it);
        if(l_buscar(l2, elem->clave) != NULL) //para ver si esta en la lista l2
        {
            if(l_buscar(resultado, elem->clave) == NULL) //compruebo si no lo habia agregado anteriormente
            {
                l_agregar(resultado, te_crear(elem->clave));
            }
        }
    }
    return resultado;
}

//PUNTO D
float promedio(Lista l)
{
    if (l_es_vacia(l))
    {
        return 0.0;  //si no hay nada en la lista devuelve 0
    }
    float suma = 0;     
    float cantidad = 0;
    Iterador it = iterador(l);  //posicionamos el iterador
    while (hay_siguiente(it))  //recorremos
    {
        TipoElemento elem = siguiente(it);  
        suma += elem->clave;  // Sumamos los valores de la lista
        cantidad ++;           //vamos acumulando la cantidad de valores
    }
    return suma/cantidad;
}

// PUNTO E
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2)
{
    ResultadoValorMinimo res;
    TipoElemento elem, elem2;    
    
    res.valor = l_recuperar(l1,1)->clave;     
    res.pos = 1;
    res.valor_2 = l_recuperar(l2,1)->clave;
    res.pos_2 = 1;

    Iterador it1 = iterador(l1);  //nos ponemos en el primer elemento de la lista 1
    int pos_actual = 1;
    while(hay_siguiente(it1))
    {
        elem = siguiente(it1);
        if(elem->clave < res.valor)  //vamos buscando el elemento menor con el if
        {
            res.valor = elem->clave;        //si encontramos un menor, lo guardamos en el struct
            res.pos = pos_actual;   //guardamos la posicion en la que fue encontrado
        }
        pos_actual++;
    }
    Iterador it2 = iterador(l2);        //buscamos en la lista 2 ahora
    pos_actual = 1;                 //reseteamos la pos actual
    while(hay_siguiente(it2))       
    {
        elem2 = siguiente(it2);
        if(elem2->clave < res.valor_2)     //buscamos el menor de la lista 2
        {
            res.valor_2 = elem2->clave;    //si encontramos lo guardamos en el struct
            res.pos_2 = pos_actual;
        }
        pos_actual++;
    }
    return res;
}



//ejercicio 3:
ResultadosMul multiplo(Lista l1, Lista l2){
    TipoElemento nodo1 = l_recuperar(l1,1), nodo2 = l_recuperar(l2,1);
    int x=nodo2->clave/nodo1->clave;
    ResultadosMul multiplo_resultado = { .esMultiplo = true, .escalar = true, .numEscalar = x };
    Iterador ite =iterador(l1), ite2 =iterador(l2);
    while(hay_siguiente(ite)){
        nodo1=siguiente(ite);
        nodo2=siguiente(ite2);
        if ((nodo2->clave%nodo1->clave) != 0){
            multiplo_resultado.esMultiplo = false, multiplo_resultado.escalar = false, multiplo_resultado.numEscalar = 0;
            return multiplo_resultado;
        }
        if (nodo2->clave/nodo1->clave != x){
            multiplo_resultado.escalar = false;
        }
    }
    return multiplo_resultado;
}

//ejercicio 4:
int CompararListas(Lista l1, Lista l2){
    int contador_l1 = 0;
    int contador_l2 = 0;                 //contadores
    int contador_iguales = 0; 

    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    TipoElemento nodo1;
    TipoElemento nodo2;

    while (hay_siguiente(ite1) && hay_siguiente(ite2)){
        nodo1 = siguiente(ite1);
        nodo2 = siguiente(ite2);
        
        if (nodo1->clave > nodo2->clave){
            contador_l1++;
        } 
        else if (nodo1->clave < nodo2->clave){   //comparaciones
            contador_l2++; 
        }
        else if (nodo1->clave == nodo2->clave){
            contador_iguales++;
        }
    }
    if (contador_l1 > contador_l2){
        printf("L1 > L2\n");
    } 
    else if (contador_l2 > contador_l1){     //resultados
        printf("L1 < L2\n");
    } 
    else if (contador_l1 == contador_l2){
        printf("L1 = L2\n");
    }
}

//Ejercicio 5
void hacerPolinomio(Lista list){
   int cantidad;
    printf("Ingrese la cantidad de elementos a cargar en las listas\n-> ");
    cantidad = ingresoDatosNumericosNoCero("Ingrese un numero valido!\n");
    printf("\nCargamos lista\n");
    int num, guia = 0;
    float * coeficiente;
    TipoElemento nodo;

    while(!l_es_llena(list) && guia<cantidad){
        printf("  | EXPONENTES %d | ->\t", guia+1);
        num = ingresoDatosNumericosPositivos("Ingrese un exponente entero positivo!\n");
        coeficiente = malloc(sizeof(float));
        printf ("  | COEFICIENTES %d |->\t", guia+1);
        * coeficiente = ingresoDatosFloat("Ingrese un coeficiente valido!\n");
        nodo = te_crear_con_valor(num, coeficiente);
        l_agregar(list, nodo);
        guia++;
    }
}


float evaluarPolinomio(Lista list, float x ){
    Iterador i1 = iterador(list);
    Iterador i2 = iterador(list);
    float valor;
    float sumando;
    sumando = 0;
    while (hay_siguiente(i1)){
        valor = *(float*)siguiente(i2)->valor * pow(x,siguiente(i1)->clave);
        sumando += valor;}
    return sumando;
}

Lista calcularRango(Lista list, double x, double y, double sumando){
    Lista listaRango = l_crear();
    double i = x;
    int c = 0;
    while (i<=y && !l_es_llena(listaRango)){
        c+=1;
        float resultado = evaluarPolinomio(list, i);
        float* valor = malloc(sizeof(float));
        *valor = resultado;
        TipoElemento elem = te_crear_con_valor(c, valor);
        l_agregar(listaRango, elem);
        i+=sumando;
    }
    return listaRango;
}

bool esSublista(Lista l1, Lista l2){
    Iterador iterr1 = iterador(l1);
    Iterador iterr2 = iterador(l2);
    TipoElemento nodo1;
    TipoElemento nodo2;
    bool encontrado = false;

    while(hay_siguiente(iterr2)){
        nodo2 = siguiente(iterr2);
        iterr1 = iterador(l1);
        encontrado = false;
        while(hay_siguiente(iterr1)){
            nodo1 = siguiente(iterr1);
            if(nodo2->clave == nodo1->clave){
                encontrado = true;
                break;
            }
        }
        if(encontrado == false){
            return false;
        }
    }
    return encontrado;
}
