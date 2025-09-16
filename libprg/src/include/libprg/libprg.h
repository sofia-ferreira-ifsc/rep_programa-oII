#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdbool.h>

/*--- Pilha ---*/
typedef struct pilha Pilha;
Pilha *criarPilha(int capacidade);
void empilhar(Pilha *pilha, int valor);
int tamanho(Pilha *pilha);
void desctruir(Pilha *pilha);

/*--- Fila ---*/
typedef struct fila fila_t;
fila_t *criar_fila(int capacidade);
void enfileirar(fila_t *fila, int valor);
bool cheia(fila_t *fila);
void desenfileirar(fila_t *fila);
bool vazia(fila_t *fila);

/*--- Lista Linear ---*/
typedef struct lista_linear lista_linear_t;
lista_linear_t* criar_lista(int capacidade);
bool lista_cheia(lista_linear_t *lista);
void inserir_item_lista(lista_linear_t *lista, int valor);
bool lista_vazia(lista_linear_t *lista);
int buscar_item_lista(lista_linear_t *lista, int valor);
void destruir_lista(lista_linear_t *lista);
void remover_item_lista(lista_linear_t *lista, int valor);

#endif
