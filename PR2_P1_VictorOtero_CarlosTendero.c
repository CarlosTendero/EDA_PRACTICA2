/* Descripcion: Curso 2017-2018. Asignatura: Estructuras de datos y algoritmos. Practica 2. Solucion a la parte 1 de dicha proctica.
 * Autor:    Victor Otero
 *          Carlos Tendero
 */

/* LIBRER�AS ESTANDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/* ZONA DE DECLARACION DE CONSTANTES*/


#define NOM_FICHERO "conjuntos.txt" 
#define NOM_FICH_RESULTADOS "resultados.txt" 
#define MAX_CARACTERES 1500
#define N 45 
#define M 100 
#define MAX_CONJUNTOS 3
#define ERROR_LECT_FICHERO 1
#define CORRECTO 0
#define MAX_NOMBRE_CONJUNTO 20

/* ZONA DE DECLARACI�N DE TIPOS*/

typedef enum {
    FALSE, TRUE
} tBoolean;

typedef struct {
    char Nombre[MAX_NOMBRE_CONJUNTO]; /*nombre*/
    unsigned short int Elementos[N]; /*n elementos*/
    short int Ultimo; /*ultimo elemento*/
} tConjunto;

/* ZONA DE DECLARACI�N DE PROTOTIPOS DE FUNCIONES */

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

/* Funcion: IniCjtos
 * Inicializa la variable que guardara los conjuntos que se leeran 
 * del fichero.
 * Parametros de entrada: 
 * no tiene 
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjuntos. Valor devuelto por referencia.
 */
void IniCjtos(tConjunto *Conjuntos);

/* Funcion: LeeFichero
 * Lee un fichero con la informacion de los conjuntos y almacena la
 * informacion.
 * Parametros de entrada: 
 * Nombre de fichero. 
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjuntos. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int LeeFichero(char *NomFichero, tConjunto *Conjuntos);

/* Funcion: CjtoVacio
 * Construye un conjunto vacio. 
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto. Valor devuelto por la funcion.
 */
tConjunto CjtoVacio(void);

/* Funcion: Aniadir
 * Anyade un elemento a un conjunto.
 * Comprueba que el elemento pertenece al 
 *conjunto universal, es decir es un numero primo ubicado en el intervalo 
 *(0, 100). El elemento que se anyada se situa a continuacion del ultimo 
 *elemento del conjunto.
 * Parametros de entrada: 
 * Elemento a anyadir.
 * Conjunto al que se desea aniadir el elemento.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto. Valor devuelto por la funcion.
 */
tConjunto Aniadir(short int Elemento, tConjunto X);

/* Funcion: Quitar
 * Quita un elemento a un conjunto. Para llenar el hueco que se deja al 
 * quitar un elemento, colocara alli el ultimo elemento.
 * Parametros de entrada: 
 * Elemento a quitar.
 * Conjunto al que se desea quitar el elemento.
 * Precondiciones: 
 * no tiene 
 * Parmetros de salida: 
 * Conjunto. Valor devuelto por la funcion.
 */
tConjunto Quitar(short int Elemento, tConjunto X);

/* Funcion: Unit
 * Construye un conjunto unitario. La funcion comprueba que el elemento 
 * pertenece al conjunto universal, es decir es un numero primo ubicado 
 * en el intervalo (0, 100).
 * Parametros de entrada: 
 * Elemento del conjunto.
 * Conjunto al que se desea quitar el elemento.
 * Precondiciones: 
 * no tiene 
 * Parsmetros de salida: 
 * Conjunto unitario. Valor devuelto por la funcion.
 */
tConjunto Unit(short int Elemento);

/* Funcion: Esta
 * Comprueba si un elemento esto en un conjunto.
 * Parametros de entrada: 
 * Elemento cuya existencia se va a comprobar.
 * Conjunto donde se chequea la existencia del elemento.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Si existe o no en el conjunto. Valor devuelto por la funcion.
 */
tBoolean Esta(short int Elemento, tConjunto C);

