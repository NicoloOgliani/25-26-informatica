/*Crea un programma in C che gestisce 
un piccolo archivio di prodotti salvato 
in un file binario chiamato prodotti.dat.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int codice;
    char nome[20];
    float prezzo;
} Prodotto;
void aggiungiProdotto(FILE *fp){
    Prodotto p;
    printf("Inserisci codice prodotto: ");
    scanf("%d", &p.codice);
    printf("Inserisci nome prodotto: ");
    scanf("%s", p.nome);
    printf("Inserisci prezzo prodotto: ");
    scanf("%f", &p.prezzo);
    fp=fopen("prodotti.dat", "ab");
    if(fp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    fwrite(&p, sizeof(Prodotto), 1, fp);
    fclose(fp);
}
void visualizzaProdotti(FILE *fp){
    Prodotto p;
    fp=fopen("prodotti.dat", "rb");
    if(fp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    printf("Prodotti:\n");
    while(fread(&p, sizeof(Prodotto), 1, fp)==1){
        printf("Codice: %d, Nome: %s, Prezzo: %.2f\n", p.codice, p.nome, p.prezzo);
    }
    fclose(fp);
}
void cercaProdotto(FILE *fp){
    int codice;
    printf("Inserisci codice prodotto da cercare: ");
    scanf("%d", &codice);
    Prodotto p;
    fp=fopen("prodotti.dat", "rb");
    if(fp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    int trovato=0;
    while(fread(&p, sizeof(Prodotto), 1, fp)==1){
        if(p.codice==codice){
            printf("Prodotto trovato: Codice: %d, Nome: %s, Prezzo: %.2f\n", p.codice, p.nome, p.prezzo);
            trovato=1;
            break;
        }
    }
    if(!trovato){
        printf("Prodotto non trovato\n");
    }
    fclose(fp);
}
int main(){
    FILE *fp;
    Prodotto p;
    printf("Menu:\n1. Aggiungi prodotto\n2. Visualizza prodotti\n3. Cerca prodotto tramite codice\n4. Esci\n");
    int scelta;
    do{
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
                aggiungiProdotto(fp);
                break;
            case 2:
                visualizzaProdotti(fp);
                break;
            case 3:
                cercaProdotto(fp);
                break;
            case 4:                printf("Uscita...\n");
                break;
            default:
                printf("Opzione non valida\n");
        }
    }while(scelta!=4);
    return 0;
            
}