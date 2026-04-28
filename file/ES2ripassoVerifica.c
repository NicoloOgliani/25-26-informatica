/*CREARE UN PROGRAMMA CHE GESTISCA UNA LIBRERIA DOTATA DI DIVERSI 
LIBRI TALE DA POTER ESEGUIRE LE SEGUENTI OPERAZONI:
- AGGIUNTA/CREAZIONE DELLA LISTA DI LIBRI;
- RICERCA DI UN LIBRO;
- CANCELLAZIONE DI UN LIBRO;
- MODIFICA DELL'ISBN;
- SEPARARE LA LISTA DEI LIBRI IN DUE LISTE CONTENENTI RISPETTIVAMENTE 
I LIBRI CREATI PRIMA DEL 2000 E QUELLI DOPO; TUTTO VIENE GESTITO DA FILE BINARI
typedef struct{
      char autore[30];
      char titolo[30];
      char ISBN[20];
      int anno;
}Libro;*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char autore[30];
    char titolo[30];
    char ISBN[20];
    int anno;
}Libro;

void aggiungiLibro(){
    FILE *fp=fopen("biblioteca.dat", "ab");
    if(fp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    Libro l;
    printf("Inserisci l'autore: ");
    scanf("%s", l.autore);
    getchar();
    printf("Inserisci il titolo: ");
    scanf("%s", l.titolo);
    getchar();
    printf("Inserisci l'ISBN: ");
    scanf("%s", l.ISBN);
    getchar();
    printf("Inserisci l'anno: ");
    scanf("%d", l.anno);
    getchar();

    fwrite(&l, sizeof(Libro), 1, fp);
    fclose(fp);
    printf("Libro aggiunto\n");
}

void cercaLibro(){
    FILE *fp=fopen("biblioteca.dat", "rb");
    Libro l;
    int trovato=0;
    if(fp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    while(fread(&l, sizeof(Libro), 1, fp)==1 && !trovato){
        if(l.ISBN==isbn){
            printf("\nTrovato Titolo: %s- ISBN: %s", l.titolo, l.ISBN);
            trovato=1;
        }
    }
    if(!trovato)
        printf("\nProdotto non trovato");
    
        fclose(fp);
}

void eliminaLibro(){
    FILE *fp=fopen("biblioteca.dat", "rb");
    FILE *fpTmp=fopen("temp.dat", "wb");
    char cerca[30];
    Libro l;
    if(fp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    if(fpTmp==NULL){
        printf("Errore apertura file\n");
        return;
    }
}
int main(){
    int scelta, isbn;
    do{
        printf("Menu:\n");
        printf("1. crea o aggungi un libro\n");
        printf("2. cerca un libro per ISBN\n");
        printf("3. cancella un libro\n");
        printf("4. modifica ISBN\n");
        printf("5. separa la lista in 2 liste (pre anni 2000 e post)\n"):
        printf("0. esci dal programma\n");
   
        printf("Scegli: \n");
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
                aggiungiLibro();
                break;
            case 2:
                printf("Inserisci l'ISBN da cercare: ");
                scanf("%d", &isbn);
                getchar();
                cercaLibro();
                break;
            case 3: 
                eliminaLibro();
                break;
            case 4:
                modificaISBN();
                break;
            case 5:
                separaLista();
                break;
            case 0:
                printf("Uscita dal programma\n");
                break;
                
        }
    }while(scelta<0 || scelta>5);
    return 0;
}