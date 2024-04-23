#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../nodo/nodo.h"
#include "../cola/lista.h"
#include "funciones.h"




void IniciarListaDoble(ListaDoble *lista) {
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}

void AddHead(ListaDoble *lista, void *dato) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo\n");
        return;
    }
    nuevo->data = dato;
    nuevo->next = lista->head;
    nuevo->prev = NULL;
    if (lista->head != NULL) {
        lista->head->prev = nuevo;
    } else {
        lista->tail = nuevo;
    }
    lista->head = nuevo;
    lista->size++;
}

void AddTail(ListaDoble *lista, void *dato) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    if (nuevo == NULL) {
        printf("Error: No se pudo asignar memoria para el nuevo nodo\n");
        return;
    }
    nuevo->data = dato;
    nuevo->next = NULL;
    nuevo->prev = lista->tail;
    if (lista->tail != NULL) {
        lista->tail->next = nuevo;
    } else {
        lista->head = nuevo;
    }
    lista->tail = nuevo;
    lista->size++;
}

NodoDoble *GetNodoPos(ListaDoble *lista, int pos) {
    NodoDoble *temp = lista->head;
    while (temp != NULL && pos > 0) {
        temp = temp->next;
        pos--;
    }
    return temp;
}



void ImprimirLista(ListaDoble *lista, void (*func)(void *)) {
    NodoDoble *actual = lista->head;
    while (actual != NULL) {
        func(actual->data);
        actual = actual->next;
    }
}

void LiberarLista(ListaDoble *lista) {
    NodoDoble *temp;
    while (lista->head != NULL) {
        temp = lista->head;
        lista->head = lista->head->next;
        free(temp->data);
        free(temp);
    }
    lista->tail = NULL;
    lista->size = 0;
}

NodoDoble *GetNodo(ListaDoble *lista, void *dato) {
    NodoDoble *temp = lista->head;
    while (temp != NULL) {
        if (temp->data == dato) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void BorrarNodo(ListaDoble *lista, void *dato) {
    NodoDoble *curr = GetNodo(lista, dato);
    if (curr == NULL) {
        printf("No se encontro el nodo\n");
        return;
    }

    if (curr->prev == NULL) {
        lista->head = curr->next;
    } else {
        curr->prev->next = curr->next;
    }

    if (curr->next == NULL) {
        lista->tail = curr->prev;
    } else {
        curr->next->prev = curr->prev;
    }

    free(curr);
    lista->size--;
}

int alturaArbol(NodoBinario *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int altura_izquierda = alturaArbol(raiz->izq);
        int altura_derecha = alturaArbol(raiz->der);
        return (altura_izquierda > altura_derecha ? altura_izquierda : altura_derecha) + 1;
    }
}

int comparar(void *a, void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return (*int_a - *int_b);
}

void imprimir_entero(void *dato) {
    int *valor = (int *)dato;
    printf("%d ", *valor);
}

void imprimir_float(void *dato) {
    float *valor = (float *)dato;
    printf("\n%.2f ", *valor);
}

void *encontrarMinimo(NodoBinario *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    NodoBinario *actual = raiz;
    while (actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual->dato;
}

void *encontrarMaximo(NodoBinario *raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    NodoBinario *actual = raiz;
    while (actual->der != NULL) {
        actual = actual->der;
    }
    return actual->dato;
}

void ingresarNodo(NodoBinario **raiz, NodoBinario *nuevo, int (*comparar)(void *, void *)) {
    if (*raiz == NULL) {
        *raiz = nuevo;
    } else {
        if (comparar(nuevo->dato, (*raiz)->dato) < 0) {
            ingresarNodo(&((*raiz)->izq), nuevo, comparar);
        } else {
            ingresarNodo(&((*raiz)->der), nuevo, comparar);
        }
    }
}


void ingresarElementoArbol(NodoBinario **raiz, void *dato, int (*comparar)(void *, void *)) {
    NodoBinario *nuevo = (NodoBinario *)malloc(sizeof(NodoBinario));
    if (nuevo == NULL) {
        fprintf(stderr, "Error: memoria insuficiente para crear un nuevo nodo.\n");
        exit(EXIT_FAILURE);
    }
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    ingresarNodo(raiz, nuevo, comparar);
}

void imprimirPreOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    printf(raiz->dato);
    imprimirPreOrden(raiz->izq,printf);
    imprimirPreOrden(raiz->der,printf);
}
void imprimirInOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    imprimirInOrden(raiz->izq,printf);
    printf(raiz->dato);
    imprimirInOrden(raiz->der,printf);

}
void imprimirPostOrden(NodoBinario *const raiz, void (*printf)(void*))
{
    if (raiz==NULL)
    return;

    imprimirPostOrden(raiz->izq,printf);
    imprimirPostOrden(raiz->der,printf);
    printf(raiz->dato);

}

