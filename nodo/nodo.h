#pragma once
typedef struct _NodoDoble {
    void *data;
    struct _NodoDoble *next;
    struct _NodoDoble *prev;
} NodoDoble;

typedef struct _NodoBinario {
    void *dato;
    struct _NodoBinario *izq;
    struct _NodoBinario *der;
}NodoBinario;