/* Funcion: EsCjtoVacio
 * Comprueba si un conjunto esta vacio.
 * Parametros de entrada: 
 * Conjunto.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Si esta vacio o no. Valor devuelto por la funcion.
 */
tBoolean EsCjtoVacio(tConjunto C);

/* Funcion: Union
 * Realiza la union de dos conjuntos y devuelve el resultado.
 * Parametros de entrada: 
 * Conjunto X.
 * Conjunto Y.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto resultante de la union. Valor devuelto por la funcion.
 */
tConjunto Union(tConjunto X, tConjunto Y);

/* Funcion: Interseccion
 * Realiza la interseccion de dos conjuntos y devuelve el resultado.
 * Parametros de entrada: 
 * Conjunto X.
 * Conjunto Y.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto resultante de la interseccion. Valor devuelto por la funcion.
 */
tConjunto Interseccion(tConjunto X, tConjunto Y);

/* Funcion: Complementario
 *  Obtiene el complementario de un conjunto y devuelve el resultado.
 * Parametros de entrada: 
 * Conjunto.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto complementario. Valor devuelto por la funcion.
 */
tConjunto Complementario(tConjunto X);

/* Funcion: Diferencia
 * Realiza la diferencia de dos conjuntos y devuelve el resultado.
 * Parametros de entrada: 
 * Conjunto X.
 * Conjunto Y.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto resultante de la diferencia. Valor devuelto por la funcion.
 */
tConjunto Diferencia(tConjunto X, tConjunto Y);

/* Funcion: ImprimeCjto
 * Imprime el conjunto que se le pasa como parometro, en la salida standard o en un fichero.
 * Parametros de entrada: 
 * Conjunto.
 * Valor que indica si se escribe en la salida stardard (FALSE) o en un 
 * fichero (TRUE).
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * no tiene.
 */
void ImprimeCjto(tConjunto C, tBoolean);

/* Funcion: CalcCjtoV
 * Obtiene el conjunto universal.
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto universal. Valor devuelto por la funcion.
 */
tConjunto CalcCjtoV(void);

/* Funcion: CalcCardinal
 * Obtiene el cardinal del conjunto que se le pasa como parametro.
 * Parametros de entrada: 
 * Conjunto.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Cardinal. Valor devuelto por la funcion.
 */
int CalcCardinal(tConjunto C);

/* Funcion: AlmOpe
 * Almacena las operaciones 1 a 5 en un archivo.
 * Parametros de entrada: 
 * Conjunto.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * no tiene.
 */
void AlmOpe(tConjunto Cjtos[MAX_CONJUNTOS]);

/* PROGRAMA PRINCIPAL */

