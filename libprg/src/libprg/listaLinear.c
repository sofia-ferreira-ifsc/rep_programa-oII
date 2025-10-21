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

void inserir_ordenada(lista_linear_t *lista, int valor){
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
    if(lista_linear_cheia(lista)){
        lista->elementos = realloc(lista->elementos, sizeof(int) * lista->capacidade * 2);
        lista->capacidade *= 2;
    }
    if(lista->ordenada) inserir_ordenada(lista, valor);//algoritmo para lista ordenada
    else inserir_nao_ordenada(lista, valor);
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

int busca_binaria(lista_linear_t *lista, int valor) {
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio] == valor) {
            return meio;
        }
        else if (lista->elementos[meio] < valor) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }
    return -1;
}

int buscar(lista_linear_t *lista, int valor){
    if(lista->ordenada){
        return busca_binaria(lista, valor);
    }
    return buscar_item_lista_linear(lista, valor);
}

int buscar_item_lista(lista_linear_t *lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor) {
            return i;
        }
    }
    return -1;
}

void destruir_lista_linear(lista_linear_t *lista){
    free(lista->elementos);
    free(lista);
}

void remover_item_lista_linear(lista_linear_t *lista, int valor){
    int indiceItem = buscar_item_lista(lista, valor);
    if(indiceItem > -1) {
        lista->elementos[indiceItem] = lista->elementos[lista->tamanho - 1];
        lista->tamanho--;
    }
}

int buscar_na_posicao(lista_linear_t *lista, int posicao){
    return lista->elementos[posicao];
}

int limitar_posicao(lista_linear_t *lista, int posicao) {
    if(posicao > lista->tamanho) return lista->tamanho;
    if(posicao < 0) return 0;
}

// inserir e remover na posição
void inserir_na_posicao(lista_linear_t *lista, int valor, int posicao){
    int indice = limitar_posicao(lista, posicao);

    inserir_item_lista_linear(lista, lista->elementos[indice]);
    lista->elementos[posicao] = valor;
}

void remover_da_posicao(lista_linear_t *lista, int posicao){
    limitar_posicao(lista, posicao);

    int valor = lista->elementos[posicao];
    remover_item_lista_linear(lista, valor);
}