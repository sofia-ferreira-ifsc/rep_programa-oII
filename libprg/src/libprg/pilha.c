#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

/* empilhar, desempilhar, informar o tamanho, saber se é vazia e destruir a pilha */

typedef struct pilha{
    int capacidade;
    int *elementos;
    int tamanho;
} Pilha;


Pilha *criarPilha(int capacidade){
    Pilha* p = malloc(sizeof(Pilha));
    p->elementos = malloc(capacidade * sizeof(int));
    p->tamanho = -1; //inicializa a pilha como vazia
    p->capacidade = capacidade;
    return p;
}

/*void empilhar(Pilha *pilha, int valor){
    for(int i = 0; i < valor; i++){
        push(&pilha->elementos, valor[i]);
        i++;
    }
    return pilha;
}*/


