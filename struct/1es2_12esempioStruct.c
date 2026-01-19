/*esempio di utilizzo di una struttura complessa
facendo accesso ai campi in modalità variabile e in
modalità puntatore alla struttura*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nome[20];
    char cognome[20];
    int eta;
}Persona;
void pulisciBuffer(){
    int c;
    while((c=getchar())!='\n' && c!=EOF);
}
void rimuoviNewline(char *s){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='\n'){
            s[i]='\0';
            break;
        }
        i++;
    }
}
int main(){
    Persona p1;
    Persona *p2;

    printf("Inserisci il nome della persona 1: ");
    fgets(p1.nome, 20, stdin);
    rimuoviNewline(p1.nome);
    
    printf("Inserisci il cognome della persona 1: ");
    fgets(p1.cognome, 20, stdin);
    rimuoviNewline(p1.cognome);
    
    printf("Inserisci l'eta della persona 1: ");
    scanf("%d", &p1.eta);
    pulisciBuffer();//va messo dopo ogni scanf se dopo ce un fgets

    p2=(Persona*)malloc(sizeof(Persona));
    printf("Inserisci il nome della persona 2: ");
    fgets(p2->nome, 20, stdin);
    rimuoviNewline((p2->nome));
    
    printf("Inserisci il cognome della persona 2: ");
    fgets(p2->cognome, 20, stdin);
    rimuoviNewline(p2->cognome);
    
    printf("Inserisci l'eta della persona 2: ");
    scanf("%d", &(p2->eta));
    pulisciBuffer();
    
    printf("\n--- DATI INSERITI ---\n"); 
    printf("\nPersona 1:\n"); 
    printf("Nome: %s\n", p1.nome); 
    printf("Cognome: %s\n", p1.cognome); 
    printf("Eta: %d\n", p1.eta); 
    printf("\nPersona 2:\n"); 
    printf("Nome: %s\n", p2->nome); 
    printf("Cognome: %s\n", p2->cognome); 
    printf("Eta: %d\n", p2->eta);

    free(p2);
    return 0;
}

