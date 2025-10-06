/*Scrivi un programma in c che gestisca un insieme di numeri interi 
usando un array dinamico. Il programma deve permettere:
1. aggiungere un numero (con realloc)
2. visualizzare tutti i numeri
3. cercare un numero specifico
4. ordinare i numeri in ordine crescente
5. eliminare un numero scelto
6. uscire*/
#include <stdio.h>
#include <stdlib.h>
int *creavett(int _n){
    int* _array=(int*)malloc(_n*sizeof(int));
    if(_array==NULL){
        printf("Errore di allocazione");
        exit (1);
    }
    return _array;
}
int *aggiungi(int _array, int _n, int _n1){
    _array=(int*)realloc(_n1*sizeof(int));
    printf("Inserisci il nuovo numero: ");
    scanf("%d", _array[_n1])

}

    
int main(){
    int *array=NULL, n=0, n1=n+1;
    printf("Quanti numeri vuoi  inserire: ");
    scanf("%d", &n);
    array=creavett(n);
}