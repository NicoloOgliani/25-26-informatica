/*Calsse di studenti:
Cognome, nome, classe, matricola
Per ogni studente dotato di matricola abbiamo
le info riguardanti gli esami e il livello raggiunto
ricerca lo studente con più certificazioni*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    char cognome[20];
    char nome[20];
    char classe[3];
    int matricola;
}studente;
typedef struct{
    int matricola;
    typedef struct{
        char corso[20];
        int livello;
    }esame;
}certificazioni;
int main(){
    printf("Inserisci il numero di studenti: ");
    int n;
    scanf("%d", &n);
    studente* studenti=malloc(n*sizeof(studente));
    for(int i=0; i<n; i++){
        printf("Inserisci cognome, nome, classe e matricola dello studente %d: ", i+1);
        scanf("%s %s %s %d", studenti[i].cognome, studenti[i].nome, studenti[i].classe, &studenti[i].matricola);
    }
    printf("Inserisci il numero di certificazioni: ");
    int m;
    scanf("%d", &m);
    certificazioni* certificazione=malloc(m*sizeof(certificazioni));
    for(int i=0; i<m; i++){
        printf("Inserisci matricola: ");
        scanf("%d", &certificazione[i].matricola);
        printf("Inserisci corso: ");
        fgets(certificazione[i].esame.corso, 20, stdin);
        printf("Inserisci livello: ");
        scanf("%d", &certificazione[i].livello);
    }
}