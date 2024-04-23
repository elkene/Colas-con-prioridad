#include "../nodo/nodo.h"
#include "../cola/lista.h"
#include "../cola/cola.h"
void ingresarNodo(NodoBinario **raiz, NodoBinario *nuevo, int (*comparar)(void *, void *));
void ingresarElementoArbol(NodoBinario **raiz, void *dato,int (*comparar)(void *,void*));
void imprimirPreOrden(NodoBinario *const raiz, void (*printf)(void*));
void imprimirInOrden(NodoBinario *const raiz, void (*printf)(void*));
void imprimirPostOrden(NodoBinario *const raiz, void (*printf)(void*));
int comparar(void *a, void *b);
void imprimir_entero(void *dato);
void imprimir_float(void *dato);
void *encontrarMinimo(NodoBinario *raiz);
void *encontrarMaximo(NodoBinario *raiz);
void liberarArbol(NodoBinario *raiz);
void imprimirNivelOrden(NodoBinario *const arbol, void (*print)(void *));
int eliminarNodo(NodoBinario **raiz, void *dato, int(*comparar)(void *, void *));
NodoBinario **buscarNodo(NodoBinario **raiz, void *data, int (*comparar)(void *, void *));
NodoBinario **buscarMinimo(NodoBinario **raiz);
int alturaArbol(NodoBinario *raiz);

void IniciarListaDoble(ListaDoble *lista);
void AddHead(ListaDoble *lista, void *dato);
void AddTail(ListaDoble *lista, void *dato);

void BorrarNodo(ListaDoble *lista, void *dato);
void LiberarLista(ListaDoble *lista);
NodoDoble *GetNodo(ListaDoble *lista, void *dato);
NodoDoble *GetNodoPos(ListaDoble *lista, int pos);

void ImprimirLista(ListaDoble *lista, void (*func)(void *));

//******************Funciones colas con prioridad*************************
void ordenarLista(ListaDoble *lista, int min, int (*comparar)(void *, void *));
void selectionsort(ListaDoble *lista, int min, int (*comparar)(void *, void *));
void intercambio(NodoDoble *a, NodoDoble *b);
void bublesort(ListaDoble *lista, int min, int (*comparar)(void *, void *));
//************************************************************************