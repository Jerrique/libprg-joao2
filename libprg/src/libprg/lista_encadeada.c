//
// Created by aluno on 28/04/2026.
//
#include "libprg.h"
#include <stdlib.h>

typedef struct no {
    int dado;
    no_t* proximo;
}no_t;

typedef struct lista_encadeada {
    no_t* inicio;
    bool ordenada;
    bool circular;
}lista_encadeada_t;

// no_t* criar_lista_encadeada () {
//     no_t* no = malloc(sizeof(no_t));
//     no->dado = (int) NULL;,
//     no->proximo = NULL;
//
//     return no;
// }

no_t* criar_no (int dado) {
    no_t* no = malloc(sizeof(no_t));
    no->dado = dado;
    no->proximo = NULL;

    return no;
}

lista_encadeada_t* criar_lista_encadeada(bool ordenada) {
    lista_encadeada_t* lista = malloc(sizeof(lista_encadeada_t));
    lista->inicio = NULL;
    lista->ordenada = ordenada;

    return lista;
}

void inserir_encadeada (lista_encadeada_t* lista, int dado) {
    no_t* novo = criar_no(dado);
    novo->proximo = lista->inicio;
    lista->inicio = novo;
}

bool remover_encadeada (lista_encadeada_t* lista, int dado) {
    no_t* atual = lista->inicio;
    no_t* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == dado) {
            if (anterior == NULL) lista->inicio = atual->proximo;
            else anterior->proximo = atual->proximo;

            free(atual);
            return true;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    return false;
}

no_t* buscar (lista_encadeada_t* lista, int dado) {
    no_t* atual = lista->inicio;

    while (atual) { //OU pode ser "while (atual != NULL)"
        if (atual->dado == dado) return lista;
        atual = atual->proximo;
    }

    return NULL;
}

void destruir_encadeada (lista_encadeada_t* lista) {

    no_t* atual = lista->inicio;

    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(lista);
}