int main() {

#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define OPCION_CINCO 5
#define OPCION_SEIS 6
#define OPCION_SIETE 7
#define OPCION_OCHO 8
#define OPCION_NUEVE 9
#define OPCION_DIEZ 10
#define OPCION_ONCE 11
#define SALIR 12
#define OPCION_TRECE 13


    tConjunto Conjuntos[MAX_CONJUNTOS];
    tConjunto ConjuntoZ, ConjuntoAux;
    char NomConjunto[MAX_NOMBRE_CONJUNTO];
    short int Elemento;
    tBoolean FlgSalir;


    int aux = 0;

    int i = 0;

    int Opcion;
    setlocale(LC_ALL, "spanish");

    IniCjtos(Conjuntos);
    if (LeeFichero(NOM_FICHERO, Conjuntos) == 0) {
        printf("\nNo se ha podido cargar");
        return -1;
    }
    FlgSalir = FALSE;
    while (!FlgSalir) {
        Opcion = Menu();
        switch (Opcion) { /*1. A Union B; A Union C; B Union C*/
            case OPCION_UNO:
                /*Union (A,B)*/
                ImprimeCjto(Union(Conjuntos[0], Conjuntos[1]), FALSE);
                /*Union (A,C)*/
                ImprimeCjto(Union(Conjuntos[0], Conjuntos[2]), FALSE);
                /*Union (B,C)*/
                ImprimeCjto(Union(Conjuntos[1], Conjuntos[2]), FALSE);
                break;
            case OPCION_DOS: /* 2. A Interseccion B; A Interseccion C; B Interseccion C.*/
                /*Interseccion(A,B)*/
                ImprimeCjto(Interseccion(Conjuntos[0], Conjuntos[1]), FALSE);
                /*Interseccion(A,C)*/
                ImprimeCjto(Interseccion(Conjuntos[0], Conjuntos[2]), FALSE);
                /*Interseccion(B,C)*/
                ImprimeCjto(Interseccion(Conjuntos[1], Conjuntos[2]), FALSE);
                break;
            case OPCION_TRES: /* 3. A - B; A - C; B - C */
                /*A-B*/
                ImprimeCjto(Diferencia(Conjuntos[0], Conjuntos[1]), FALSE);
                /*A-C*/
                ImprimeCjto(Diferencia(Conjuntos[0], Conjuntos[2]), FALSE);
                /*B-C*/
                ImprimeCjto(Diferencia(Conjuntos[1], Conjuntos[2]), FALSE);
                break;
            case OPCION_CUATRO: /* 4.Complementario (A); Complementario(B); Complementario(C).*/

                ConjuntoZ = CjtoVacio();
                /*Complementario(A)*/
                ImprimeCjto(Complementario(Conjuntos[0]), FALSE);
                /*Complementario(B)*/ 
                ImprimeCjto(Complementario(Conjuntos[1]), FALSE);
                /*Complementario(C)*/
                ImprimeCjto(Complementario(Conjuntos[2]), FALSE);
                break;
            case OPCION_CINCO: /* 5.(A Interseccion B ) Union Complementario (( B Interseccion C )).*/
                ConjuntoZ = CjtoVacio();
                ConjuntoAux = CjtoVacio();
                printf("\nConjunto %s Interseccion Conjunto %s", Conjuntos[0].Nombre, Conjuntos[1].Nombre);
                ConjuntoZ = Interseccion(Conjuntos[0], Conjuntos[1]);
                printf("\nConjunto %s Interseccion Conjunto %s", Conjuntos[1].Nombre, Conjuntos[2].Nombre);
                ConjuntoAux = Interseccion(Conjuntos[1], Conjuntos[2]);
                printf("\nComplementario de la ultima interseccion");
                ConjuntoAux = Complementario(ConjuntoAux);
                printf("\nUnion de los conjuntos");
                ConjuntoZ = Union(ConjuntoZ, ConjuntoAux);
                ImprimeCjto(ConjuntoZ, FALSE);
                break;
            case OPCION_SEIS: /* 6.Crear conjunto vacio. */
                ConjuntoZ = CjtoVacio();
                printf("\nConjunto %s", ConjuntoZ.Nombre);
                break;
            case OPCION_SIETE: /* 7. Anadir elemento. */
                printf("\nIntroduzca un valor entre (0,100)");
                scanf("%d", &Elemento);
                while (Elemento < 0 || 100 < Elemento) {
                    printf("\nValor no valido");
                    printf("\nIntroduzca un valor entre (0,100)");
                    fflush(stdin);
                    scanf("%d", &Elemento);
                }
                while (Esta(Elemento, CalcCjtoV()) == FALSE) {
                    printf("\nEl numero introducido no es primo");
                    printf("\nIntroduzca un valor entre(0,100)");
                    fflush(stdin);
                    scanf("%d", &Elemento);
                }

                if (Esta(Elemento, Conjuntos[0]) == TRUE && Esta(Elemento, Conjuntos[1]) == TRUE && Esta(Elemento, Conjuntos[2]) == TRUE)
                    printf("\nEl elemento introducido esta en todos los conjuntos");
                else {
                    printf("\nEl valor puede introducirse en: ");
                    if (Esta(Elemento, Conjuntos[0]) == FALSE)
                        printf("\n1: \t%s", Conjuntos[0].Nombre);
                    if (Esta(Elemento, Conjuntos[1]) == FALSE)
                        printf("\n2: \t%s", Conjuntos[1].Nombre);
                    if (Esta(Elemento, Conjuntos[2]) == FALSE)
                        printf("\n3: \t%s", Conjuntos[2].Nombre);

                    printf("\nIntroduzca una opcion: ");
                    fflush(stdin);
                    scanf("%d", &aux);
                    while (aux < 0 || 3 < aux) {
                        printf("\nOpcion no valida, pruebe de nuevo");
                        scanf("%d", &aux);
                    }
                    if (aux == 1)
                        Conjuntos[0] = Aniadir(Elemento, Conjuntos[0]);
                    else if (aux == 2)
                        Conjuntos[1] = Aniadir(Elemento, Conjuntos[1]);
                    else if (aux == 3)
                        Conjuntos[2] = Aniadir(Elemento, Conjuntos[2]);
                }

                break;
            case OPCION_OCHO: /*Quita un elemento*/
                printf("\nIntroduzca un valor entre (0,100)");
                scanf("%d", &Elemento);
                while (Elemento < 0 || 100 < Elemento) {
                    printf("\nValor no valido");
                    printf("\nIntroduzca un valor entre (0,100)");
                    scanf("%d", &Elemento);
                }
                if (Esta(Elemento, Conjuntos[0]) == FALSE && Esta(Elemento, Conjuntos[1]) == FALSE && Esta(Elemento, Conjuntos[2]) == FALSE)
                    printf("\nEl elemento no se encuentra en ningun conjunto");

                printf("\nEl valor puede ser eliminado en: ");
                if (Esta(Elemento, Conjuntos[0]) == TRUE)
                    printf("\n1: \t%s", Conjuntos[0].Nombre);
                if (Esta(Elemento, Conjuntos[1]) == TRUE)
                    printf("\n2: \t%s", Conjuntos[1].Nombre);
                if (Esta(Elemento, Conjuntos[2]) == TRUE)
                    printf("\n3: \t%s", Conjuntos[2].Nombre);

                printf("\nIntroduzca una opcion: ");
                fflush(stdin);
                scanf("%d", &aux);
                while (aux < 0 || 3 < aux) {
                    printf("\nOpcion no valida, pruebe de nuevo");
                    scanf("%d", &aux);
                }
                if (aux == 1)
                    Conjuntos[0] = Quitar(Elemento, Conjuntos[0]);
                else if (aux == 2)
                    Conjuntos[1] = Quitar(Elemento, Conjuntos[1]);
                else if (aux == 3)
                    Conjuntos[2] = Quitar(Elemento, Conjuntos[2]);



                break;
            case OPCION_NUEVE: /* 9. Crear conjunto unitario. */
                printf("\nIntroduzca un valor entre (0,100)");
                scanf("%d", &Elemento);

                while (Elemento < 0 || 100 < Elemento) {
                    printf("\nValor no valido, pruebe de nuevo (0,100): ");
                    scanf("%d", &Elemento);
                }
                while (Esta(Elemento, CalcCjtoV()) == FALSE) {
                    printf("\nEl numero introducido no es primo");
                    printf("\nIntroduzca un valor entre(0,100)");
                    fflush(stdin);
                    scanf("%d", &Elemento);
                }
                ConjuntoAux = Unit(Elemento);
                printf("\nConjunto \t%s", ConjuntoAux.Nombre);
                printf("\nConjunto \t%s", ConjuntoAux.Elementos[0]);

                break;
            case OPCION_DIEZ: /* 10.Comprobar existencia.*/
                printf("\nIntroduzca un valor a comprobar su existencia: ");
                scanf("%d", &Elemento);
                while (Elemento < 0 && 100 < Elemento) {
                    printf("\nValor no valido, pruebe de nuevo (0,100): ");
                    scanf("%d", &Elemento);
                }

                if (Esta(Elemento, Conjuntos[0]) == FALSE && Esta(Elemento, Conjuntos[1]) == FALSE && Esta(Elemento, Conjuntos[2]) == FALSE)
                    printf("\nEl elemento no se encuentra en ningun conjunto");

                else {
                    for (i = 0; i < MAX_CONJUNTOS && strcmp(Conjuntos[i].Nombre, "?") != 0; i++)
                        if (Esta(Elemento, Conjuntos[i]) == TRUE)
                            printf("\n%d esta en el Conjunto %s", Elemento, Conjuntos[i].Nombre);
                }

                break;
            case OPCION_ONCE:

                printf("\nQue Conjunto quiere calcular su cardinal: ");
                scanf("%d", &aux);
                while (aux < 0 || 3 < aux) {
                    printf("\nValor no valido, pruebe de nuevo (1,3): ");
                    scanf("%d", &aux);
                    if (aux == 1) {
                        printf("\nCardinal del conjunto %s es", Conjuntos[0].Nombre);
                        if (Conjuntos[0].Ultimo == -1)
                            printf("\nNo hay elementos");
                        else
                            printf("\n%d", Conjuntos[0].Ultimo + 1);
                    } else if (aux == 2) {
                        printf("\nCardinal del conjunto %s es", Conjuntos[1].Nombre);
                        if (Conjuntos[1].Ultimo == -1)
                            printf("\nNo hay elementos");
                        else
                            printf("\n%d", Conjuntos[1].Ultimo + 1);
                    } else if (aux == 3) {
                        printf("\nCardinal del conjunto %s es", Conjuntos[2].Nombre);
                        if (Conjuntos[2].Ultimo == -1)
                            printf("\nNo hay elementos");
                        else
                            printf("\n%d", Conjuntos[2].Ultimo + 1);
                    }
                }

                break;
            case SALIR: /* 12.	Salir. */
                FlgSalir = TRUE;
                break;
            case OPCION_TRECE: /*13.	Almacenar los resultados de las opciones 1, 2, 3, 4 y 5 en un archivo. */

                AlmOpe(Conjuntos);

                break;

            default:
                printf("Opcion no valida\n");

        }
    }
    return CORRECTO;

}

