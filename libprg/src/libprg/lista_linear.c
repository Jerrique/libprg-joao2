//
// Created by aluno on 02/04/2026.
//

#include <stdbool.h>
#include <stdlib.h>
#include <libprg/libprg.h>


typedef struct lista_linear {
    int* elemento;
    int tamanho;
    int capacidade;
    bool ordenada;
}lista_linear_t;

lista_linear_t criar_lista (int capacidade, bool ordenada) {
    lista_linear_t* lista_linear = malloc(sizeof(lista_linear_t));
    lista_linear->elemento = malloc(sizeof(int)*capacidade);
    lista_linear->tamanho = 0;
    return lista_linear;
}

//inserir
//remover
//buscar
//alterar
//ordenar
//combinar
//destruir