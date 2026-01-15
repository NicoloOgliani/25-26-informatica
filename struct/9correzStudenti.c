/*date le informazioni di alcuni studenti:
cognome, nome, classe, maticola, n_certifi
e le informazioni riguardo le certificazioni di ogni studente:
matricola, esame(corso, livello) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Studente{
    char Cognome[20];
    char Nome[20];
    char classe[3];
    int matricola;
    int n_certif;
};
struct Certificazione{
    int matricola;
    struct esame{
        char corso[20];
        int livello;
    }esame;
};
int main(){
    struct Studente *studenti;
    struct Certificazione *certificazioni;
    int n=3, num, c_max, i_max;
    //allochiamo i primi 3 elementi
    studenti=(struct Studente*)malloc(n*sizeof(struct Studente));
    certificazioni=(struct Certificazione*)malloc(n*sizeof(struct Certificazione));
    if(studenti==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    if(certificazioni==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    //inseriamo i dati
    strcpy(studenti[0].Cognome, "Rossi");
    strcpy(studenti[0].Nome, "Roberto");
    strcpy(studenti[0].classe, "Roberto");
    studenti[0].matricola=123;
    studenti[0].n_certif=0;

    strcpy(studenti[1].Cognome, "Carboni");
    strcpy(studenti[1].Nome, "Roberta");
    strcpy(studenti[1].classe, "Roberto");
    studenti[1].matricola=456;
    studenti[1].n_certif=0;
    
    //Inseriamo i dati riguardanti le certificazioni
    certificazioni[0].matricola=123;
    strcpy(certificazioni[0].esame.corso, "inglese");
    certificazioni[0]. esame.livello=2;

    certificazioni[1].matricola=456;
    strcpy(certificazioni[0].esame.corso, "inglese");
    certificazioni[1]. esame.livello=2;

    //visualizzazione dei dati

    printf("===Lista studenti===\n");
    for(int i=0; i<n; i++){
        printf("Studente %d:\n", i+1);
        printf("Cognome %s:\n", studenti[i].Cognome);
        printf("Nome %s:\n", studenti[i].Nome);
        printf("Classe %s:\n", studenti[i].classe);
        printf("Matricola %d:\n", studenti[i].matricola);
    }
    //visualizzare le info riguardo le certificazioni
    printf("===Lista certificazioni===\n");
    for(int i=0; i<n; i++){
        printf("Studente %d:\n", i+1);
        printf("Matricola %d:\n", certificazioni[i].matricola);
        printf("Corso %d:\n", certificazioni[i].esame.corso);
        printf("Livello Certificazione %d:\n", certificazioni[i].esame.livello);
    }
    //calcoliamo il numero delle certificazioni di ogni studente
    for(int i=0; i<n; i++){
        num=studenti[i].matricola;
        for(j=0; j<n; j++){
            if(certificazioni[j].matricola==num){
                studenti[i].n_certif++;
            }
        }
    }
    //dati studenti
    printf("===Lista studenti===\n");
    for(int i=0; i<n; i++){
        printf("Studente %d:\n", i+1);
        printf("Cognome %s:\n", studenti[i].Cognome);
        printf("Nome %s:\n", studenti[i].Nome);
        printf("Classe %s:\n", studenti[i].classe);
        printf("Matricola %d:\n", studenti[i].matricola);
    }
    //calcoliamo lo studente con il numero di certificazioni massimo
    c_max=studenti[0].n_certif;
    i_max=0;
    for(int i=0; i<n; i++){
        if(studenti[i].n_certif>c_max){
            c_max=studenti[i].n_certif;
            i_max=i;
        }
    }
    printf("Lo studente con il maggior numero di certificazioni è %s %s", studenti[i_max].Cognome, studenti[i_max].Nome );
    
}