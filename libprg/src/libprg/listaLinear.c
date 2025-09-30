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
    bool ordenada; // true se for busca biário - false se for busca linear
} lista_linear_t;

// criar, inserir, buscar, remover, saber se é vazia, retornar de é cheia e destruir

lista_linear_t* criar_lista_linear(int capacidade, bool ordenada){
    lista_linear_t *lista = malloc(sizeof(lista_linear_t));
    lista->elementos = malloc(sizeof(int) * capacidade);
    lista->tamanho = 0;
    lista->capacidade = capacidade;
    lista->ordenada = ordenada;
    return lista;
}

bool lista_linear_cheia(lista_linear_t *lista){
    return lista->tamanho == lista->capacidade;
}

void inserir_nao_ordenada(lista_linear_t *lista, int valor){
    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
}

void inseir_ordenada(lista_linear_t *lista, int valor){
    for(int i = lista->tamanho - 1; i >= 0; i--){
        if(lista->elementos[i] < valor){
            lista->elementos[i + 1] = valor;
            break;
        } else{
            lista->elementos[i + 1] = lista->elementos[i];
        }
    }
    lista->tamanho++;
}

void inserir_item_lista_linear(lista_linear_t *lista, int valor){
    if(!lista_linear_cheia(lista)){
        if(lista->ordenada){ //algoritmo para lista ordenada
            inseir_ordenada(lista, valor);
        } else{
            inserir_nao_ordenada(lista, valor);
        }
    }
}

bool lista_linear_vazia(lista_linear_t *lista){
    return (lista->tamanho == 0);
}

int buscar_item_lista_linear(lista_linear_t *lista, int valor){
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

int busca_binaria(lista_linear_t *lista, int valor){

}

int buscar(lista_linear_t *lista, int valor){
    if(lista->ordenada){
        return busca_binaria(lista, valor);
    }
    return buscar_item_lista_linear(lista, valor);
}

void destruir_lista_linear(lista_linear_t *lista){
    free(lista->elementos);
    free(lista);
}

void remover_item_lista_linear(lista_linear_t *lista, int valor){
    int indiceItem = buscar_item_lista(lista, valor);
    if(indiceItem == -1) {
        return;
    }

    for(int i = indiceItem; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
}