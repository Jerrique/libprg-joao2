//
// Created by aluno on 02/04/2026.
//

#include <stdbool.h>
#include <stdlib.h>
#include <libprg/libprg.h>


typedef struct lista_linear {
    int* elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
}lista_linear_t;

lista_linear_t *criar_lista (int capacidade, bool ordenada) {
    lista_linear_t* lista_linear = malloc(sizeof(lista_linear_t));
    if (lista_linear == NULL) {
        return NULL;
    }
    lista_linear->elementos = malloc(sizeof(int)*capacidade);
    if (lista_linear->elementos == NULL) {
        free(lista_linear);
        return NULL;
    }
    lista_linear->tamanho = 0;
    lista_linear->capacidade = capacidade;
    lista_linear->ordenada = ordenada;

    return lista_linear;
}

int inserir (lista_linear_t* lista_linear, int valor) {
    if (lista_linear->tamanho > lista_linear->capacidade) {
        exit(EXIT_FAILURE);
    }
    lista_linear->elementos[lista_linear->tamanho] = valor;
    lista_linear->tamanho ++;
    return 0;
}

int remover (lista_linear_t* lista_linear, int valor) {
    //SE ORDENADA
    if (lista_linear->ordenada == 1) {
        for (int i = lista_linear->elementos[lista_linear->tamanho]; i != valor; i--) //SE TIVER MAIS DE UM VALOR IGUAL???????????????
        {
            if (lista_linear->elementos[i] == valor) {
                lista_linear->elementos[lista_linear->tamanho - 1] = lista_linear->elementos[i]; //SE O ULTIMO ELEMENTO QUE FOR O RETIRADO???????
            }
        }
        lista_linear->tamanho--;
    }
    //NÃO ORDENADA
    else {

    }
    return valor;
}

//buscar
//alterar
//ordenar
//combinar
//destruir;