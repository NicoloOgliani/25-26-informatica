/*creare una struttura squadra con nome
colore, punteggio e le informazioni del proprio allenatore, 
(nome, cognome, titoli), poi stampiamo sollo le squadre 
che hanno un punteggio superiore a 100 e numero di titoli per allenatore superiore a 10
superiore a 100. Caricare un max di 10 squadre*/
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char nome[20];
    char cognome[20];
    int titoli;
}Allenatore;
typedef struct{
    char nome[20];
    char colore[20];
    int punteggio;
    Allenatore coach;
}Squadra;
void stampa(Squadra *teams, int n){
    int i;
    for(i=0; i<n; i++){
        if(teams[i].punteggio>100 && teams[i].coach.titoli>10){
            printf("nome squadra: \n%s\n", teams[i].nome);
            printf("colore squadra: \n%s\n", teams[i].colore);
            printf("punteggio: \n%d\n", teams[i].punteggio);
            printf("allenatore: \n%s %s\n", teams[i].coach.nome, teams[i].coach.cognome);
            printf("numero titoli: \n%d\n", teams[i].coach.titoli);
        }
    }
}
int main(){
    Squadra teams[10];
    int n, i;
    printf("quante squadre vuoi inserire? (max 10) \n");
    scanf("%d", &n);
    while(getchar()!='\n');
    for(i=0; i<n; i++){
        printf("inserisci il nome della squadra: \n");
        fgets(teams[i].nome, 20, stdin);
        printf("inserisci il colore della squadra: \n");
        fgets(teams[i].colore, 20, stdin);
        printf("inserisci il punteggio della squadra: \n");
        scanf("%d", &teams[i].punteggio);
        while(getchar()!='\n');
        printf("inserisci il nome dell'allenatore: \n");
        fgets(teams[i].coach.nome, 20, stdin);
        printf("inserisci il cognome dell'allenatore: \n");
        fgets(teams[i].coach.cognome, 20, stdin);
        printf("inserisci il numero di titoli dell'allenatore: \n");
        scanf("%d", &teams[i].coach.titoli);
        while(getchar()!='\n');
    }
    stampa(teams, n);
    return 0;
}

