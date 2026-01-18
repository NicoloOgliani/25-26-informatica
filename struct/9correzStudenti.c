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
    int n=3;

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


}
