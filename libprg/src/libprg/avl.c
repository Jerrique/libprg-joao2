//
// Created by aluno on 26/05/2026.
//
#include <libprg.h>
#include <stdlib.h>

#define max(a, b) (a > b ? a : b);

typedef struct noavl {
    int dado;
    noavl_t *esquerda;
    noavl_t *direita;
    int altura;
} noavl_t;

noavl_t *criar_noavl(int dado) {
    noavl_t *no = malloc(sizeof(noavl_t));
    no->dado = dado;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 0;

    return no;
}

int altura_avl(noavl_t *raiz) {
    if (raiz == NULL) return 0;

    return raiz->altura;
}

int fator_balanceamento(noavl_t *raiz) {
    if (raiz == NULL) return 0;

    return altura_avl(raiz->esquerda) - altura_avl(raiz->direita) + 1;
}

noavl_t *adicionar_noavl(noavl_t *raiz, int dado) {
    if (raiz == NULL) {
        return criar_noavl(dado);
    }

    if (raiz->dado < dado) {
        raiz->direita = adicionar_noavl(raiz->direita, dado);
    }

    if (raiz->dado > dado) {
        raiz->esquerda = adicionar_noavl(raiz->esquerda, dado);
    }


    return raiz;
}

noavl_t *rotacao_direita(noavl_t *V) {
    noavl_t *U = V->esquerda;
    noavl_t *T2 = U->direita;

    U->direita = V;
    V->esquerda = T2;

    V->altura = max(altura_avl(V->esquerda), altura_avl(V->direita)) +1;
    U->altura = max(altura_avl(U->esquerda), altura_avl(U->direita)) +1;

    return U;
}

//rotacao_dupla_direita
noavl_t *rotacao_esquerda(noavl_t *V) {
    noavl_t *U = V->direita;
    noavl_t *T2 = U->esquerda;

    U->esquerda = V;
    V->direita = T2;

    V->altura = max(altura_avl(V->esquerda), altura_avl(V->direita))
    +1;
    U->altura = max(altura_avl(U->esquerda), altura_avl(U->direita))
    +1;

    return U;
}

//rotacao_dupla_esquerda
//balancear
