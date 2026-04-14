#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>

 /*---    PILHA   ---*/
    typedef struct pilha pilha_t;
     pilha_t* criar_pilha(int capacidade);
    int empilhar(pilha_t* pilha, int valor);
    int desempilhar (pilha_t* pilha);
    int tamanho (pilha_t* pilha);
    bool vazia_p (pilha_t* pilha);
    int destruir_pilha (pilha_t* pilha);

 /*---   FILA   ---*/
    typedef struct fila fila_t;
    fila_t* criar_fila (int capacidade);
    void enfileirar (fila_t* fila, int valor);
    int desenfileirar (fila_t* fila);
    int inicio (fila_t* fila);
    int fim (fila_t* fila);
    bool vazia_f (fila_t* fila);
    bool cheia (fila_t* fila);
    int destruir_fila (fila_t* fila);

 /*---   LISTAS   ---*/
    typedef struct lista_linear lista_linear_t;
    lista_linear_t *criar_lista (int capacidade, bool ordenada);
    int inserir (lista_linear_t* lista_linear, int valor);
    int remover (lista_linear_t* lista_linear, int valor);
    //ORDENADA

    //NÃO ORDENADA


#endif
