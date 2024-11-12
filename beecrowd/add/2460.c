#include <stdio.h>
#include <stdlib.h>

#define MIDs 100001

typedef struct Pess{
    int id;
    struct Pess* next;
} Pess;

Pess* novaPess(int id){
    Pess* n_pess = (Pess*)malloc(sizeof(Pess));
    n_pess->id = id;
    n_pess->next = NULL;
    return n_pess;
}

void addPess(Pess** fst, int id){
    Pess* n_pess = novaPess(id);
    if (*fst == NULL){
        *fst = n_pess;
    }
    else {
        Pess* temp = *fst;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n_pess;
    }
}

void rmvPess(Pess** fst, int id){
    Pess* temp = *fst;
    Pess* prev = NULL;

    if (temp != NULL && temp->id == id){
        *fst = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->id != id){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void freeF(Pess* fst){
    Pess* temp;
    while (fst != NULL){
        temp = fst;
        fst = fst->next;
        free(temp);
    }
}

void printF(Pess* fst){
    Pess* temp = fst;
    int first = 1;
    while (temp != NULL){
        if (!first){
            printf(" ");
        }
        printf("%i", temp->id);
        temp = temp->next;
        first = 0;
    }
    printf("\n");
}

int main(){
    int N, M;
    scanf("%i", &N);
    Pess* fila = NULL;
    for (int i = 0; i < N; i++){
        int id;
        scanf("%i", &id);
        addPess(&fila, id);
    }
    scanf("%i", &M);
    int* sai = (int*)calloc(MIDs, sizeof(int));
    for (int i = 0; i < M; i++){
        int id;
        scanf("%i", &id);
        sai[id] = 1;
    }
    Pess* temp = fila;
    int first = 1;
    while (temp != NULL){
        if (!sai[temp->id]){
            if (!first){
                printf(" ");
            }
            printf("%i", temp->id);
            first = 0;
        }
        temp = temp->next;
    }
    printf("\n");
    freeF(fila);
    free(sai);
    return 0;
}
