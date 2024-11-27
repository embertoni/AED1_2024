/*
  Enrico Manzolli Bertoni RA: 176259
  2006 - Identifying Tea
*/

#include <stdio.h>

int main(){
    int T;
    int p[5];
    int win = 0;
    scanf("%i", &T);
    for (int i = 0; i < 5; i++){
        scanf("%i", &p[i]);
        if (p[i] == T){
            win++;
        }
    }
    printf("%i\n", win);
}
