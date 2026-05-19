//
// Created by aluno on 19/05/2026.
//

#include <stdlib.h>

#include "libprg.h"

typedef struct nobin {
    int dado;
    nobin_t *proximo_menor; //nobin_t *esquerda;
    nobin_t *proximo_maior; //nobin_t *direita;
} nobin_t;


nobin_t* criar_nobin (int dado) {
    nobin_t* no = malloc(sizeof(nobin_t));
    no->dado = dado;
    no->proximo_menor = NULL;
    no->proximo_maior = NULL;

    return no;
}

nobin_t* adicionar_nobin (nobin_t* raiz, int dado) {
    if (raiz == NULL) {
        return criar_nobin(dado);
    }

    if (raiz->dado < dado) {
        raiz->proximo_maior = adicionar_nobin(raiz->proximo_maior, dado);
    }

    if (raiz->dado > dado) {
        raiz->proximo_menor = adicionar_nobin(raiz->proximo_menor, dado);
    }


    return raiz;
}

//remover
//destruir