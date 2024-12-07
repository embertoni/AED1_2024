#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *v, int n){
    int i, j, index;

    for (i = 1; i < n; i++){
        index = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > index){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = index;
    }
}

double tempoExecucao(int *v, int n){
    clock_t inicio, fim;
    inicio = clock();
    insertionSort(v, n);
    fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

int main(){
    int i, j;
    int tam;
    double tempT;
    double mTempo;

    printf("Tamanho\tInsertionSort\n");
    for (tam = 20000; tam <= 400000; tam += 20000){
        tempT = 0;
        for (j = 0; j < 3; j++){
            int *v = (int *)malloc(tam * sizeof(int));
            for (i = 0; i < tam; i++){
                v[i] = rand() % 100000;
            }
            tempT += tempoExecucao(v, tam);
            free(v);
        }
        mTempo = tempT / 3;
        printf("%d\t%.5f\n", tam, mTempo);
    }
    return 0;
}
