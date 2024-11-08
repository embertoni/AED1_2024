#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpString(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    for (int i = 0; i < N; i++){
        char lin[10000];
        fgets(lin, sizeof(lin), stdin);
        lin[strcspn(lin, "\n")] = 0;
        char *plvs[1000];
        int plvCount = 0;
        char *token = strtok(lin, " ");
        while (token != NULL){
            int isRepet = 0;
            for (int j = 0; j < plvCount; j++){
                if (strcmp(plvs[j], token) == 0){
                    isRepet = 1;
                    break;
                }
            }
            if (!isRepet){
                plvs[plvCount++] = token;
            }
            token = strtok(NULL, " ");
        }
        qsort(plvs, plvCount, sizeof(char *), cmpString);
        for (int i = 0; i < plvCount; i++){
            if (i > 0){
                printf(" ");
            }
            printf("%s", plvs[i]);
        }
        printf("\n");   
    }
    return 0;
}