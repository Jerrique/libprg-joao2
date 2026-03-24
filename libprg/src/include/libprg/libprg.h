#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

 /*---    PILHA   ---*/
    typedef struct pilha_t pilha_t;
     pilha_t* criar_pilha(int capacidade);
    int empilhar(pilha_t* pilha, int valor);
    int desempilhar (pilha_t* pilha);

#endif
