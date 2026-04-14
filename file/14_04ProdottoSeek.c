/*CREATA UNA STRUCT PRODOTTO CON NOME, ID E PREZZO
SCRIVERE SU FILE BINARIO UNA SERIE DI PRODOTTI
MODIFICARE IL PREZZO DI UN PRODOTTO DATO IL SUO ID*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[50];
    float prezzo;
}Prodotto;
void inserisciProdotto(const char *filename){
    FILE *fp=fopen(filename, "ab");
    int n;
    Prodotto p;
    if(fp==NULL){
        perror("Errore apertura file");
        return;
    }
    printf("Quanti prodotti vuoi inserire?\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Prodotto %d \n", i+1);
        printf("ID: ");
        scanf("%d", &p.id);
        printf("NOME: ");
        scanf("%s", p.nome);
        getchar();
        printf("PREZZO: ");
        scanf("%f", &p.prezzo);
        getchar();

        fwrite(&p, sizeof(Prodotto), 1, fp);
    }
    fclose(fp);
}
void stampaProdotti(const char *filename){
    FILE *fp=fopen(filename, "rb");
    Prodotto p;
    if(fp==NULL){
        perror("Errore apertura file");
        return;
    }
    printf("ELENCO: \n");
    while(fread(&p, sizeof(Prodotto), 1, fp)){
        printf("ID= %d- Nome: %s- Prezzo: %.2f\n ", p.id, p.nome, p.prezzo);
    }
    fclose(fp);
}
void cercaProdotto(const char *filename, int _id){
    FILE *fp=fopen(filename, "rb");
    Prodotto p;
    int trovato;
    if(fp==NULL){
        perror("Errore apertura file");
        return;
    }
    while(fread(&p, sizeof(Prodotto), 1, fp)==1){
        if(p.id==_id){
            printf("\n trovato: Nome %s, prezzo %.2f", p.nome, p.prezzo);
            trovato=1;
            break;
        }
        
    }
    if(!trovato){
        printf("\n Prodotto non trovato");
    }
    fclose(fp);
}
void modificaProdotto(const char *filename, int _id, float nP){
    FILE *fp=fopen(filename, "rb+");
    Prodotto p;
    int trovato;
    if(fp==NULL){
        perror("Errore apertura file");
        return;
    }
    while(fread(&p, sizeof(Prodotto), 1, fp)==1){
        if(p.id==_id){
            p.prezzo=nP;
            fseek(fp, -sizeof(Prodotto), SEEK_CUR);
            fwrite(&p, sizeof(Prodotto), 1, fp);
        }
    }
    fclose(fp);
}
int main(){
    const char *file="prodotti.dat";
    int scelta, id;
    float nuovoPrezzo;
    do{
        printf("Menu prodotti:\n");
        printf("1. Aggiungi prodotto\n");
        printf("2. Visualizza elenco prodotti\n");
        printf("3. Modifica prezzo prodotto\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d",&scelta);
        getchar();
        switch(scelta){
            case 1:
                inserisciProdotto(file);
                break;
            case 2:
                stampaProdotti(file);
                break;
            case 3:
                printf("Inserisci l'id del prodotto: ");
                scanf("%d", &id);
                getchar();
                cercaProdotto(file, id);
                printf("Inserisci il nuovo prezzo: ");
                scanf("%f", &nuovoPrezzo);
                getchar();
                modificaProdotto(file, id, nuovoPrezzo);
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                if(scelta!=0){
                    printf("Scelta non valida. Riprova.\n");
                }
        }

    }while(scelta!=0);
}
