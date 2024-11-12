#include <stdio.h>

int main(){
    int T1, T2, T3, T4;
    scanf("%i %i %i %i", &T1, &T2, &T3, &T4);
    int total = (T1 - 1) + (T2 - 1) + (T3 - 1) + (T4 - 1) + 1;
    printf("%i\n", total);
    return 0;
}