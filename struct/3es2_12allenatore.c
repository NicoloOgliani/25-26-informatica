/*creare una struttura squadra con nome
colore, punteggio e le informazioni del proprio allenatore, 
(nome, cognome, titoli), poi stampiamo sollo le squadre 
che hanno un punteggio superiore a 30 e numero di titoli per allenatore superiore a 10. Caricare un max di 10 squadre*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct squadra{
    char nome[20];
    char colore[20];
    int punteggio;
    struct allenatore{
        char nomeAllenatore[20];
        char cognome [20];
        int titoli;
    }mister;
};
typedef struct squadra squadre;
void caricaSquadre(squadre *team, int n){
    for(int i=0; i<n; i++){
        printf("Inserisci il nome della squadra: ");
        scanf("%s", team[i].nome);
        printf("Inserisci il colore della squadra: ");
        scanf("%s", team[i].colore);
        printf("Inserisci il punteggio della squadra: ");
        scanf("%d", &team[i].punteggio);
        printf("Inserisci il nome dell'allenatore: ");
        scanf("%s", team[i].mister.nomeAllenatore);
        printf("Inserisci il cognome dell'allenatore: ");
        scanf("%s", team[i].mister.cognome);
        printf("Inserisci il numero di titoli dell'allenatore: ");
        scanf("%d", &team[i].mister.titoli);
    }   
}
void stampaSquadre(squadre team[], int n){
    printf("\nSquadre con punteggio superiore a 30 e allenatore con piu' di 10 titoli:\n");
    for(int i=0; i<n; i++){
        if(team[i].punteggio > 30 && team[i].mister.titoli > 10){
            printf("Squadra: %s, Colore: %s, Punteggio: %d, Allenatore: %s %s, Titoli: %d\n",
                   team[i].nome, team[i].colore, team[i].punteggio,
                   team[i].mister.nomeAllenatore, team[i].mister.cognome,
                   team[i].mister.titoli);
        }
    }
}
int main(){
    squadre *team;
    int n;
    team=(squadre *)malloc(10 * sizeof(squadre));
    do{
    printf("Quante squadre vuoi inserire (max 10)? ");
    scanf("%d", &n);
    }while(n>=10);
    caricaSquadre(team, n);
    stampaSquadre(team, n);
    return 0;
}   