int Menu(void) {
    int opcion;


    printf("\n 1. A Union B; A Union C; B Union C");
    printf("\n 2. A Interseccion B; A Interseccion C; B Interseccion C");
    printf("\n 3. A - B; A - C; B - C");
    printf("\n 4. Complementario(A); Complementario(B); Complementario(C)");
    printf("\n 5. (A Interseccion B ) Union Comp(( B Interseccion C ))");
    printf("\n 6. Crear conjunto vacio");
    printf("\n 7. Anadir elemento");
    printf("\n 8. Quitar elemento");
    printf("\n 9. Crear conjunto unitario");
    printf("\n 10. Comprobar existencia");
    printf("\n 11. Calcular cardinal de conjunto");
    printf("\n 12. Salir");
    printf("\n 13. Almacenar los resultados de las opciones 1, 2, 3, 4 y 5 en un archivo");
    printf("\n Elija opcion");
    scanf("%d", &opcion);

    return opcion;
}

/* Funcion: CalcCjtoV
 * Obtiene el conjunto universal.
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto universal. Valor devuelto por la funcion.
 */
tConjunto CalcCjtoV(void) {
    tConjunto conjunto_aux;
    int i = 0, j = 0, flg = 0;
    conjunto_aux = CjtoVacio();
    strcpy(conjunto_aux.Nombre, "UniV");

    conjunto_aux = Aniadir(1, conjunto_aux); /*caso especial*/
    conjunto_aux = Aniadir(2, conjunto_aux); /*caso especial*/
    for (i = 3; i < 100; i++) {
        flg = 0;
        for (j = 2; j <= sqrt(i) && flg == 0; j++) {
            if (i % j == 0)
                flg = 1;
        }
        if (flg == 0)
            conjunto_aux = Aniadir(i, conjunto_aux);

    }
    return conjunto_aux;
}

