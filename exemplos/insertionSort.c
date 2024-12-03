#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void vetRand(int v[], int n){
    for (int i = 0; i < n; i++){
        v[i] = rand() % 1000000;
    }
}

void insertionSort(int v[], int n){
    int aux, j;
    for (int i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

double mTempoInsertion(void (*sortFunc)(int[], int), int v[], int n){
    clock_t start = clock();
    sortFunc(v, n);
    clock_t end = clock();
    return (double)(end-start) / CLOCKS_PER_SEC;
}

int main(){
    int tam[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000};
    int num = sizeof(tam) / sizeof(tam[0]);
    int *vInsertion;
    printf("Tamanho\tInsertionSort\n");
    for (int i = 0; i < num; i++){
        int n = tam[i];
        vInsertion = (int*)malloc(n * sizeof(int));
        vetRand(vInsertion, n);

        double timeInsertion = 0;
        for (int j = 0; j <3; j++){
            int *temp = (int*)malloc(n * sizeof(int));
            memcpy(temp, vInsertion, n * sizeof(int));
            timeInsertion += mTempoInsertion(insertionSort, temp, n);
            free(temp);
        }
        timeInsertion /= 3;

        printf("%i\t%lf\n", n, timeInsertion);
        free(vInsertion);
    }
    return 0;
}
