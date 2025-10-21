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
int *creavett(int *_n){
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", _n);
    int *array = (int*)malloc(*_n * sizeof(int));
    if (array == NULL) {
        printf("Errore di allocazione");
        exit(1);
    }
    for (int i = 0; i < *_n; i++) {
        printf("Inserisci i numeri: ");
        scanf("%d", &array[i]);
    }
    return array;
}

int *aggiungi(int *array, int *_n){
    array = (int*)realloc(array, (*_n + 1) * sizeof(int));
    if (array == NULL) {
        printf("Errore di allocazione");
        exit(1);
    }
    printf("Inserisci il nuovo numero: ");
    scanf("%d", &array[*_n]);
    (*_n)++;
    for (int i = 0; i < *_n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return array;
}


void stampaVett(int *array, int _n){
    for (int i = 0; i < _n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int cercaNumero(int *array, int _n){
    int num = 0;
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &num);
    for (int i = 0; i < _n; i++) {
        if (array[i] == num) {
            printf("Numero trovato in posizione %d\n", i);
            return i;
        }
    }
    printf("Numero non trovato\n");
    return -1;
}

void bubbleSort(int *array, int _n){
    for (int i = 0; i < _n - 1; i++) {
        for (int j = i + 1; j < _n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("Numeri in ordine crescente: ");
    for (int i = 0; i < _n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int *elimina(int *array, int *_n){
    int num = 0, trovato = 0;
    printf("Inserisci il numero da eliminare: ");
    scanf("%d", &num);
    for (int i = 0; i < *_n; i++) {
        if (array[i] == num) {
            for (int j = i; j < *_n - 1; j++) {
                array[j] = array[j + 1];
            }
            (*_n)--;
            trovato = 1;
            break;
        }
    }
    if (!trovato) {
        printf("Numero non trovato\n");
        return array;
    }
    array = (int*)realloc(array, (*_n) * sizeof(int));
    if (array == NULL && *_n > 0) {
        printf("Errore");
        exit(1);
    }
    printf("Numeri aggiornati: ");
    for (int i = 0; i < *_n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return array;
}

int main(){
    int *array = NULL, n = 0, scelta = 0;
    array = creavett(&n);
    printf("Menu:\n1 Aggiungi un numero\n2 Visualizza tutti i numeri\n3 Cerca un numero specifico\n4 Ordina i numeri in ordine crescente\n5 Elimina un numero scelto\n6 Esci\n");
    scanf("%d", &scelta);
    switch (scelta){
        case 1:{
            array = aggiungi(array, &n);
            break;
        }
        case 2:{
            stampaVett(array, n);
            break;
        }
        case 3:{
            cercaNumero(array, n);
            break;
        }
        case 4:{
            bubbleSort(array, n);
            break;
        }
        case 5:{
            array = elimina(array, &n);
            break;
        }
        case 6:{
            exit(0);
            break;
        }
        default:{
            printf("Scelta non valida\n");
        }
    }
    free(array);
    return 0;
}