/* Funcion: CjtoVacio
 * Construye un conjunto vacio. 
 * Parametros de entrada: 
 * no tiene.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto. Valor devuelto por la funcion.
 */
tConjunto CjtoVacio(void) {
    tConjunto conjunto_aux;
    int i = 0;
    strcpy(conjunto_aux.Nombre, "Vacio");
    for (i = 0; i < N; i++)
        conjunto_aux.Elementos[i] = 0;
    conjunto_aux.Ultimo = -1;

    return conjunto_aux;
}

/* Funcion: IniCjtos
 * Inicializa la variable que guardara los conjuntos que se leeran 
 * del fichero.
 * Parametros de entrada: 
 * no tiene 
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjuntos. Valor devuelto por referencia.
 */
void IniCjtos(tConjunto *Conjuntos) {
    int i = 0, j = 0;
    for (i = 0; i < MAX_CONJUNTOS; i++) {
        for (j = 0; j < N; j++)
            Conjuntos[i].Elementos[j] = 0;
        Conjuntos[i].Ultimo = -1;
        strcpy(Conjuntos[i].Nombre, "?");
    }
}

/* Funcion: ImprimeCjto
 * Imprime el conjunto que se le pasa como parometro, en la salida standard o en un fichero.
 * Parametros de entrada: 
 * Conjunto.
 * Valor que indica si se escribe en la salida stardard (FALSE) o en un 
 * fichero (TRUE).
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * no tiene.
 */
