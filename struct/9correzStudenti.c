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
    int n=3;
    //allochiamo i primi 3 elementi
    studenti=(struct Studente*)malloc(n*sizeof(struct Studente));
    certificazioni=(struct Certificazione*)malloc(n*sizeof(struct Certificazione));
    if(studenti==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    if(cert
        printf("Errore di allocazione");
        return 1;
    }
}