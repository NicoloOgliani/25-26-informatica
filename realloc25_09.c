/*scrivere un programma in linguaggio c che:
 1. allochi dinamicamente un array iniziale di n numeri con malloc 
 2. inserimento dei valori 
 3. stampa array 
 4. calcola la somma degli elementi multipli di 3 
 5. creiamo un nuovo array contenente solo valori dispari */
#include <stdio.h>
#include <stdlib.h>

int* creaVett(int _n){
    int* _array1 = (int*)malloc(_n * sizeof(int));
    if(_array1 == NULL){
        printf("Errore di allocazione\n");
        exit(1);
    } 
    return _array1;
}

void inserisciValori(int *_array1, int _n){
    for(int i = 0; i < _n; i++){
        printf("Inserisci un valore [%d]: ", i + 1);
        scanf("%d", &_array1[i]);
    }
}

void stampaVett(int *_array1, int _n){
    printf("Hai inserito i seguenti elementi:\n");
    for(int i = 0; i < _n; i++){
        printf("%d ", _array1[i]);
    }
    printf("\n");
}

void sommaMultipli(int *_array1, int _n){
    int somma = 0, cnt = 0;
    for(int i = 0; i < _n; i++){
        if(_array1[i] % 3 == 0){
            cnt++;
            somma += _array1[i];
        }
    }
    printf("Gli elementi multipli di 3 sono %d e la loro somma è %d\n", cnt, somma);
}

int* creaVettDispari(int *_array1, int *_sizedispari, int _n){
    *_sizedispari=0;
    int *_dispari=NULL;
    int j = 0;
    for(int i = 0; i < _n; i++){
        if(_array1[i] % 2 != 0){
            (*_sizedispari)++;
            int *tmp=realloc(_dispari, (*_sizedispari)*sizeof(int));
            if(tmp==NULL){
                printf("Errore di allocazione");
                free(_dispari);
                return NULL;
            }
            _dispari=tmp;
            _dispari[(*_sizedispari)-1]=_array1[i];
        }
    }
    return _dispari;

}
void stampaVettd(int *_dispari, int _sizedispari){
    for(int i = 0; i < _sizedispari; i++){
        printf("%d ", _dispari[i]);
    }
    printf("\n");
    
}


int main(){
    int *array1 = NULL;
    int n = 0;
    int *dispari = NULL;
    int sizedispari=0;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);

    array1 = creaVett(n);
    inserisciValori(array1, n);
    stampaVett(array1, n);
    sommaMultipli(array1, n);

    dispari = creaVettDispari(array1, &sizedispari, n);
    printf("l'array contenente gli elementi dispari risulta: ");
    stampaVettd(dispari, sizedispari);
    free(array1);
    free(dispari);
    return 0;
}
