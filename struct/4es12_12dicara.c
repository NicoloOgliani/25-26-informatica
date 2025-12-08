/*aggiungere la funzionalità che permette di eliminare un auto dalla lista data in input una targa.
fare in modo che l'inserimento dell'auto non permetta di aggiungere due auto con la stessa targa.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Auto {
    char targa[9];
    char marca[20];
    char modello[20];
    float prezzo_giorno;
    struct Auto* next;
} Auto;

typedef struct Lista {
    Auto* testa;
    int lunghezza;
} Lista;

// Funzione per rimuovere il newline da fgets
void pulisci_newline(char *s) {
    int len = strlen(s);
    if(len > 0 && s[len-1] == '\n') {
        s[len-1] = '\0';
    }
}

void set_auto(Auto* nuova_auto){
    printf(" === Inserimento nuova auto ===\n");
    printf("Inserisci targa: ");
    fgets(nuova_auto->targa, 9, stdin);
    pulisci_newline(nuova_auto->targa);

    printf("Inserisci marca: ");
    fgets(nuova_auto->marca, 20, stdin);
    pulisci_newline(nuova_auto->marca);

    printf("Inserisci modello: ");
    fgets(nuova_auto->modello, 20, stdin);
    pulisci_newline(nuova_auto->modello);

    printf("Inserisci prezzo giornaliero: ");
    scanf("%f", &nuova_auto->prezzo_giorno);
    char c;
    while((c = getchar()) != '\n') {}
}

int esisteTarga(Lista* lista, char* targa) {
    Auto* temp = lista->testa;
    while(temp != NULL) {
        if(strcmp(temp->targa, targa) == 0) {
            return 1; // trovata
        }
        temp = temp->next;
    }
    return 0; // non trovata
}

void inserisciAuto(Lista* lista) {
    Auto* nuova = (Auto*)malloc(sizeof(Auto));
    if(nuova == NULL) {
        printf("Errore di allocazione\n");
        exit(1);
    }
    nuova->next = NULL;

    set_auto(nuova);

    // controllo duplicato
    if(esisteTarga(lista, nuova->targa)) {
        printf("Errore: esiste già un'auto con la targa %s\n", nuova->targa);
        free(nuova);
        return;
    }

    if(lista->testa == NULL) {
        lista->testa = nuova;
    } else {
        Auto* temp = lista->testa;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuova;
    }
    lista->lunghezza++;
    printf("Auto inserita correttamente!\n");
}

void stampaAuto(Lista* parco_auto){
    Auto* temp = parco_auto->testa;
    int i = 0;
    if(temp == NULL) {
        printf("Nessuna auto presente.\n");
        return;
    }
    while(temp != NULL){
        printf("\n=== AUTO %d ===\n", i+1);
        printf("Targa: %s\nMarca: %s\nModello: %s\nPrezzo: %.2f €/giorno\n",
               temp->targa, temp->marca, temp->modello, temp->prezzo_giorno);
        i++;
        temp = temp->next;
    }
}

void eliminaAuto(Lista* lista, char* targa) {
    Auto* temp = lista->testa;
    Auto* prev = NULL;

    while(temp != NULL && strcmp(temp->targa, targa) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Nessuna auto trovata con la targa %s\n", targa);
        return;
    }

    if(prev == NULL) { // eliminazione in testa
        lista->testa = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    lista->lunghezza--;
    printf("Auto con targa %s eliminata correttamente!\n", targa);
}

Lista* crea_lista(){
    Lista *parco_auto = (Lista*)malloc(sizeof(Lista));
    parco_auto->lunghezza = 0;
    parco_auto->testa = NULL;
    return parco_auto;
}

int main(){
    Lista *parco_auto = crea_lista();
    int scelta;
    char c;
    char targa[9];

    do {
        printf("\n===== AUTONOLEGGIO 2000 =====\n");
        printf("1. Inserisci nuova auto\n");
        printf("2. Visualizza auto\n");
        printf("3. Elimina auto per targa\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        while((c = getchar()) != '\n') {}

        switch (scelta) {
            case 1:
                inserisciAuto(parco_auto);
                break;
            case 2:
                stampaAuto(parco_auto);
                break;
            case 3:
                printf("Inserisci la targa da eliminare: ");
                fgets(targa, 9, stdin);
                pulisci_newline(targa);
                eliminaAuto(parco_auto, targa);
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    } while (scelta != 0);

    return 0;
}

