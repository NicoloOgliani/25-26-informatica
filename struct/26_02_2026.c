/*data la struct prodotto:
-nome
-codice
-prezzo
eseguire
1. inserire prodotto
2. stampare elenco prodotti
3. cercare un prodotto per codice
4. calcolare il valore totale del magazzino*/           
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct prodotto{
    char nome[50];
    int codice;
    float prezzo;
} prodotto;

void inserisciProdotto(prodotto *p){
    printf("Inserisci nome prodotto: ");
    scanf("%49s", p->nome);
    
    printf("Inserisci codice prodotto: ");
    scanf("%d", &p->codice);
    
    printf("Inserisci prezzo prodotto: ");
    scanf("%f", &p->prezzo);
}

void stampaElenco(prodotto *elenco, int n){
    if (n == 0) {
        printf("Nessun prodotto inserito.\n");
        return;
    }
    
    printf("\nElenco prodotti:\n");
    for(int i = 0; i < n; i++) {
        printf("Nome:    %s\n", elenco[i].nome);
        printf("Codice:  %d\n", elenco[i].codice);
        printf("Prezzo:  %.2f\n", elenco[i].prezzo);
    }
}

void cercaProdotto(prodotto *elenco, int n){
    int codice;
    printf("Inserisci il codice del prodotto da cercare: ");
    scanf("%d", &codice);
    
    for (int i = 0; i < n; i++) {
        if (elenco[i].codice == codice) {
            printf("\nProdotto trovato:\n");
            printf("Nome:    %s\n", elenco[i].nome);
            printf("Codice:  %d\n", elenco[i].codice);
            printf("Prezzo:  %.2f\n", elenco[i].prezzo);
            return;
        }
    }
    printf("Prodotto non trovato\n");
}

void calcolaValore(prodotto *elenco, int n){
    float totale = 0;
    for (int i = 0; i < n; i++) {
        totale += elenco[i].prezzo;
    }
    printf("Valore totale del magazzino: %.2f\n", totale);
}

int main(){
    prodotto *magazzino = NULL;
    int num_prodotti = 0;
    int scelta;

    do {
        printf("\nMenu:\n");
        printf("1. Inserire prodotto\n");
        printf("2. Stampare elenco prodotti\n");
        printf("3. Cercare un prodotto per codice\n");
        printf("4. Calcolare il valore totale del magazzino\n");
        printf("0. Esci\n");
        printf("Scegli un opzione: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:{
                prodotto *temp = realloc(magazzino, (num_prodotti + 1) * sizeof(prodotto));
                if (temp == NULL) {
                    printf("Errore: memoria insufficiente!\n");
                    return 1;
                }
                magazzino = temp;

                inserisciProdotto(&magazzino[num_prodotti]);
                num_prodotti++;
                printf("Prodotto inserito (totale: %d)\n", num_prodotti);
                break;
            }

            case 2:{
                stampaElenco(magazzino, num_prodotti);
                break;
            }

            case 3:{
                cercaProdotto(magazzino, num_prodotti);
                break;
            }

            case 4:{
                calcolaValore(magazzino, num_prodotti);
                break;
            }

            default:{
                printf("Opzione non valida\n");
                break;
            }
        }

    } while(scelta != 0);

    free(magazzino);
    return 0;
}