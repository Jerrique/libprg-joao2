//
// Created by aluno on 19/05/2026.
//

#include <stdio.h>
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

nobin_t* remover_nobin (nobin_t* raiz, int dado) {
    if (raiz == NULL) return NULL;

    if (dado < raiz->dado) {
        raiz->proximo_menor = remover_nobin(raiz->proximo_menor, dado);
    } else if (dado > raiz->dado) {
        raiz->proximo_maior = remover_nobin(raiz->proximo_maior, dado);
    } else {
        if (raiz->proximo_maior == NULL || raiz->proximo_menor ==NULL) { //1 ou 0 filhos
            nobin_t* temp = raiz->proximo_menor != NULL ? raiz : raiz->proximo_maior;
            if (temp == NULL) { //0 filhos
                free(raiz);
                return NULL;
            } else { //2 filhos
                // Encontra o menor valor da subarvore da direita
                nobin_t* temp = raiz->proximo_maior;
                while (temp && temp->proximo_menor != NULL) {
                    temp = temp->proximo_menor;
                }
                raiz->dado = temp->dado;
                raiz->proximo_maior = remover_nobin(raiz->proximo_maior, temp->dado);

            }
        }
    }
}

//destruir

void travessia_preordem (nobin_t* raiz) {
    if (raiz != NULL) {
        printf("%d", raiz->dado);
        travessia_emordem(raiz->proximo_menor);
        travessia_emordem(raiz->proximo_maior);
    }
}

void travessia_emordem (nobin_t* raiz) {
    if (raiz != NULL) {
        travessia_emordem(raiz->proximo_menor);
        printf("%d", raiz->dado);
        travessia_emordem(raiz->proximo_maior);
    }
}

void travessia_posordem (nobin_t* raiz) {
    if (raiz != NULL) {
        travessia_emordem(raiz->proximo_menor);
        travessia_emordem(raiz->proximo_maior);
        printf("%d", raiz->dado);
    }
}