void ImprimeCjto(tConjunto C, tBoolean Flg) {
    int i = 0;
    FILE* faux;
    if (Flg == FALSE) {
        fprintf(stdout, "\n\tNombre: %s", C.Nombre);
        for (i = 0; i < N && C.Elementos[i] != 0; i++)
            fprintf(stdout, "\n\tElemento\t%d:\t%d", i + 1, C.Elementos[i]);
    } else if (Flg == TRUE) {
        if (!(faux = fopen(NOM_FICH_RESULTADOS, "a+")))
            faux = fopen(NOM_FICH_RESULTADOS, "w");
        fprintf(faux, "\n\tNombre: %s", C.Nombre);
        for (i = 0; i < N && C.Elementos[i] != 0; i++)
            fprintf(faux, "\n\tElemento\t%d:\t%d", i + 1, C.Elementos[i]);
        fclose(faux);
    }

}

/* Funcion: LeeFichero
 * Lee un fichero con la informacion de los conjuntos y almacena la
 * informacion.
 * Parametros de entrada: 
 * Nombre de fichero. 
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjuntos. Valor devuelto por referencia.
 * Resultado de la operacion. Valor devuelto por la funcion.
 */
int LeeFichero(char *NomFichero, tConjunto *Conjuntos) {
    FILE *fichero;
    char *toks = NULL;
    char cadena[MAX_CARACTERES];
    int Elemento;
    int i = 0, j = 0;
    fichero = fopen(NomFichero, "r");
    if (fichero) {
        while (fgets(cadena, MAX_CARACTERES, fichero) && i < MAX_CONJUNTOS) {
            toks = strtok(cadena, ";");
            strcpy(Conjuntos[i].Nombre, toks);
            toks = strtok(NULL, ";");
            while (toks) {
                Conjuntos[i].Elementos[j] = atol(toks);
                toks = strtok(NULL, ";");
                j++;
            }
            Conjuntos[i].Ultimo = j - 1;
            i++;
            j = 0;
        }
        return 1;
    } else
        return 0;
}

/* Funcion: Esta
 * Comprueba si un elemento esto en un conjunto.
 * Parametros de entrada: 
 * Elemento cuya existencia se va a comprobar.
 * Conjunto donde se chequea la existencia del elemento.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Si existe o no en el conjunto. Valor devuelto por la funcion.
 */
tBoolean Esta(short int Elemento, tConjunto C) {
    int i = 0;
    tBoolean aux = FALSE;
    for (i = 0; i < N && aux == FALSE; i++)
        if (C.Elementos[i] == Elemento)
            aux = TRUE;
    return aux;
}

/* Funcion: Union
 * Realiza la union de dos conjuntos y devuelve el resultado.
 * Parametros de entrada: 
 * Conjunto X.
 * Conjunto Y.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto resultante de la union. Valor devuelto por la funcion.
 */
