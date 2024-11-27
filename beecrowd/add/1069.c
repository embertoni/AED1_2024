/*
  Enrico Manzolli Bertoni RA: 176259
  1069.c - Diamonds and Sand
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000

typedef struct Stack{
    int count;
} Stack;

void startStack(Stack* stack){
    stack->count = 0;
}

int countDmd(char *inp){
    Stack stack;
    startStack(&stack);
    int dmd = 0;
    for (int i = 0; inp[i] != '\0'; i++){
        if (inp[i] == '<'){
            stack.count++;
        }
        else if (inp[i] == '>'){
            if (stack.count > 0){
                stack.count--;
                dmd++;
            }
        }
    }
    return dmd;
}

int main(){
    int n;
    scanf("%i", &n);
    getchar();
    for (int i = 0; i < n; i++){
        char input[M];
        fgets(input, M, stdin);
        input[strcspn(input, "\n")] = '\0';
        int dmd = countDmd(input);
        printf("%i\n", dmd);
    }
    return 0;
}
