#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdbool.h>

/*--- Pila ---*/
typedef struct pilha Pilha;

Pilha *criarPilha(int capacidade);
void empilhar(Pilha *pilha, int valor);
int tamanho(Pilha *pilha);
void desctruir(Pilha *pilha);

/*--- Fila ---*/
typedef struct fila fila_t;
fila_t *criar_fila(int capacidade;
void enfileirar(fila_t *fila, int valor);
bool cheia(fila_t *fila);

#endif
