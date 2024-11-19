#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000

int potmu(int x){
    if (x%2 == 0){
        return 1;
    }
    else {
        return -1;
    }
}

int RandomInteger(int low, int high){
    int k;
    srand((unsigned)time(NULL));
    k = (rand()%high)+low;
    return k;
}

void bubbleSort(int v[TAM]){
    int a, b, aux;
    for (a = TAM-1; a >= 1; a--){
        for (b = 0; b < a; b++){
            if (v[b] > v[b+1]){
                aux = v[b];
                v[b] = v[b+1];
                v[b+1] = aux;
            }
        }
    }
}

int main(){
    clock_t t;
    int vetor[TAM];
    int p, r, a;
    p = 0;
    r = TAM;
    for (a = 0; a < TAM; a++){
        vetor[a] = (potmu(a)*(a*a+1));
    }
    for (int i = 0; i < 10; i++){
        printf("%i ", vetor[i*9]);
    }
    printf("\n");
    t = clock();
    bubbleSort(vetor);
    for (int i = 0; i < 10; i++){
        printf("%i ", vetor[i*9]);
    }
    printf("\n");
    t = clock() - t;
    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
}
