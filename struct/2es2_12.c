/*creare una struttura squadra con nome
colore e punteggio, poi stampiamo sollo le squadre 
che hanno un punteggio
superiore a 100. Caricare un max di 10 squadre*/
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome[20];
    char colore[20];
    int punteggio;
}Squadra;

void stampa(Squadra *teams, int n){
    int i;
    for(i=0; i<n; i++){
        printf("nome squadra: \n%s", teams[i].nome);
        printf("colore squadra: \n%s", teams[i].colore);
        printf("punteggio: \n%d", teams[i].punteggio);
    }
}

int main(){
    Squadra *teams;
    int n, i;
    
    do{
        printf("inserisci il numero delle squadre (max 10): ");
        scanf("%d", &n);
        fflush(stdin);
    }while(n<0 || n>10);
    
    teams =(Squadra*)malloc(sizeof(Squadra));
    if(teams==NULL){
        printf("errore di alloocazione");
        return 1;
    }
    for(i=0; i<n; i++){
        printf("Inserisci il nome della squadra: ");
        scanf("%s", teams[i].nome);
        fflush(stdin);
        printf("Inserisci il colore della squadra: ");
        scanf("%s", teams[i].colore);
        fflush(stdin);
        printf("Inserisci il punteggio della squadra: ");
        scanf("%d", &(teams[i].punteggio));
        fflush(stdin);
    }
    stampa(teams, n);
    
}

