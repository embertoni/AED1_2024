/*
  Enrico Manzolli Bertoni RA: 176259
  1068 - Parenthesis Balance I
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1000

typedef struct Input{
    char chc;
    struct Input* next;
} Input;

typedef struct Stack{
    Input* last;
} Stack;

void startStack(Stack* stack){
    stack->last = NULL;
}

void push(Stack* stack, int chc){
    Input* n_char = (Input*)malloc(sizeof(Input));
    n_char->chc = chc;
    n_char->next = stack->last;
    stack->last = n_char;
}

int pop(Stack* stack){
    if (stack->last == NULL){
        return -1;
    }
    Input* temp = stack->last;
    int chc = temp->chc;
    stack->last = temp->next;
    free(temp);
    return chc;
}

int checkEmpty(Stack* stack){
    return stack->last == NULL;
}

int checkP(char *inp){
    Stack stack;
    startStack(&stack);
    for (int i = 0; inp[i] != '\0'; i++){
        if (inp[i] == '('){
            push(&stack, i);
        }
        else if (inp[i] == ')'){
            if (checkEmpty(&stack)){
                return 0;
            }
            pop(&stack);
        }
    }
    return checkEmpty(&stack) ? 1 : 0;
}

int main(){
    char input[M];

    while(fgets(input, M, stdin) != NULL){
        input[strcspn(input, "\n")] = '\0';
        if (checkP(input)){
            printf("correct\n");
        }
        else {
            printf("incorrect\n");
        }
    }
    return 0;
}
