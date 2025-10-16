#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no_duplo{
    struct no_duplo *anterior;
    int valor;
    struct no_duplo *proximo;
} no_duplo_t;


no_duplo_t* criar_lista_encadeada_dupla(int valor){
    no_duplo_t* no_duplo = malloc(sizeof(no_duplo_t));
    no_duplo->anterior = NULL;
    no_duplo->valor = valor;
    no_duplo->proximo = NULL;

    return no_duplo;
}

void adicionar_lista_encadeada_dupla(no_duplo_t** inicio, int valor){
    no_duplo_t* novo_no = criar_lista_encadeada_dupla(valor);
    novo_no->proximo = *inicio;
    (*inicio)->anterior = novo_no;
    *inicio = novo_no;
}

no_duplo_t* buscar_lista_encadeada_dupla(no_duplo_t** inicio, int valor){
    no_duplo_t* atual = *inicio;
    while (atual){
        if (atual->valor == valor) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void remover_item_lista_encadeada_dupla(no_duplo_t** inicio, int valor){
    no_duplo_t* atual = *inicio;

    while(atual){
        if(atual->valor == valor){
            if(atual->anterior){
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            } else{
                *inicio = atual->proximo;
                (*inicio)->anterior = NULL;
            }
            free(atual);
            break;
        }
        atual = atual->proximo;
    }
}