#include<stdio.h>
typedef struct {
    char nome[100];
    char cognome[100];
    int eta;
}Dati;


void inserisci(Dati *s) {
    char c;
    printf("Inserisci il nome: ");
    fgets(s->nome, 30, stdin);
    printf("Inserisci il cognome: ");
    fgets(s->cognome, 30, stdin);
    printf("Inserisci l'eta: ");
    scanf("%d", &s->eta);
    while((c = getchar()) != '\n') {}

}

int main(){
    FILE *fp;
    Dati s;
    fp=fopen("dati3.txt","w");

    if(fp==NULL){
        printf("Errore nell'apertura del file!");
    return 1;
    }
    inserisci(&s);
    
    fprintf(fp,"nome: %s, cognome: %s, eta: %d\n",s.nome, s.eta, s.cognome);
    fclose(fp);
    
   return 0;
}