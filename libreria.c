#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void stampaVettore(int vettore[], int dim, char sep){
    for(int i=0; i<dim; i++){
        printf("%d%c", vettore[i], sep);
    }
}
void riempiVettore(int vettore[], int dim){
    for(int i=0; i<dim; i++){
        printf("inserici l'elemento in posizione di %d: ", i);
        scanf("%d", &vettore[i]);
    }
}
void riempiVettoreCasuale(int vettore[], int dim, int minimo, int massimo){
    srand(time(NULL));
    for(int i=0; i<dim; i++){
        vettore[i]=rand()%(massimo-minimo+1)+minimo;
    }
}

int contaOccorrenze(int vettore[], int dim, int valore){
    int cnt=0;

    for(int i=0; i<dim; i++){
        if(vettore[i] == valore){
            cnt++;
        }
    }
    return cnt;
}



int ricercaSequenziale(int *vettore, int dim, int valore){
    for(int i = 0; i<dim; i++){
        if(vettore[i]==valore){
            return i;
        }
    }
    return -1;

}

int ricercaBinaria(int vettore[], int dim, int estInf, int estSup, int valore){
    int media = (estSup+estInf)/2;
    if(estInf > estSup)
        return -1;
    if(vettore[media]== valore)
        return media;
    if(vettore[media] > valore)
        return ricercaBinaria( vettore,dim, estInf, media-1, valore);
    else 
        return ricercaBinaria( vettore,dim, media+1, estSup, valore);
}

void shiftDx (int vett[], int dim, int pos){
    for(int i=dim; i>pos; i--){
        vett[i]=vett[i-1];
    }
}
int trovaPosizione (int vett[], int dim, int num){
    int i=0;
    while(vett[i]<num && i<dim){
        i++;
    }
    return i;
}

void riempiVettoreOrdinatoCasuale(int vett[], int dim, int minimo, int massimo) {
    srand(time(NULL));
    vett[0]=rand()%(massimo-minimo+1)+minimo;
    for(int i=1; i<dim; i++){
        vett[i]=rand()%(massimo-minimo+1)+minimo;
        int pos = trovaPosizione(vett, i, vett[i]);
        shiftDx(vett, i, pos);
        vett[pos]=vett[i];



    }
}
void bubbleSortC(int vett[], int dim){
    int temp;
    int flag=0;
    int i=0;
    while(flag==0){
        flag=1;
        for(int j=0; j<dim-1-i; j++){
            if(vett[j]>vett[j+1]){
                flag=0;
                temp=vett[j];
                vett[j]=vett[j+1];
                vett[j+1]=temp;
            }
        }
        i++;
    }
}
void bubbleSortD(int vett[], int dim){
    int temp;
    int flag=0;
    int i=0;
    while(flag==0){
        flag=1;
        for(int j=0; j<dim-1-i; j++){
            if(vett[j+1]>vett[j]){
                flag=0;
                temp=vett[j+1];
                vett[j+1]=vett[j];
                vett[j]=temp;
            }
        }
        i++;
    }
}
void scambioMinMax(int vett[], int dim){
    int min = 0;
    int max = 0;
    for(int i=0; i<dim; i++){
        if(vett[i]<vett[min]){
            min=i;
        }
        if(vett[i]>vett[max]){
            max=i;
        }
    }
    int temp = vett[min];
    vett[min]=vett[max];
    vett[max]=temp;
    
    
}void leggiMatrice(int righe, int colonne, int mat[righe][colonne]){
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("inserisci l'elemento in posizione [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void stampaMatrice(int righe, int colonne, int mat[righe][colonne]){
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void riempiMatriceCasuale(int righe, int colonne, int mat[righe][colonne], int minimo, int massimo){
    srand(time(NULL));
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            mat[i][j]=rand()%(massimo-minimo+1)+minimo;
        }
    }
}
void scambiaDiagonali(int dim, int mat[dim][dim]){
    for(int i=0; i<dim; i++){
        int temp = mat[i][i];
        mat[i][i]=mat[i][dim-1-i];
        mat[i][dim-1-i]=temp;
    }
}