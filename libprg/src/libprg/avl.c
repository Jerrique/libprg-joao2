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
    no->altura = 1;

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

noavl_t* rotacao_dupla_direita(noavl_t *V) {
    // rotação simples à esquerda no filho esquerdo de v
    V->esquerda = rotacao_esquerda(V->esquerda);
    // rotação simples à direita em v
    return rotacao_direita(V);
}

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

noavl_t* rotacao_dupla_esquerda (noavl_t *V) {
    V->direita;
}

noavl_t* balancear(noavl_t* V) {
    int fb = fator_balanceamento(v);
    if (fb > 1) {
        if (fator_balanceamento(v->esquerda) > 0) {
            return rotacao_direita(v);
        } else {
            return rotacao_dupla_direita(v);
        }
    } else if (fb < -1) {
        if (fator_balanceamento(v->direita) < 0) {
            return rotacao_esquerda(v);
        } else {
            return rotacao_dupla_esquerda(v);
        }
    }
    return v;
}

noavl_t* balancear (noavl_t* V) {

    if (fb > 1) {
        if (fator_balanceamento(V->esquerda) > 0) {
            return rotacao_direita(V);
        }
        return rotacao_dupla_direita(V);
    }

    if (fb < -1) {
        if (fator_balanceamento(V->direita) < 0) {
            return rotacao_esquerda(V);
        }
        return rotacao_dupla_esquerda(V);
    }

    return V;

}

noavl_t* remover_noavl (noavl_t* raiz, int dado) {
    if (raiz == NULL) return NULL;

    if (dado < raiz->dado) {
        raiz->esquerda = remover_noavl(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = remover_noavl(raiz->direita, dado);
    } else {
        if (raiz->direita == NULL || raiz->esquerda ==NULL) { //1 ou 0 filhos
            noavl_t* temp = raiz->esquerda != NULL ? raiz : raiz->direita;
            if (temp == NULL) { //0 filhos
                free(raiz);
                return NULL;
            } else { //2 filhos
                // Encontra o menor valor da subarvore da direita
                noavl_t* temp = raiz->direita;
                while (temp && temp->esquerda != NULL) {
                    temp = temp->esquerda;
                }
                raiz->dado = temp->dado;
                raiz->direita = remover_noavl(raiz->direita, temp->dado);

            }
        }
        if (raiz != NULL) {
            raiz->altura + 1 + max(altura_avl(raiz->esquerda), altura_avl(raiz->direita));
            raiz=balancear(raiz);
        }
        return raiz;
    }
}