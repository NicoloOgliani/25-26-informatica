/*    Dichiarare un array di libri di dimensione massima N
    Consentire l'inserimento dei dati di un libro.
    Aggiornare correttamente il numero di copie disponibili.
    Registare il prestito di un libro:
        -inserendo la data di un prestito e la data di restituzione
        -decrementando il numero di copie disponibili
        -impedendo il prestito se non ci sono copie disponibili
    Visualizzare l'elenco completo dei libri con tutte le informazioni
    Visualizzare solo i libri attualmente in prestito(copie disponibili<copie totali)
    Cercare un libro tramite ISBN
    Stampare solo i libri con prestito scaduto
    Vincoli: accedere ai campi delle date tramite struct annidata
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Data{
    int giorno;
    int mese;
    int anno;
}Data;
typedef struct Libro{
    char titolo[20];
    char autore[20];
    int isbn;
    int copie_disponibili;
    int copie_totali;
    Data data_prestito;
    Data data_restituzione;
}Libro;
Libro* InserisciLibro(Libro* L, int* n){
    L=(Libro*)realloc(L, ((*n)+1)*sizeof(Libro));
    if(L==NULL){
        printf("Errore di allocazione");
        exit(1);
    }
}
int main(){
    Libro *biblioteca =NULL;
    int n=0, scelta;
    char c;

    do{
        printf("Menu: \n");
        printf("1. Inserisci un libro\n");
        printf("2. Visualizza tutti i libri\n");
        printf("3. Registra prestito\n");
        printf("4. Cerca libro per ISBN\n");
        printf("5. Visualizza libri in prestito\n");
        printf("6. Visualizza libri con prestito scaduto\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        while((c=getchar())!='\n'){}

        switch(scelta){
            case 0:
                printf("Esci dal programma\n");
                break;
            case 1:{
                biblioteca=InserisciLibro(biblioteca, &n);
                break;
            }
            case 2:{

            }

        }
    }while(scelta!=0);
}