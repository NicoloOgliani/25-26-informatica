/* Rubrica contatti con file binario */
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    char telefono[15];
} Contatto;

void pulisciBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void aggiungiContatto() {
    FILE *fp = fopen("rubrica.bin", "ab");
    if (fp == NULL) {
        printf("Errore di apertura del file!\n");
        return;
    }

    Contatto c;
    
    printf("Inserisci il nome: ");
    pulisciBuffer();                    // importante!
    fgets(c.nome, sizeof(c.nome), stdin);
    c.nome[strcspn(c.nome, "\n")] = '\0';  // rimuove il \n

    printf("Inserisci il numero di telefono: ");
    fgets(c.telefono, sizeof(c.telefono), stdin);
    c.telefono[strcspn(c.telefono, "\n")] = '\0';

    if (fwrite(&c, sizeof(Contatto), 1, fp) != 1) {
        printf("Errore durante il salvataggio!\n");
    } else {
        printf("Contatto aggiunto con successo!\n");
    }

    fclose(fp);
}

void stampaContatti() {
    FILE *fp = fopen("rubrica.bin", "rb");
    if (fp == NULL) {
        printf("Nessun contatto presente o errore di apertura file.\n");
        return;
    }

    Contatto c;
    int count = 0;

    printf("\n--- Rubrica ---\n");
    while (fread(&c, sizeof(Contatto), 1, fp) == 1) {
        printf("%d. Nome: %s, Telefono: %s\n", ++count, c.nome, c.telefono);
    }

    if (count == 0) {
        printf("La rubrica è vuota.\n");
    }

    fclose(fp);
}

int main() {
    int scelta;

    do {
        printf("\n=== MENU RUBRICA ===\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        switch (scelta) {
            case 1:
                aggiungiContatto();
                break;
            case 2:
                stampaContatti();
                break;
            case 0:
                printf("Programma terminato.\n");
                break;
            default:
                printf("Scelta non valida!\n");
                pulisciBuffer();
        }
    } while (scelta != 0);

    return 0;
}