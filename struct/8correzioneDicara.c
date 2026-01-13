/*registrare le informazioni di alcuni libri con titolo,
autore, anno e prezzo.
Determinare il libro più costoso e il piùì vecchio*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LIBRO{
    char titolo[40];
    char autore[20];
    int anno;
    float prezzo;
};

typedef char* Stringa;
void compatta(Stringa buffer, int lun){
    if(lun>0 && buffer[lun-1]=='\n'){
        buffer[lun-1]='\0';
        lun--;
    }
}
int main(){
    struct LIBRO *libri;
    int lun=0;
    char libro[40];
    int n=3, i=0, datato, i_datato;
    float costoso;
    int i_costoso;
    //allochiamo i primi 3 elementi
    libri=(struct LIBRO*)malloc(n*sizeof(struct LIBRO));
    if(libri==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    //inseriamo i dati
    strcpy(libri[0].titolo, "L'amore mio non muore");
    strcpy(libri[0].autore, "Roberto Saviano");
    libri[0].anno=2025;
    libri[0].prezzo=19.50;

    strcpy(libri[1].titolo, "Maledetti di Dio");
    strcpy(libri[1].autore, "Sven Assel");
    libri[1].anno=1953;
    libri[1].prezzo=13;

    strcpy(libri[2].titolo, "Il dirito di contare");
    strcpy(libri[2].autore, "Margot Lee Shetterly");
    libri[2].anno=2017;
    libri[2].prezzo=18.50;

    n++;
    libri=(struct LIBRO*)realloc(libri, n*sizeof(struct LIBRO));
    if(libri==NULL){
        printf("errore di allocazione");
        return 1;
    }
    strcpy(libri[3].titolo, "Orgoglio e pregiudizio");
    strcpy(libri[3].autore, "Jane Austen");
    libri[3].anno=1813;
    libri[3].prezzo=9;
    //visualizzazione dei dati

    printf("===Lista libri===\n");
    for(i=0; i<n; i++){
        printf("Libro %d:\n", i+1);
        printf("Titolo %s:\n", libri[i].titolo);
        printf("Autore %s:\n", libri[i].autore);
        printf("Anno %d:\n", libri[i].anno);
        printf("Prezzo %.2f:\n", libri[i].prezzo);
    }
    //calcoliamo il libro più datato
    datato=libri[0].anno;
    i_datato=0;
    for(i=1; i<n; i++){
        if(libri[i].anno<datato){
            datato=libri[i].anno;
            i_datato=i;
        }
    }
    printf("Il libro più datato è: %s ", libri[i_datato].titolo);
    

    //calcoliamo il libro più costoso
    costoso=libri[0].prezzo;
    i_costoso=0;
    for(i=1; i<n; i++){
        if(libri[i].prezzo<costoso){
            costoso=libri[i].prezzo;
            i_costoso=i;
        }
    }
    printf("\nIl libro più costoso è: %s ", libri[i_costoso].titolo);
    //eliminiamo un libro
    printf("Inserisci il titolo del libro da eliminare: ");
    fgets(libro, 40, stdin);
    lun= strlen(libro);
    compatta(libro, lun);
    
}