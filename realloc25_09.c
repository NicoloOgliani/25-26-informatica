/*scrivere un programma in linguaggio c che:
1. allochi dinamicamente un array iniziale di n numeri con malloc
2. inserimento dei valori
3. stampa array
4. calcola la somma degli elementi multipli di 3
5. creiamo un nuovo array contenente solo valori dispari */
#include <stdio.h>
#include <stdlib.h>
int* creaVett(int _n){
    int* _array1=NULL;
    _array1=(int*)malloc(_n*sizeof(int));
    if(_array1==NULL){
        printf("Errore di allocazione");
        exit (1);
    } 
    return _array1;
}
int* inserisciValori(int *_array1, int _n){
    for(int i=0; i<_n; i++){
        printf("Inserisci un valore: ");
        scanf("%d", &_array1[i]);
    }
    return _array1;
}
void stampaVett(int *_array1, int _n){
    printf("Hai inserito i seguenti elementi: ");
    for(int i=0; i<_n; i++){
        printf("%d ", _array1[i]);
    }
    printf("\n");
}
int sommaMultipli(int *_array1, int _n){
    int somma=0, cnt=0;
    for(int i=0; i<_n; i++){
        if(_array1[i]%3==0){
            cnt++;
            somma=somma+_array1[i];
        }

    }
    printf("Gli elementi multipli di 3 sono %d e la loro somma è %d", cnt, somma);
}
int* creanuovoVett(int _n){
    int* _array2=NULL;
    _array2=(int*)malloc(_n*sizeof(int));
    if(_array2==NULL){
        printf("Errore di allocazione");
        exit (1);
    } 
    return _array2;
}
void controlloValori(int *_array2, int _n){
    for(int i=0; i<_n; i++){
        if(_array2[i]%2==0){
            _array2=(int*)realloc(_array2, (_n-1)*sizeof(int));
            if(_array2==NULL){
                printf("Errore di allocazione");
            exit (1);
            }
        }
        else{
            printf("%d ", _array2[i]);
        }
    }
}
int main(){
    int *array1=NULL;
    int *array2=NULL;
    int n=0;
    
    array1=creaVett(n);
    array1=inserisciValori(array1, n);
    stampaVett(array1, n);
    sommaMultipli(array1, n);
    array2=creanuovoVett(n);
    controlloValori(array2, n);
    free(array1);
    free(array2);
    return 0;
}