#include <stdio.h>

#define M 9

int validaS(int mtx[M][M]){
    int lin[M][M] = {0};
    int col[M][M] = {0};
    int txt[M][M] = {0};

    for (int i = 0; i < M; i++){
        for (int j = 0; j < M; j++){
            int num = mtx[i][j];
            if (num < 1 || num > 9){
                return 0;
            }
            int index = (i / 3) * 3 + (j / 3);
            if (lin[i][num - 1] || col[j][num - 1] || txt[index][num - 1]){
                return 0;
            }
            lin[i][num - 1] = 1;
            col[j][num - 1] = 1;
            txt[index][num - 1] = 1;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int k = 1; k <= n; k++){
        int mtx[M][M];
        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                scanf("%i", &mtx[i][j]);
            }
        }
        printf("Instancia %i\n", k);
        if (validaS(mtx)){
            printf("SIM\n");
        }
        else {
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;
}
