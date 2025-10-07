#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

/* empilhar, desempilhar, informar o tamanho, saber se é vazia e destruir a pilha */

typedef struct pilha{
    int capacidade;
    int *elementos;
    int tamanho;
} pilha_t;

pilha_t *criarPilha(int capacidade){
    pilha_t* pilha = malloc(sizeof(pilha_t));
    pilha->elementos = malloc(capacidade * sizeof(int));
    pilha->tamanho = -1; //inicializa a pilha como vazia
    pilha->capacidade = capacidade;

    return pilha;
}

int pilha_vazia(pilha_t *pilha){
    return pilha->tamanho == -1;
}

int tamanho_pilha(pilha_t *pilha){
    return pilha->tamanho + 1;
}

void empilhar(pilha_t *pilha, int valor){
    if(pilha->tamanho == pilha->capacidade - 1){
        printf("Erro: pilha cheia!\n");
        return;
    }
    pilha->tamanho++;
    pilha->elementos[pilha->tamanho] = valor;
}

int desempilhar(pilha_t *pilha){
    if(pilha_vazia(pilha)){
        printf("Erro: pilha vazia!\n");
        return -1;
    }
    int valor = pilha->elementos[pilha->tamanho];
    pilha->tamanho--;

    return valor;
}

void destruir_pilha(pilha_t *pilha){
    free(pilha->elementos);
    free(pilha);
}
