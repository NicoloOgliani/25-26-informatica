/*date le informazioni di alcuni studenti:
cognome, nome, classe, maticola, n_certifi
e le informazioni riguardo le certificazioni di ogni studente:
matricola, esame(corso, livello) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Studente{
    char cognome[20];
    char nome[20];
    char classe[3];
    int matricola;
    int n_certif;
}Studente;
typedef struct Certificazione{
    int matricola;
    struct esame{
        char corso[20];
        int livello;
    }esame;
}Certificazione;
int main(){
    Studente *studenti;
    Certificazione *certificazioni;
    int n=3, num, c_max, i_max;

    certificazioni=(Certificazione*)malloc(n*sizeof(Certificazione));
    if(certificazioni==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    studenti=(Studente*)malloc(n*sizeof(Studente));
    if(studenti==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    //Inserimento dati studente
    strcpy(studenti[0].nome, "Mario");
    strcpy(studenti[0].cognome, "rossi");
    strcpy(studenti[0].classe, "3A");
    studenti[0].matricola="223";
    studenti[0].n_certif="0";
    //Inserimento certificazioni
    certificazioni[0].matricola="223";
    strcpy(certificazioni[0].esame.corso, "Inglese");
    certificazioni[0].esame.livello="2";
    //stampa studenti
    for(int i=0; i<n; i++){
        printf("Studente %d", i+1);
        printf("Cognome %s:\n", studenti[i].cognome); 
        printf("Nome %s:\n", studenti[i].nome); 
        printf("Classe %s:\n", studenti[i].classe); 
        printf("Matricola %d:\n", studenti[i].matricola);
    }
    printf("Corso %d:\n", certificazioni[i].esame.corso); 
    for(int i=0; i<n; i++){
        num=studenti[i].matricola;
        for(int j=0; j<n; j++){
            if(certificazioni[j].matricola == num){ 
                studenti[i].n_certif++; 
            }
        }
    }
    c_max=studenti[0].n_certif;
    i_max=0;
    for(int i=0; i<n; i++){ 
        if(studenti[i].n_certif > c_max){ 
            c_max = studenti[i].n_certif; 
            i_max = i; 
        } 
    }
    printf("Lo studente con il maggior numero di certificazioni è %s %s", studenti[i_max].Cognome, studenti[i_max].Nome);
}
