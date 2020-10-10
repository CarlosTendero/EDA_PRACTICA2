
/* Descripcion: Curso 2017-2018. Asignatura: Estructuras de datos y algoritmos. Practica 2. Solucion a la parte 2 de dicha practica.
 * Autor:   Victor Otero
 *          Carlos Tendero
 */


/* LIBRERIAS ESTANDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
#include <time.h>


/* ZONA DE DECLARACION DE CONSTANTES*/


#define CORRECTO 0
#define ERR_PILA_VACIA 1
#define ERR_MEMORIA 2
#define MIN 0
#define MAX 20.0
#define POBLAR_PILA 1
#define EXTRAER_ELEMENTOS_PILA 2
#define SALIR 3

/* ZONA DE DECLARACION DE TIPOS*/

typedef enum {
    FALSE, TRUE
} tBoolean;

typedef struct _pnodo {
    float Elem; /* Variable para almacenar un elemento de la pila. */
    struct _pnodo *Sig;
    /* Puntero al siguiente nodo que contiene un elemento. */
} tNodo;
/* Tipo nodo. Cada nodo contiene un elemento de la pila. */

typedef tNodo tPila;

/* ZONA DE DECLARACION DE PROTOTIPOS DE FUNCIONES */

/* Funcion: AsignarMemoria
 * Devuelve memoria apara un puntero a *tPila.
 * Parametros de entrada: 
 * no tiene 
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Memoria para un puntero a *tPila. Valor devuelto por la funcion.
 */
tPila **AsignarMemoria(void);

/* Funcion: Apilar
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Elemento anyadir a la pila.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Pila. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Apilar(tPila **p, float E);

/* Funcion: Desapilar
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Elemento anyadir a la pila.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Pila. Valor devuelto por referencia.
 * Elemento desapilado. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Desapilar(tPila **p, float *E);

/* Funcion: VerPila
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Pila
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * no tiene               
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int VerPila(tPila *p);

/* Funcion: LlenarPila
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Numero de elementos a incluir.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Pila. Valor devuelto por referencia.              
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int LlenarPila(tPila **p, int N);

/* Funcion: Menu
 * Devuelve la opcion de menu escogida.
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Opcion de menu escogida. Valor devuelto por la funcion.
 */
int Menu(void);

/* Funcion: Sumar
 * Extrae de la pila un numero de elementos, y devuelve su suma. Tambien 
 * devuelve el resultado de la operacion.
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Suma. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */

int Sumar(tPila **p, int N, float *Sum);

/* PROGRAMA PRINCIPAL */

int main() {

    int Resultado, Opcion, NumElem;
    tPila **pPila = NULL;
    float Suma;
    tBoolean FlgSalir;

    int i = 0; /*vatiable auxiliar*/
    float Elemento = 0.00; /*variable auxiliar*/

    pPila = AsignarMemoria();
    FlgSalir = FALSE;
    while (!FlgSalir) {
        Opcion = Menu();
        switch (Opcion) {
            case POBLAR_PILA: /* 1.	Llenar pila. */
                /*Puebla la pila con 20 números reales generados aleatoriamente en el intervalo [0, 20]. 
                 * Una vez poblada la pila, se escribe en la salida estándar el valor de los elementos de la pila. */

                LlenarPila(pPila, 20);
                /*Se muestra la pila*/
                VerPila(*pPila);
                break;

            case EXTRAER_ELEMENTOS_PILA: /* 2.Sumar elementos pila. */
                /*El programa solicitará al usuario el número de elementos a extraer de la pila, 
                 * mostrará por pantalla el contenido de la pila y la suma de los elementos extraídos. 
                 * Si  se solicita extraer más elementos que los contenidos en la pila, 
                 * hse extraerán todos los posibles.*/
                
                
                if (*pPila == NULL) /*control de errores*/
                    printf("\nNo hay elementos en la pila");
                else {
                    printf("\nCuantos elementos desea extraer ?");
                    scanf("%f", &Elemento);
                    while (Elemento < 1) {
                        printf("\nValor no valido, pruebe con un valor mayor que 1");
                        scanf("%f", &Elemento);
                    }
                    Sumar(pPila, Elemento, &Suma);
                    printf("\nSuma de los elementos extraidos:\t%.f\n", Suma);
                    Suma = 0;   /*para que solo se muestre la suma en los elementos que se piden 
                                 * a extraer*/
                     VerPila(*pPila);
                }
                break;

            case SALIR: /* 3.	Salir */
                FlgSalir = TRUE;
                break;

            default:
                printf("Opcion no valida\n");
        }

    }
    if ((*pPila) != NULL)       /*control de errores*/
        free(*pPila);
    free(pPila);
    return 0;
}

