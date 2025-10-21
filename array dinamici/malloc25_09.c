/*creare un array dinamico chiedendo all'utente la sua dimensione
il programma deve prevedere le seguenti funzioni
1. crea l'array
2. inserire gli elementi nell'array
3. stampa dei valori
4. esci*/
#include <stdio.h>
#include <stdlib.h>

int* creaVett(int _n){
    int* _vettore=NULL;
    _vettore=(int*)malloc(_n*sizeof(int));
    if(_vettore==NULL){
        printf("Errore di allocazione!\n");
        return 1;
    }
    return _vettore;
}
int* inserisciValori(int *_vettore, int _n){
    for(int i=0; i<_n; i++){
        printf("Inserisci un valore: ");
        scanf("%d", &_vettore[i]);
    }
    return _vettore;
}
void stampaVett(int *_vettore, int _n){
    printf("Hai inserito i seguenti elementi: ");
    for(int i=0; i<_n; i++){
        printf("%d ", _vettore[i]);
    }
    printf("\n");
}
int main(){
    int *vettore=NULL;
    int n;
    do{ 
    printf("Inserisci la quantità degli elementi: ");
    scanf("%d", &n);
    }while(n<0);
    
    vettore=creaVett(n);
    vettore=inserisciValori(vettore, n);
    stampaVett(vettore, n);

    free(vettore);
    return 0;
}