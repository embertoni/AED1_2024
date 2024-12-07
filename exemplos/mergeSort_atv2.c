#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *v, int *temp, int l, int m, int r){
    int i = l, j = m + 1, k = l;

    while (i <= m && j <= r){
        if (v[i] <= v[j]){
            temp[k++] = v[i++];
        }
        else {
            temp[k++] = v[j++];
        }
    }
    while(i <= m){
        temp[k++] = v[i++];
    }
    while (j <= r){
        temp[k++] = v[j++];
    }
    for (i = l; i <= r; i++){
        v[i] = temp[i];
    }
}

void mergeSortRec(int *v, int *temp, int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        mergeSortRec(v, temp, l, m);
        mergeSortRec(v, temp, m + 1, r);
        merge(v, temp, l, m, r);
    }
}

void mergeSort(int *v, int n){
    int *temp = (int *)malloc(n * sizeof(int));
    mergeSortRec(v, temp, 0, n - 1);
    free(temp);
}

double tempoExecucao(int *v, int n){
    clock_t start, end;
    start = clock();
    mergeSort(v, n);
    end = clock();
    return ((double)(end-start)) / CLOCKS_PER_SEC;
}

int main(){
    int i, j;
    int tam;
    double tempT;
    double mTempo;
    
    printf("Tamanho\tMergeSort\n");
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
