#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