/* Funcion: AsignarMemoria
 * Devuelve memoria apara un puntero a *tPila.
 * Parametros de entrada: 
 * no tiene 
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Memoria para un puntero a *tPila. Valor devuelto por la funcion.
 */
tPila **AsignarMemoria(void) {

    tPila **pila_aux = NULL;

    pila_aux = (tPila**) malloc(sizeof (tPila*)); /*memoria doble puntero*/

    /*control de errores*/
    if (pila_aux == NULL)
        return NULL;

    *(pila_aux) = NULL; /*contenido de la pila*/

    return pila_aux;
}

/* Funcion: Apilar
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Elemento anyadir a la pila.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Pila. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Apilar(tPila **p, float E) {

    tNodo *nodo_aux = NULL;
    int resultado = 0;

    nodo_aux = (tNodo*) malloc(sizeof (tNodo));

    if (nodo_aux == NULL) /*control de errores*/
        resultado = -1;
    else {
        nodo_aux->Elem = E;
        if (*p == NULL) /*si no hay elementos*/
            nodo_aux->Sig = NULL;
        else /*si hay elementos*/
            nodo_aux->Sig = *p;
        *p = nodo_aux;
        resultado = 1; /*correcto*/
    }
    return resultado;
}

/* Funcion: Desapilar
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Elemento anyadir a la pila.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Pila. Valor devuelto por referencia.
 * Elemento desapilado. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Desapilar(tPila **p, float *E) {

    tNodo* nodo_aux = NULL;
    int resultado = 0;

    if (*p == NULL) /*control de errores*/
        resultado = -1;

    else {
        nodo_aux = *p;
        *E = (*p)->Elem;    /*recojo elemento*/
        *p = (*p)->Sig;
        free(nodo_aux);     /*libero meo¡memoria*/
    }
    return resultado;
}

/* Funcion: VerPila
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Pila
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * no tiene               
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int VerPila(tPila *p) {

  tPila* aux;       /*variable auxiliar*/

  aux = p;
  while (aux != NULL)
 {
   printf("%.f\n", aux->Elem);
   aux = aux->Sig;
 } 
  
    return TRUE;

}

/* Funcion: LlenarPila
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Numero de elementos a incluir.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Pila. Valor devuelto por referencia.              
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int LlenarPila(tPila **p, int N) {

    int resultado = 0;
    int i = 0;
    /*control de errores*/
    if (p == NULL || N < 0)
        resultado = -1;
    else {
        for (i = 0; i < N; i++)
            Apilar(p, rand() % 21); /*introduzco elementos*/
        resultado = 1;
    }
    return resultado;
}

/* Funcion: Sumar
 * Extrae de la pila un numero de elementos, y devuelve su suma. Tambien 
 * devuelve el resultado de la operacion.
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Suma. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Sumar(tPila **p, int N, float *Sum) {

    int i = 0;
    int resultado = 0;
    float aux;
    
    for(i = 0; i < N && *p != NULL; i++){
        Desapilar(p, &aux);         /*desapilo*/
        *Sum += aux;                /*suma*/
    }
    resultado = 1;
    return resultado;
}

int Menu(void) {
    int opcion;


    printf("\n 1. Llenar pila");
    printf("\n 2. Sumar elementos pila");
    printf("\n 3. Salir");
    printf("\n Elija opcion: ");
    scanf("%d", &opcion);

    return opcion;
}




