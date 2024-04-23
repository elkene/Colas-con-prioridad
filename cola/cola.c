#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "cola.h"
#include "../funciones/funciones.h"

void pushcola(Cola *cola, void *dato)
{
    AddTail(cola,dato);
}

void *popcola(ListaDoble *cola) {
    NodoDoble *nodo = cola->head;
    if (nodo == NULL) {
        printf("Error: La cola está vacía.\n");
        return NULL;
    }
    void *copia = nodo->data;
    cola->head = nodo->next;
    if (cola->head == NULL) {
        cola->tail = NULL;
    } else {
        cola->head->prev = NULL;
    }
    free(nodo);
    cola->size--;
    return copia;
}

int estavaciacola(ListaDoble *cola) {
    return cola->head == NULL;
}


void imprimircola(Cola *cola, void (*Print_func)(void *)) {
    Cola aux;
    void *dato = NULL;

    IniciarListaDoble(&aux);

    while (cola->size != 0) {
        dato = popcola(cola);
        Print_func(dato);
        pushcola(&aux, dato);
    }

    LiberarLista(cola); 
    IniciarListaDoble(cola); 

    while (aux.size != 0) {
        dato = popcola(&aux);
        pushcola(cola, dato);
    }

    LiberarLista(&aux); 
}


void *peek(const Cola *const cola)
{
    return cola->head->data;
}


void *PopPrioridad(Cola *cola, int min, int (*comparar)(void *, void *))
{
    ordenarLista(cola,min,comparar);
    
    return popcola(cola);
    
}