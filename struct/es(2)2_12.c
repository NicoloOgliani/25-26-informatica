/*creare una struttura squadra con nome
colore e punteggio, poi stampiamo sollo le squadre 
che hanno un punteggio
superiore a 100. Caricare un max di 10 squadre*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    char colore[20];
    int punteggio;
} Squadra;

void stampa(Squadra *teams, int n){
    printf("\n--- Squadre con punteggio > 100 ---\n");
    for(int i=0; i<n; i++){
        if (teams[i].punteggio > 100) {
            printf("Nome squadra: %s\n", teams[i].nome);
            printf("Colore squadra: %s\n", teams[i].colore);
            printf("Punteggio: %d\n\n", teams[i].punteggio);
        }
    }
}

int main(){
    Squadra *teams;
    int n;

    do{
        printf("Inserisci il numero delle squadre (max 10): ");
        scanf("%d", &n);
        getchar();
        
    }while(n <= 0 || n > 10);

    teams = malloc(n * sizeof(Squadra));
    if(teams == NULL){
        printf("Errore durante l'allocazione\n");
        return 1;
    }

    for(int i=0; i<n; i++){
        printf("Inserisci il nome della squadra: ");
        scanf(" %19[^\n]", teams[i].nome);

        printf("Inserisci il colore: ");
        scanf(" %19[^\n]", teams[i].colore);

        printf("Inserisci il punteggio: ");
        scanf("%d", &(teams[i].punteggio));
        getchar();
    }

    stampa(teams, n);

    free(teams);
    return 0;
}


