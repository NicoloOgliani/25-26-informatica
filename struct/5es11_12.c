
    /*registrare le informazioni di alcuni libri 
titolo, autore, anno pubblicazione
-array di libri, caricare l'array, pubblicare, rimuovere un libro, 
cercare un libro in base al titolo */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char titolo[40];
    char autore[30];
    int annoPubb;

}Libro;
void caricaLibri(Libro *libro, int n) {
    for(int i = 0; i < n; i++) {
        printf("Inserisci il titolo del libro: ");
        scanf(" %[^\n]", libro[i].titolo);

        printf("Inserisci l'autore del libro: ");
        scanf(" %[^\n]", libro[i].autore);

        printf("Inserisci l'anno di pubblicazione del libro: ");
        scanf("%d", &libro[i].annoPubb);
    }
}

void pubblicaLibri(Libro *libro, int n){
    printf("\nElenco dei libri: \n");
    for(int i=0; i<n; i++){
        printf("Titolo: %s, Autore: %s, Anno di pubblicazione: %d\n",libro[i].titolo, libro[i].autore, libro[i].annoPubb);
    }
}
int cercaLibro(Libro *libro, int n, char *titoloCercato){
    for(int i=0; i<n; i++){
        if(strcmp(libro[i].titolo, titoloCercato) == 0){
            return i;
        }
    }
    return -1;
}
void rimuoviLibro(Libro *libro, int *n, int indice){
    for(int i=indice; i<*n; i++){
        libro[i]=libro[i+1];
    }
    (*n)--;   
}
int main(){
    Libro *libro;
    int n, indice;
    char titoloCercato[40];
    libro=(Libro*)malloc(100*sizeof(Libro));
    printf("Quanti libri vuoi inserire?: ");
    scanf("%d", &n);
    caricaLibri(libro, n);
    pubblicaLibri(libro, n);
    printf("Inserisci il titolo del libro da cercare: ");
    scanf("%s", titoloCercato);
    indice=cercaLibro(libro, n, titoloCercato);
    if(indice != -1){
        printf("Libro trovato all'indice %d\n", indice);
        rimuoviLibro(libro, &n, indice);
        printf("Lista aggiornata: ");
        pubblicaLibri(libro, n);

    }
    else{
        printf("Libro non trovato\n");
    }
    return 0;
}


