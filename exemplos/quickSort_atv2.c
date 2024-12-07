#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa(int *v, int l, int r){
    int index = v[r];
    int i = l - 1;
    
    for (int j = l; j < r; j++){
        if (v[j] <= index) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[r];
    v[r] = temp;
    return i + 1;
}

void quickSortRec(int *v, int l, int r){
    if (l < r){
        int index = Separa(v, l, r);
        quickSortRec(v, l, index - 1);
        quickSortRec(v, index + 1, r);
    }
}

void quickSort(int *v, int n){
    quickSortRec(v, 0, n - 1);
}

double tempoExecucao(int *v, int n){
    clock_t start, end;
    start = clock();
    quickSort(v, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main(){
    int i, j;
    int tam;
    double tempT;
    double mTempo;
    
    printf("Tamanho\tQuickSort\n");
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
