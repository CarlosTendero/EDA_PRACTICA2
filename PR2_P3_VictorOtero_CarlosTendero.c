/* Descripcion: Curso 2017-2018. Asignatura: Estructuras de datos y algoritmos. Practica 2. Solucion a la parte 3 de dicha practica.
 * Autor: Victor Otero
 *       Carlos Tendero
 */

/* LIBRERIAS ESTANDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
#include <time.h>
#include <locale.h>


/* ZONA DE DECLARACiON DE CONSTANTES*/


#define CORRECTO 0
#define ERR_COLA_VACIA 1
#define ERR_MEMORIA 2
#define MIN 0
#define MAX 20.0
#define POBLAR_COLA 1
#define EXTRAER_ELEMENTOS_COLA 2
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

typedef struct {
    tNodo *pCab, *pCol; /* Punteros a la cabeza y la cola. */
} tCola;

typedef tNodo tPila;

/*ZONA DE DECLARACION DE PROTOTIPOS DE FUNCIONES */


/* Funcion: AsignarMemoria
 * Devuelve memoria apara un puntero a *tCola.
 * Parametros de entrada: 
 * no tiene 
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Memoria para un puntero a *Cola. Valor devuelto por la funcion.
 */
tCola *AsignarMemoria(void);

/* Funcion: Encolar
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Elemento anyadir a la cola.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Cola. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Encolar(tCola **p, float E);

/* Funcion: Desencolar
 * Devuelve el resultado de la operacion (correcto o error).
 * Par�metros de entrada: 
 * Elemento anyadir a la cola.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Cola. Valor devuelto por referencia.
 * Elemento desapilado. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Desencolar(tCola **p, float *E);

/* Funcion: VerCola
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Cola
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * no tiene               
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int VerCola(tCola *p);

/* Funcion: LlenarCola
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Numero de elementos a incluir.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Cola. Valor devuelto por referencia.              
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int LlenarCola(tCola **p, int N);

/* Funci�n: Menu
 * Devuelve la opci�n de men� escogida.
 * Par�metros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Par�metros de salida: 
 * Opci�n de men� escogida. Valor devuelto por la funci�n.
 */
int Menu(void);

/* Funcion: Sumar
 * Extrae de la cola un numero de elementos, y devuelve su suma. Tambien 
 * devuelve el resultado de la operacion.
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Suma. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */

int Sumar(tCola **p, int N, float *Sum);

/* PROGRAMA PRINCIPAL */

int main() {

    int Resultado, Opcion, NumElem;
    tCola *pCola;
    float Suma;
    tBoolean FlgSalir;

    int i = 0; /*variable auxiliar*/
    int Elemento = 0.00; /*variable auxiliar*/

            setlocale(LC_ALL, "spanish");

    pCola = AsignarMemoria();

    FlgSalir = FALSE;
    while (!FlgSalir) {
        Opcion = Menu();
        switch (Opcion) {
            case POBLAR_COLA: /* 1.	Llenar cola.*/
                /* Llenar cola. Puebla la pila con 20 números reales generados aleatoriamente en el intervalo [0, 20].
                 *  Una vez poblada la cola, se escribe en la salida estándar el valor de los elementos de la cola.  */

                LlenarCola(&pCola, 20); /*se llena la cola*/
                VerCola(pCola); /*se muestra la cola*/

                break;

            case EXTRAER_ELEMENTOS_COLA: /* 2.Sumar elementos cola. */

                /*Sumar elementos cola. El programa solicitará al usuario el número 
                 * de elementos a extraer de la cola, mostrará por pantalla el contenido 
                 * de la cola y la suma de los elementos extraídos. Si  se solicita 
                 * extraer más elementos que los contenidos en la cola, se extraerán 
                 * todos los posibles. */

                if (pCola->pCab == NULL)
                    printf("\nNo hay elementos en la cola");
                else {
                    printf("\nCuantos elementos desea extraer (?)");
                    scanf("%d", &Elemento);         
                    while (Elemento < 1) {          /*control de errores*/
                        printf("\nValor no valido, pruebe con un valor mayor que 1");
                        scanf("%d", &Elemento);
                    }
                    Sumar(&pCola, Elemento, &Suma);         /*sumar*/
                    printf("\nSuma de los elementos extraidos:\t %.f\n", Suma);
                    Suma = 0;   /*para evitar acumulaciones*/
                    VerCola(pCola);                   
                }

                break;

            case SALIR: /* 3.	Salir */
                FlgSalir = 1;
                free(pCola);
                break;

            default:
                printf("Opcion no valida\n");
                break;
        }

    }

}

