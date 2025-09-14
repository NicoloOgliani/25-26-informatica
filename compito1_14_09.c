/*Data una matrice di valori scambiare gli elementi della diagonale principale con la diagonale secondaria.*/
#include <stdio.h>

#define R 3
#define C 3

void LeggiMatrice(int mat[R][C]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("Inserisci l'elemento in posizione [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void StampaMatrice(int mat[R][C]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void ScambiaDiagonali(int mat[R][C]){
    for(int i = 0; i < R; i++){
        int temp = mat[i][i];
        mat[i][i] = mat[i][C - 1 - i];
        mat[i][C - 1 - i] = temp;
    }
}

int main(){
    int mat[R][C];
    LeggiMatrice(mat);
    printf("Matrice inserita:\n");
    StampaMatrice(mat);

    ScambiaDiagonali(mat);
    printf("Matrice con diagonali scambiate:\n");
    StampaMatrice(mat);

    return 0;
}
