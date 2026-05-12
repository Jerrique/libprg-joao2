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


int* merge (int* vetor, int esquerda, int meio, int direita) {
    int aux [direita - esquerda + 1];
    int i = esquerda, j = meio + 1, k = 0;
    while (i <= meio && j <= direita) {
        if (vetor[i] <= vetor[j]) {
            aux[k] = vetor[i];
            i++;
        } else {
            aux[k] = vetor[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= meio) {
        aux[k] = vetor[i];
        i = i + 1, k = k + 1;
    }
    while (j <= direita) {
        aux[k] = vetor[i];
        j = j + 1, k = k + 1;
    }
    for (i = esquerda; i <= direita; i++) {
        vetor[i] = aux[i - esquerda];
    }
    return vetor;
}

int* merge_sort (int* vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
    return vetor;
}




