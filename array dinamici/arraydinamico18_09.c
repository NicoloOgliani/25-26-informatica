/*Scrivere un programma in C che gestisca un insieme di array interi usando un array dinamico.
Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l’array con realloc)
    2. Visualizzare tutti i array
    3. Cercare un numero specifico
    4. Ordinare i array in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int *array = NULL;
    int scelta, numero, i, j, trovato, n = 10;
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Errore di allocazione della memoria\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }
    do {
        printf("Menu:\n");
        printf("1. Aggiungere un numero\n");
        printf("2. Visualizzare tutti i numeri\n");
        printf("3. Cercare un numero specifico\n");
        printf("4. Ordinare i array in ordine crescente\n");
        printf("5. Eliminare un numero scelto\n");
        printf("6. Uscire\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                printf("Inserisci il numero da aggiungere: ");
                scanf("%d", &numero);
                n++;
                array=(int *)realloc(array, n * sizeof(int));
                if (array == NULL) {
                    printf("Errore di allocazione");
                    return 1;
                }
                array[n - 1] = numero;
                printf("numeri nell'array: ");
                for(i=0; i<n; i++){
                    printf("%d ", array[i]);
                }
                break;
            case 2:
                printf("numeri nell'array: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            case 3:
                printf("Inserisci il numero: ");
                scanf("%d", &numero);
                trovato = 0;
                for (i = 0; i < n; i++) {
                    if (array[i] == numero) {
                        trovato = 1;
                        break;
                    }
                }
                if (trovato==1) {
                    printf("Numero %d trovato.", numero);
                } else {
                    printf("Numero %d non trovato", numero);
                }
                break;
            case 4:
                for (i = 0; i < n - 1; i++) {
                    for (j = i + 1; j < n; j++) {
                        if (array[i] > array[j]) {
                            int temp = array[i];
                            array[i] = array[j];
                            array[j] = temp;
                        }
                    }
                }
                printf("numeri in ordine crescente");
                for (i = 0; i < n; i++) {
                    printf("%d ", array[i]);
                }
                break;
            case 5:
                printf("Inserisci il numero da eliminare: ");
                scanf("%d", &numero);
                trovato = 0;
                for (i = 0; i < n; i++) {
                    if (array[i] == numero) {
                        trovato = 1;
                        break;
                    }
                }
                if (trovato==1) {
                    for (j = i; j < n - 1; j++) {
                        array[j] = array[j + 1];
                    }
                    n--;
                    array = (int *)realloc(array, n * sizeof(int));
                    if (array == NULL && n > 0) {
                        printf("Errore di allocazione");
                        return 1;
                    }
                    printf("Numero %d eliminato.", numero);
                } else {
                    printf("Numero %d non trovato.", numero);
                }
                printf("numeri nell'array definitivo: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", array[i]);
                }
                break;
            case 6:
                printf("Uscita dal programma");
                break;
            default:
                printf("Opzione non valida");
        }
    } while (scelta <1 || scelta>6);
    free(array);
    return 0;


}