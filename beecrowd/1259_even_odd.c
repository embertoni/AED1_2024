/*
  Enrico Manzolli Bertoni RA: 176259
  1259 - Even and Odd
*/

#include <stdio.h>
#include <stdlib.h>

int cmp_par(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int cmp_impar(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}


int main(){
    int n;
    scanf("%i", &n);
    
    int num[n];
    int par[n], impar[n];
    int countp = 0, counti = 0;

    for (int i = 0; i < n; i++){
        scanf("%i", &num[i]);
        if (num[i]%2 == 0){
            par[countp++] = num[i];
        }
        else {
            impar[counti++] = num[i];
        }
    }
    qsort(par, countp, sizeof(int), cmp_par);
    qsort(impar, counti, sizeof(int), cmp_impar);
    for (int i = 0; i < countp; i++){
        printf("%i\n", par[i]);
    }
    for (int i = 0; i < counti; i++){
        printf("%i\n", impar[i]);
    }
    return 0;
}
