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
    printf("Inserisci titolo: ");
    fgets(L[*n].titolo, sizeof(L[*n].titolo), stdin);
    L[*n].titolo[strcspn(L[*n].titolo, "\n")] = '\0';
    
    printf("Inserisci autore: ");
    fgets(L[*n].autore, sizeof(L[*n].autore), stdin);
    L[*n].autore[strcspn(L[*n].autore, "\n")] = '\0';
    
    printf("Inserisci ISBN: ");
    scanf("%d", &L[*n].isbn);
    
    printf("Inserisci copie totali: ");
    scanf("%d", &L[*n].copie_totali);
    
    L[*n].copie_disponibili=L[*n].copie_totali;
    L[*n].data_prestito.giorno=0;
    L[*n].data_restituzione.giorno=0;
    (*n)++;
    //getchar();
    return L;
}
void stampa(Libro* L, int n){
    int i=0;
    for(i =0; i<n; i++){
        printf("Titolo: %s\n", L[i].titolo);
        printf("Autore: %s\n", L[i].autore);
        printf("ISBN: %d\n", L[i].isbn);
        printf("Copie disponibili: %d\n", L[i].copie_disponibili);
        printf("Copie totali: %d\n", L[i].copie_totali);
        if(L[i].data_prestito.giorno!=0){
            printf("Data prestito: %02d/%02d/%04d\n", L[i].data_prestito.giorno, L[i].data_prestito.mese, L[i].data_prestito.anno);
            printf("Data restituzione: %02d/%02d/%04d\n", L[i].data_restituzione.giorno, L[i].data_restituzione.mese, L[i].data_restituzione.anno);
        }
        printf("\n");
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
                stampa(biblioteca, n);
                break;
            }

        }
    }while(scelta!=0);
}