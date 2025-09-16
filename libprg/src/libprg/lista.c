//
// Created by sofia on 16/09/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct lista_linear {
    int *elementos;
    int tamanho; // quantos tem
    int capacidade; //quantos cabem
} lista_linear_t;

// criar, inserir, buscar, remover, saber se é vazia, retornar de é cheia e destruir

lista_linear_t* criar_lista(int capacidade){
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    return lista;
}

bool lista_cheia(lista_linear_t *lista){
    return lista->tamanho == lista->capacidade;
}

void inserir_item_lista(lista_linear_t *lista, int valor){
    if(cheia(lista)){
        exit(EXIT_FAILURE);
    }

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

bool lista_vazia(lista_linear_t *lista){
    return (lista->tamanho == 0);
}

int buscar_item_lista(lista_linear_t *lista, int valor){
    int indice = 0;
    while(indice < lista->tamanho){
        if(lista->elementos[indice] == valor)
        {
            return indice;
        }
        indice++;
    }
    return -1;
}

void destruir_lista(lista_linear_t *lista){
    free(lista->elementos);
    free(lista);
}

void remover_item_lista(lista_linear_t *lista, int valor){
    int indiceItem = buscar_item_lista(lista, valor);
    if(indiceItem == -1) {
        return;
    }

    for(int i = indiceItem; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
}