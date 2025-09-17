/*caricare una matrice di quadrata con numeri in scala da 1 a 25 a spirale*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 5
void carica(int m[DIM][DIM]){
    int i, j, n=1;
    int inizio=0, fine=DIM-1;
    while(inizio<=fine){
        for(i=inizio; i<=fine; i++)
            m[inizio][i]=n++;
        for(i=inizio+1; i<=fine; i++)
            m[i][fine]=n++;
        for(i=fine-1; i>=inizio; i--)
            m[fine][i]=n++;
        for(i=fine-1; i>inizio; i--)
            m[i][inizio]=n++;
        inizio++;
        fine--;
    }
}
void stampa(int m[DIM][DIM]){
    int i, j;
    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}
int main(){
    int matrice[DIM][DIM];
    carica(matrice);
    stampa(matrice);
    return 0;
}