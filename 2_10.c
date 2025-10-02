/*Scrivi un programma in c che:
1.chieda all'utente quanti numeri interi vuole inserire
2. alloca dinamicamente un array di quella dimensione con malloc
3. permetta all'utente di inserire i numeri
4. chieda all'utente se vuole aumentare la dimensione dell'array
  -se si, richiede la nuova dimensione e usa realloc() per ridimensionarlo
  -permette quindi di inserire i nuovi valori negli spazi aggiunti
5. infine stampi tutti gli elementi dell'array*/
#include <stdio.h>
#include <stdlib.h>
int *creaVett(int _n){
    int* _array1=(int*)malloc(_n*sizeof(int));
    if(_array1==NULL){
        printf("Errore di allocazione");
        exit (1);
    }
    return _array1;
}
void inserisciValori(int *_array1, int _n){
    for(int i=0; i<_n; i++){
        printf("Inserisci un valore: ");
        scanf("%d", &_array1[i]);
    }
}
void aumentaDimensione(int *_array1, int _n, int _n1){
    int scelta=0;
    printf("Vuoi aumentare la dimensione dell'array? se si inserisci 1 altrimenti 0");
    scanf("%d", &scelta);
    if(scelta==0){
        printf("Gli elementi dell'array sono: ");
        for(int i=0; i<_n; i++){
            printf("%d ", _array1[i]);
        }
        exit(1);
        
    }
    else{
        printf("Inserisci la nuova dimensione dell'array: ");
        scanf("%d", &_n1);
        int *tmp=realloc(_array1, _n1*sizeof(int));
        if(tmp==NULL){
            printf("Errore di allocazione");
            free(_array1);
            exit(1);
        }
        _array1=tmp;
        for(int i=_n; i<_n1; i++){
            printf("Inserisci un valore: ");
            scanf("%d", &_array1[i]);
        }
        printf("Gli elementi dell'array sono: ");
        for(int i=0; i<_n1; i++){
            printf("%d ", _array1[i]);
        }

        
        
    }
}
int main(){
    int* array1=NULL;
    int n=0;
    int n1=0;
    printf("Inserisci la quantità degli elementi: ");
    scanf("%d", &n);
    array1=creaVett(n);
    inserisciValori(array1, n);
    aumentaDimensione(array1, n, n1);
    free(array1);
    return 0;
}