/* Funcion: AsignarMemoria
 * Devuelve memoria apara un puntero a *tCola.
 * Parametros de entrada: 
 * no tiene 
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Memoria para un puntero a *Cola. Valor devuelto por la funcion.
 */
tCola *AsignarMemoria(void) {

    tCola *cola_aux = NULL;

    cola_aux = (tCola*) malloc(sizeof (tCola)); /*memoria doble puntero*/

    /*control de errores*/
    if (cola_aux == NULL)
        return NULL;

    cola_aux->pCab = NULL;      /*cabeza NULL*/
    cola_aux->pCol = NULL;      /*cola NULL*/

    return cola_aux;

}

/* Funcion: Encolar
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Elemento anyadir a la cola.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Cola. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Encolar(tCola **p, float E) {

    tNodo* nodo_aux = NULL;         /*variable auxiliar*/

    nodo_aux = (tNodo*) malloc(sizeof (tNodo));


    if (nodo_aux == NULL)       /*control de errores*/
        return -1;
    else {
        nodo_aux->Elem = E;
        nodo_aux->Sig = NULL;
        /*esta vacia la cola (?)*/
        if ((*p)->pCab == NULL) {
            (*p)->pCab = nodo_aux;
            /*solo hay un elemento para este caso por lo que la cola 
             y la cabeza apuntan al mismo*/
            (*p)->pCol = (*p)->pCab;
        }
        else {      /*no esta vacia*/
            (*p)->pCol->Sig = nodo_aux;
            (*p)->pCol = (*p)->pCol->Sig;
        }
    }
    return 1;
}

/* Funcion: Desencolar
 * Devuelve el resultado de la operacion (correcto o error).
 * Par�metros de entrada: 
 * Elemento anyadir a la cola.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Cola. Valor devuelto por referencia.
 * Elemento desapilado. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Desencolar(tCola **p, float *E) {
    tNodo *pAux;
    int Res;
    Res = CORRECTO;
    if ((*p)->pCab == NULL)     /*contrtol de erroes*/
        Res = ERR_COLA_VACIA;
    else {
        (*E) = (*p)->pCab->Elem;
        pAux = (*p)->pCab; //Puntero al nodo a borrar
        (*p)->pCab = (*p)->pCab->Sig; //Actualizar pCab
        if ((*p)->pCab == NULL)
            (*p)->pCol = NULL; //Si la cola es vacía actualizamos pCol

        free(pAux); //Liberamos la memoria del nodo
    }
    return (Res);
}

/* Funcion: VerCola
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Cola
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * no tiene               
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int VerCola(tCola *p) {

    tNodo * pAux;           /*variable auxiliar*/
    pAux = p->pCab;
    printf("Contenido de la cola:\n");
    while (pAux != NULL) {
        printf("%.f\n", pAux->Elem);
        pAux = pAux->Sig;
    }

}

/* Funcion: LlenarCola
 * Devuelve el resultado de la operacion (correcto o error).
 * Parametros de entrada: 
 * Numero de elementos a incluir.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Cola. Valor devuelto por referencia.              
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int LlenarCola(tCola **p, int N) {
    int i = 0;

    if (p == NULL)      /*control de errores*/
        return FALSE;

    for (i = 0; i < N; i++)
        Encolar(p, rand() % 21);        /*encolo*/

    return TRUE;

}

/* Funcion: Sumar
 * Extrae de la cola un numero de elementos, y devuelve su suma. Tambien 
 * devuelve el resultado de la operacion.
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Suma. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int Sumar(tCola **p, int N, float *Sum) {
    int i = 0;
    int resultado = 0;
    float aux;

    for (i = 0; i < N && *p != NULL; i++) {
        Desencolar(p, &aux);        /*desencolo*/
        *Sum += aux;                /*sumo*/
    }
    resultado = 1;
    return resultado;
}

int Menu(void) {
    int opcion;


    printf("\n 1. Llenar cola");
    printf("\n 2. Sumar elementos cola");
    printf("\n 3. Salir");
    printf("\n Elija opcion: ");
    scanf("%d", &opcion);

    return opcion;
}







