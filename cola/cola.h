#include "lista.h"
#include "../nodo/nodo.h"

typedef ListaDoble Cola;

void pushcola(Cola *cola, void *dato);
void *popcola(Cola *cola);
void imprimircola(Cola *cola, void (*Print_func)(void *));
int estavaciacola(Cola *cola);
void *peek(const Cola *const cola);


void *PopPrioridad(Cola *cola, int min, int (*comparar)(void *, void *));
