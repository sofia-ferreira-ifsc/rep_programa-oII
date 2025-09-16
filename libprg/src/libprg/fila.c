#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "./libprg/libprg.h"

typedef struct fila {
    int *elementos;
    int inicio;
    int fim;
    int tamanho; //remover o campo tamanho
    int capacidade;
} fila_t;

fila_t *criar_fila(int capacidade){
    fila_t *fila = malloc(sizeof(fila_t));
    fila->elementos = malloc(capacidade * sizeof(int));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
}

void enfileirar(fila_t *fila, int valor){
    if(cheia(fila)){
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim++;
    fila->tamanho++;
}

bool cheia(fila_t *fila){
    return fila->tamanho >= fila->capacidade;
}

void desenfileirar(fila_t *fila){
	if(vazia(fila)){
		exit(EXIT_FAILURE);
	}
}

bool vazia(fila_t *fila){
	return (fila->fim == fila->inicio);
}


/* desenfileirar, tamanho, vazia, inicio, fim */