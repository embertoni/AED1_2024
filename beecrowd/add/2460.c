#include <stdio.h>
#include <stdlib.h>

typedef struct Pess{
    int num;
    int pos;
    struct Pess* next;
} Pess;

Pess* cPess(int num, int pos){
    Pess* n_pess = (Pess*)malloc(sizeof(Pess));
    n_pess->num = num;
    n_pess->pos = pos;
    n_pess->next = NULL;
    return n_pess;
}

void inserePess(Pess** fst, Pess** lst, int num, int pos){
    Pess* n_pess = cPess(num, pos);
    if (*fst == NULL){
        *fst = *lst = n_pess;
    }
    else {
        (*lst)->next = n_pess;
        *lst = n_pess;
    }
}

void removePess(Pess** fst, int num){
    Pess* temp = *fst;
    Pess* prev = NULL;

    while (temp != NULL && temp->num != num){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        return;
    }
    if (prev == NULL){
        *fst = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
}

void printF(Pess* fst){
    int vrf = 0;
    Pess* temp = fst;
    while (temp != NULL){
        if (vrf){
            printf(" ");
        }
        printf("%i", temp->num);
        vrf = 1;
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int nPess, nPess_out;
    int idPess;
    Pess* fila = NULL;
    Pess* lst = NULL;
    scanf("%i", &nPess);
    for (int i = 0; i < nPess; i++){
        scanf("%i", &idPess);
        inserePess(&fila, &lst, idPess, i);
    }
    scanf("%i", &nPess_out);
    for (int i = 0; i < nPess_out; i++){
        scanf("%i", &idPess);
        removePess(&fila, idPess);
    }
    printF(fila);
    return 0;
}
