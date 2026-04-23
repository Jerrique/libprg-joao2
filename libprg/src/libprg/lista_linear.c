//
// Created by aluno on 02/04/2026.
//

#include <stdbool.h>
#include <stdlib.h>
#include <libprg/libprg.h>

#define CAPACIDADE_INICIAL 10

/*
typedef struct lista_linear {
    int *elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_linear_t *criar_lista(bool ordenada) {
    lista_linear_t *lista_linear = malloc(sizeof(lista_linear_t));
    if (lista_linear == NULL) {
        return NULL;
    }
    lista_linear->elementos = malloc(sizeof(int) * CAPACIDADE_INICIAL);
    if (lista_linear->elementos == NULL) {
        free(lista_linear);
        return NULL;
    }
    lista_linear->tamanho = 0;
    lista_linear->capacidade = CAPACIDADE_INICIAL;
    lista_linear->ordenada = ordenada;

    return lista_linear;
}

int inserir(lista_linear_t *lista_linear, int alvo) {

    int indice = buscar(lista_linear, alvo);
    //ORDENADA


    //NÃO ORDENADA





    // if (lista_linear->tamanho > lista_linear->capacidade) {
    //     exit(EXIT_FAILURE);
    // }
    // lista_linear->elementos[lista_linear->tamanho] = alvo;
    // lista_linear->tamanho++;
    // return 0;
}

int remover(lista_linear_t *lista_linear, int valor) {
    if (lista_linear->elementos[lista_linear->tamanho] == valor) {
        lista_linear->tamanho--;
    }
    //NÃO ORDENADA
    if (lista_linear->ordenada) {
        for (int i = lista_linear->elementos[lista_linear->tamanho]; i != valor; i--) {
            if (lista_linear->elementos[i] == valor) {
                lista_linear->elementos[lista_linear->tamanho - 1] = lista_linear->elementos[i];
            }
        }
        lista_linear->tamanho--;
    }
    //ORDENADA
    else {
        for (int i = 0; i <= lista_linear->capacidade; i++) {
        }
    }
    return valor;
}

int buscar (alvo) {
    //ORDENADA
    if (lista_linear->ordenada) {
        indice = buscar_binario;
    }
    //NAO ORDENADA
    else {
        indice = buscar_linear;
    }
}
*/

//buscar_linear
//buscar_binario

//alterar
//ordenar
//combinar
//destruir;
