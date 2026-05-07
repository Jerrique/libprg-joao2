//
// Created by aluno on 07/05/2026.
//

#include "libprg.h"

int* bubble_sort (int* vetor, int tamanho) {



    for (int i = 1; i < tamanho; i++) {
        for (int j = 1; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor [j];
                vetor[j] = vetor [j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    return vetor;
}






//inserction_sort
//selection_sort