void liberarArbol(NodoBinario *raiz) {
    if (raiz == NULL)
        return;

    liberarArbol(raiz->izq);
    liberarArbol(raiz->der);
    free(raiz->dato); 
    free(raiz); 
}
void imprimirNivelOrden(NodoBinario *const arbol, void (*print)(void *)) {
    if (arbol == NULL)
        return;

    Cola colaAuxiliar;
    IniciarListaDoble(&colaAuxiliar);
    pushcola(&colaAuxiliar, arbol);

    while (!estavaciacola(&colaAuxiliar)) {
        NodoBinario *nodo = (NodoBinario *)popcola(&colaAuxiliar);
        print(nodo->dato);

        if (nodo->izq != NULL)
            pushcola(&colaAuxiliar, nodo->izq);
        if (nodo->der != NULL)
            pushcola(&colaAuxiliar, nodo->der);
    }
}

NodoBinario **buscarNodo(NodoBinario **raiz, void *data, int (*comparar)(void *, void *)) {
    if (*raiz == NULL || comparar((*raiz)->dato, data) == 0) {
        return raiz;
    }

    if (comparar((*raiz)->dato, data) > 0) {
        return buscarNodo(&((*raiz)->izq), data, comparar);
    } else {
        return buscarNodo(&((*raiz)->der), data, comparar);
    }
}

NodoBinario **buscarMinimo(NodoBinario **raiz) {
    NodoBinario **actual = raiz;

    while ((*actual)->izq != NULL) {
        actual = &((*actual)->izq);
    }

    return actual;
}


int eliminarNodo(NodoBinario **raiz, void *data, int (*comparar)(void *, void *)) {
    NodoBinario **nborrar = buscarNodo(raiz, data, comparar);

    if (*nborrar == NULL) {
        return 0;
    }

    if ((*nborrar)->izq == NULL && (*nborrar)->der == NULL) {
        free(*nborrar);
        *nborrar = NULL;
        return 1;
    } else if ((*nborrar)->der == NULL) {
        NodoBinario *temporal = *nborrar;
        *nborrar = (*nborrar)->izq;
        free(temporal);
        temporal = NULL;
        return 1;
    } else if ((*nborrar)->izq == NULL) {
        NodoBinario *temporal = *nborrar;
        *nborrar = (*nborrar)->der;
        free(temporal);
        temporal = NULL;
        return 1;
    } else {
        NodoBinario **minimo = buscarMinimo(&((*nborrar)->der));
        (*nborrar)->dato = (*minimo)->dato;
        return eliminarNodo(&((*nborrar)->der), (*minimo)->dato, comparar);
    }
}

//******************Funciones colas con prioridad*************************
void ordenarLista(ListaDoble *lista, int min, int (*comparar)(void *, void *))
{
    selectionsort(lista,min,comparar);
}
void selectionsort(ListaDoble *lista, int min, int (*comparar)(void *, void *))
{
    int tam = lista->size;
    NodoDoble *nodoOrd = NULL;
    NodoDoble *pivote = lista->head;
    NodoDoble *sig = pivote->next;

    for(int i=0; i < tam - 1; i++ )
    {
        nodoOrd=pivote;
        for (int j = (i+1); j < tam; j++)
        {
            if(comparar(nodoOrd->data, sig->data)> 0 && min == 1)
            {
                nodoOrd=sig;
            }
            else if(comparar(nodoOrd->data, sig->data)< 0 && min == 0)
            {
                nodoOrd=sig;
            }
            sig=sig->next;
        }
        intercambio(pivote,nodoOrd);
        pivote=pivote->next;
        sig=pivote->next;
        }
}

void intercambio(NodoDoble *a, NodoDoble *b)
{
    void *temp = a->data;
    a->data=b->data;
    b->data=temp;
}

void bublesort(ListaDoble *lista, int min, int (*comparar)(void *, void *))
{
    int tam=lista->size;
    NodoDoble *actual = lista->head;
    NodoDoble *sig = lista->head;

    for(int i=0; i<tam; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(comparar(actual->data,sig->data) > 0 && min == 0)
            {
                intercambio(actual,sig);
            }
            else if(comparar(actual->data,sig->data) < 0 && min == 1)
            {
                intercambio(actual, sig);
            }
            sig=sig->next;
        }
            actual=actual->next;
            sig = lista->head;
    }
}

