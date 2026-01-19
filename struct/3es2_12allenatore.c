/* creare una struct Squadra contenente le seguenti 
informazioni: nome, colore, punteggio e le informazioni del proprio  
alenatore(nome, cognome, titoli)
caricato un massimo di 10 squadre stampare quelle 
con punteggio superiore a 100 e numero di titoli per allenatore superiore a 10
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    char colore[20];
    int punteggio;
    struct allenatore{
        char nome[20];
        char cognome[20];
        int titoli;
    }mister;
}Squadra;
void pulisciBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void rimuoviNewline(char *s){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='\n'){
            s[i]='\0';
        }
        i++;
    }
}
void caricaSquadre(Squadra *team, int n){
    for(int i=0; i<n; i++){
        printf("Inserisci il nome della squadra: ");
        fgets(team[i].nome, 20, stdin);
        rimuoviNewline(team[i].nome);

        printf("Inserisci il colore della squadra: ");
        fgets(team[i].colore, 20, stdin);
        rimuoviNewline(team[i].colore);

        printf("Inserisci il punteggio della squadra: ");
        scanf("%d", &team[i].punteggio);
        pulisciBuffer();
        
        printf("Inserisci il nome dell'allenatore: ");
        fgets(team[i].mister.nome, 20, stdin);
        rimuoviNewline(team[i].mister.nome);

        printf("Inserisci il cognome dell'allenatore: ");
        fgets(team[i].mister.cognome, 20, stdin);
        rimuoviNewline(team[i].mister.cognome);

        printf("Inserisci i titoli dell'allenatore: ");
        scanf("%d", &team[i].mister.titoli);
        pulisciBuffer();

    }
}
void stampaSquadre(Squadra *team, int n){
    for(int i=0; i<n; i++){
        if(team[i].punteggio>100 && team[i].mister.titoli>10){
            printf("La squadra: %s ha fatto più di 100 punti e vinto + di 10 titoli", team[i].nome);
        }
    }
}
int main(){
    Squadra *team;
    int n=0;
    team=(Squadra*)malloc(10*sizeof(Squadra));
    do{
        printf("Quante squadre vuoi inserire: ");
        scanf("%d", &n);
        pulisciBuffer();
    }while(n>=10);
    caricaSquadre(team, n);
    stampaSquadre(team, n);
    free(team);
    return 0;
}

