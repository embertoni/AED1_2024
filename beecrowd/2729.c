#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 1000
#define L 21

typedef struct Item{
    char plv[L];
    struct Item* next;
} Item;

int cmp_item(const void* a, const void* b){
    return strcmp(((Item*)a)->plv, ((Item*)b)->plv);
}

int repete(Item* fst, const char* plv){
    Item* atual = fst;
    while (atual != NULL){
        if (strcmp(atual->plv, plv) == 0){
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

void add(Item** fst, const char* plv, int* count){
    if (*count >= M){
        return;
    }
    if (repete(*fst, plv)){
        return;
    }
    Item* novo = (Item*)malloc(sizeof(Item));
    strcpy(novo->plv, plv);
    novo->next = NULL;
    if (*fst == NULL){
        *fst = novo;
    }
    else {
        Item* atual = *fst;
        while (atual->next != NULL){
            atual = atual->next;
        }
        atual->next = novo;
    }
    (*count)++;
}

void sort(Item** fst){
    int count = 0;
    Item* atual = *fst;
    while (atual != NULL){
        count++;
        atual = atual->next;
    }
    if (count <= 1){
        return;
    }
    Item* vet[count];
    atual = *fst;
    for (int i = 0; atual != NULL; i++){
        vet[i] = atual;
        atual = atual->next;
    }
    qsort(vet, count, sizeof(Item*), cmp_item);
    for (int i = 0; i < count-1; i++){
        vet[i]->next = vet[i+1];
    }
    vet[count-1]->next = NULL;
    *fst = vet[0];
}

void printl(Item* fst){
    Item* atual = fst;
    while (atual != NULL){
        printf("%s", atual->plv);
        if (atual->next != NULL){
            printf(" ");
        }
        atual = atual->next;
    }
    printf("\n");
}

void freelist(Item* fst){
    Item* atual = fst;
    while (atual != NULL){
        Item* aux = atual;
        atual = atual->next;
        free(aux);
    }
}

int main(){
    int n;
    scanf("%i", &n);
    getchar();
    while (n--){
        Item* fst = NULL;
        int count = 0;
        char lin[1000];
        fgets(lin, sizeof(lin), stdin);
        char* token = strtok(lin, " \n");
        while (token != NULL){
            add(&fst, token, &count);
            token = strtok(NULL, " \n");
        }
        sort(&fst);
        printl(fst);
        freelist(fst);
    }
    return 0;
}
