#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void vetRand(int v[], int n){
    for (int i = 0; i < n; i++){
        v[i] = rand() % 1000000;
    }
}

void merge(int v[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++){
        L[i] = v[l+i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = v[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int v[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l , m, r);
    }
}

double mTempoMerge(void (*sortFunc)(int[], int, int), int v[], int n){
    clock_t start = clock();
    sortFunc(v, 0, n-1);
    clock_t end = clock();
    return (double)(end-start) / CLOCKS_PER_SEC;
}

int main(){
    int tam[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000};
    int num = sizeof(tam) / sizeof(tam[0]);
    int *vMerge;
    printf("Tamanho\tMergeSort\n");
    for (int i = 0; i < num; i++){
        int n = tam[i];
        vMerge = (int*)malloc(n * sizeof(int));
        vetRand(vMerge, n);
        
        double timeMerge = 0;
        for (int j = 0; j < 3; j++){
            int *temp = (int*)malloc(n * sizeof(int));
            memcpy(temp, vMerge, n * sizeof(int));
            timeMerge += mTempoMerge(mergeSort, temp, n);
            free(temp);
        }
        timeMerge /= 3;

        printf("%i\t%lf\n", n, timeMerge);
        free(vMerge);
    }
    return 0;
}