tConjunto Union(tConjunto X, tConjunto Y) {

    tConjunto conjunto_aux;
    int i = 0;

    conjunto_aux = CjtoVacio();

    if (strcmp(X.Nombre, "?") == 0 || strcmp(Y.Nombre, "?") == 0)
        return conjunto_aux;


    strcpy(conjunto_aux.Nombre, X.Nombre);
    strcat(conjunto_aux.Nombre, "uni");
    strcat(conjunto_aux.Nombre, Y.Nombre);
    /*meto los valores en conjunto_aux*/

    for (i = 0; i < N && X.Elementos[i] != 0; i++)
        conjunto_aux = Aniadir(X.Elementos[i], conjunto_aux);


    for (i = 0; i < N && Y.Elementos[i] != 0; i++)
        if (Esta(Y.Elementos[i], conjunto_aux) == FALSE)
            conjunto_aux = Aniadir(Y.Elementos[i], conjunto_aux);

    return conjunto_aux;

}

/* Funcion: Interseccion
 * Realiza la interseccion de dos conjuntos y devuelve el resultado.
 * Parametros de entrada: 
 * Conjunto X.
 * Conjunto Y.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto resultante de la interseccion. Valor devuelto por la funcion.
 */
tConjunto Interseccion(tConjunto X, tConjunto Y) {
    tConjunto conjunto_aux;
    int i = 0;
    conjunto_aux = CjtoVacio();
    if (strcmp(X.Nombre, "?") == 0 || strcmp(Y.Nombre, "?") == 0)
        return conjunto_aux;

    strcpy(conjunto_aux.Nombre, X.Nombre);
    strcat(conjunto_aux.Nombre, "int");
    strcat(conjunto_aux.Nombre, Y.Nombre);

    for (i = 0; i < N && X.Elementos[i] != 0; i++)
        if (Esta(X.Elementos[i], Y) == TRUE)
            conjunto_aux = Aniadir(X.Elementos[i], conjunto_aux);

    return conjunto_aux;
}

/* Funcion: Diferencia
 * Realiza la diferencia de dos conjuntos y devuelve el resultado.
 * Parametros de entrada: 
 * Conjunto X.
 * Conjunto Y.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto resultante de la diferencia. Valor devuelto por la funcion.
 */
tConjunto Diferencia(tConjunto X, tConjunto Y) {
    tConjunto conjunto_aux;
    int i = 0;

    conjunto_aux = CjtoVacio();
    strcpy(conjunto_aux.Nombre, X.Nombre);
    strcat(conjunto_aux.Nombre, "-");
    strcat(conjunto_aux.Nombre, Y.Nombre);
    if (strcmp(X.Nombre, "?") == 0 || strcmp(Y.Nombre, "?") == 0)
        return conjunto_aux;

    for (i = 0; i < N && X.Elementos[i] != 0; i++)
        if (Esta(X.Elementos[i], Y) == FALSE)
            conjunto_aux = Aniadir(X.Elementos[i], conjunto_aux);

    return conjunto_aux;

}

/* Funcion: Complementario
 *  Obtiene el complementario de un conjunto y devuelve el resultado.
 * Parametros de entrada: 
 * Conjunto.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto complementario. Valor devuelto por la funcion.
 */
tConjunto Complementario(tConjunto X) {
    tConjunto conjunto_aux;

    conjunto_aux = CalcCjtoV();

    return Diferencia(conjunto_aux, X);
}

/* Funcion: Aniadir
 * Anyade un elemento a un conjunto.
 * Comprueba que el elemento pertenece al 
 *conjunto universal, es decir es un numero primo ubicado en el intervalo 
 *(0, 100). El elemento que se anyada se situa a continuacion del ultimo 
 *elemento del conjunto.
 * Parametros de entrada: 
 * Elemento a anyadir.
 * Conjunto al que se desea aniadir el elemento.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Conjunto. Valor devuelto por la funcion.
 */
tConjunto Aniadir(short int Elemento, tConjunto X) {

    int i = 0;

    if (Elemento < 0 || 100 < Elemento)
        return X;

    if (strcmp(X.Nombre, "?") == 0)
        return X;

    for (i = 0; i < N && X.Elementos[i] != 0; i++)
        if (X.Elementos[i] == Elemento)
            return X;

    if (i == N)
        return X;

    X.Elementos[i] = Elemento;
    X.Ultimo = i;

    return X;
}

