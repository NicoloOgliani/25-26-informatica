/*esempio di utilizzo di una struttura complessa
facendo accesso ai campi in modalità variabile e in
modalità puntatore alla struttura*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nome[20];
    char cognome[20];
    int eta;
}Persona;
int main(){
    Persona p1;
    Persona *p2;
    //inseriamo le informazioni in p1
    printf("Inserisci il nome della persona: ");
    scanf("%s", p1.nome);
    while(getchar()!='\n');
    printf("Inserisci il cognome della persona: ");
    scanf("%s", p1.cognome);
    while(getchar()!='\n');
    printf("Inserisci l'eta' della persona: ");
    scanf("%d", &p1.eta);
    while(getchar()!='\n');
    
    
    printf("Dati della persona: %s, %s, %d", p1.nome, p1.cognome, p1.eta);

    //ora facciamo la stessa cosa con p2
    p2=malloc(sizeof(Persona));
    printf("\nInserisci il nome della persona: ");
    scanf("%s", p2->nome);
    while(getchar()!='\n');
    printf("Inserisci il cognome della persona: ");
    scanf("%s", p2->cognome);
    while(getchar()!='\n');
    printf("Inserisci l'eta della persona: ");
    scanf("%d", &(p2->eta));
    while(getchar()!='\n');

    printf("Dati della persona: %s, %s, %d", p2->nome, p2->cognome, p2->eta);
}

