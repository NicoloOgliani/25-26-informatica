/*creare una struttura squadra con nome
colore, punteggio e le informazioni del proprio allenatore, 
(nome, cognome, titoli), poi stampiamo sollo le squadre 
che hanno un punteggio superiore a 100 e numero di titoli per allenatore superiore a 10. Caricare un max di 10 squadre*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    char cognome[20];
    int titoli;
} Allenatore;

typedef struct {
    char nome[20];
    char colore[20];
    int punteggio;
    Allenatore coach;
} Squadra;

void stampa(Squadra *teams, int n) {
    for (int i = 0; i < n; i++) {
        if (teams[i].punteggio > 100 && teams[i].coach.titoli > 10) {
            printf("Nome squadra: %s\n", teams[i].nome);
            printf("Colore: %s\n", teams[i].colore);
            printf("Punteggio: %d\n", teams[i].punteggio);
            printf("Allenatore: %s %s\n", teams[i].coach.nome, teams[i].coach.cognome);
            printf("Titoli: %d\n\n", teams[i].coach.titoli);
        }
    }
}

void leggi_stringa(char *dest, int size) {
    fgets(dest, size, stdin);
    int len = strlen(dest);
    if (len > 0 && dest[len - 1] == '\n') {
        dest[len - 1] = '\0';  // rimuove il newline
    }
}

int main() {
    Squadra teams[10];
    int n;

    printf("Quante squadre vuoi inserire? (max 10)\n");
    scanf("%d", &n);
    getchar(); // consuma il newline rimasto da scanf
    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        printf("Nome squadra: ");
        leggi_stringa(teams[i].nome, 20);

        printf("Colore squadra: ");
        leggi_stringa(teams[i].colore, 20);

        printf("Punteggio: ");
        scanf("%d", &teams[i].punteggio);
        getchar();

        printf("Nome allenatore: ");
        leggi_stringa(teams[i].coach.nome, 20);

        printf("Cognome allenatore: ");
        leggi_stringa(teams[i].coach.cognome, 20);

        printf("Titoli allenatore: ");
        scanf("%d", &teams[i].coach.titoli);
        getchar();
    }

    stampa(teams, n);
    return 0;
}