/* Funcion: Quitar
 * Quita un elemento a un conjunto. Para llenar el hueco que se deja al 
 * quitar un elemento, colocara alli el ultimo elemento.
 * Parametros de entrada: 
 * Elemento a quitar.
 * Conjunto al que se desea quitar el elemento.
 * Precondiciones: 
 * no tiene 
 * Parmetros de salida: 
 * Conjunto. Valor devuelto por la funcion.
 */

tConjunto Quitar(short int Elemento, tConjunto X) {

    int i = 0, aux = 0;

    if (Elemento < 0 || 100 < Elemento)
        return X;

    for (i = 0; i < N && X.Elementos[i] != Elemento; i++);

    if (i == N)
        return X;

    X.Elementos[i] = 0;
    /**ordenarlo*/

    for (i = 0; i < N - 1 && (X.Elementos[i] != X.Elementos[i + 1]); i++) {
        if (X.Elementos[i] == -1 && X.Elementos[i + 1] != 0) {
            aux = X.Elementos[i + 1];
            X.Elementos[i + 1] = 0;
            X.Elementos[i] = aux;
            X.Ultimo = i - 1;
        }
    }

    return X;
}

/* Funcion: Unit
 * Construye un conjunto unitario. La funcion comprueba que el elemento 
 * pertenece al conjunto universal, es decir es un numero primo ubicado 
 * en el intervalo (0, 100).
 * Parametros de entrada: 
 * Elemento del conjunto.
 * Conjunto al que se desea quitar el elemento.
 * Precondiciones: 
 * no tiene 
 * Parsmetros de salida: 
 * Conjunto unitario. Valor devuelto por la funcion.
 */
tConjunto Unit(short int Elemento) {

    tConjunto conjunto_aux;

    conjunto_aux = CjtoVacio();

    strcpy(conjunto_aux.Nombre, "Unitario");

    return Aniadir(Elemento, conjunto_aux);


}

/* Funcion: CalcCardinal
 * Obtiene el cardinal del conjunto que se le pasa como parametro.
 * Parametros de entrada: 
 * Conjunto.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * Cardinal. Valor devuelto por la funcion.
 */
int CalcCardinal(tConjunto C) {
    return C.Ultimo + 1;
}

/* Funcion: AlmOpe
 * Almacena las operaciones 1 a 5 en un archivo.
 * Parametros de entrada: 
 * Conjunto.
 * Precondiciones: 
 * no tiene 
 * Parametros de salida: 
 * no tiene.
 */
void AlmOpe(tConjunto Cjtos[MAX_CONJUNTOS]) {

    /*OPCION 1*/
    ImprimeCjto(Union(Cjtos[0], Cjtos[1]), TRUE);
    ImprimeCjto(Union(Cjtos[0], Cjtos[2]), TRUE);
    ImprimeCjto(Union(Cjtos[1], Cjtos[2]), TRUE);

    /*OPCION 2*/
    ImprimeCjto(Interseccion(Cjtos[0], Cjtos[1]), TRUE);
    ImprimeCjto(Interseccion(Cjtos[0], Cjtos[2]), TRUE);
    ImprimeCjto(Interseccion(Cjtos[1], Cjtos[2]), TRUE);

    /*OPCION 3*/
    ImprimeCjto(Diferencia(Cjtos[0], Cjtos[1]), TRUE);
    ImprimeCjto(Diferencia(Cjtos[0], Cjtos[2]), TRUE);
    ImprimeCjto(Diferencia(Cjtos[1], Cjtos[2]), TRUE);

    /*OPCION 4*/
    ImprimeCjto(Complementario(Cjtos[0]), TRUE);
    ImprimeCjto(Complementario(Cjtos[1]), TRUE);
    ImprimeCjto(Complementario(Cjtos[2]), TRUE);

    /*OPCION 5*/

    ImprimeCjto(Union(Interseccion(Cjtos[0], Cjtos[1]), Complementario(Interseccion(Cjtos[1], Cjtos[2]))), TRUE);


}




