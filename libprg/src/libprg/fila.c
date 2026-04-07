//
// Created by aluno on 26/03/2026.
//

#include <stdbool.h>
#include <stdlib.h>
#include <libprg/libprg.h>

typedef struct fila {
    int* elementos;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
}fila_t;

fila_t* criar_fila (int capacidade) {
    fila_t* fila = malloc(sizeof(fila_t));
    if (fila == NULL) {
        return NULL;
    }
    fila->elementos = malloc(sizeof(int) * capacidade);
    if (fila->elementos == NULL) {
        free(fila);
        return NULL;
    }
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;

    return fila;
}


void enfileirar (fila_t* fila, int valor) {

    if (cheia(fila)) {
        exit(EXIT_FAILURE);
    }

    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}
int desenfileirar (fila_t* fila) {
    if (vazia_f(fila)) exit(EXIT_FAILURE);
    int valor = fila->elementos[fila->inicio];
    fila->inicio = fila->inicio + 1;
    fila->tamanho --;
    return valor;
}

int inicio (fila_t* fila) {
    if (vazia_f(fila)) exit(EXIT_FAILURE);
    int inicio_fila = fila->elementos[fila->inicio];
    return inicio_fila;
}

int fim (fila_t* fila) {
    if (vazia_f(fila)) exit(EXIT_FAILURE);
    int fim_corrigido = fila->fim - 1;
    if (fim_corrigido < 0) fim_corrigido = fila->capacidade - 1;
    return fila->elementos[fim_corrigido];
}

bool vazia_f (fila_t* fila) {
    return fila->tamanho == 0;
}

bool cheia (fila_t* fila) {
    return fila->tamanho >= fila->capacidade;
}

int destruir_fila (fila_t* fila) {
    free(fila->elementos);
    free(fila);

    return 0;
}