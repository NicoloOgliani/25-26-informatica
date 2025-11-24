/*provare la libreria string.h
per le seguenti operazioni
1. calcola lunghezza stringa
2. controlla se 2 stringhe sono uguali
3. copiare una stringa
4. cercare un carattere e comunicare la frequenza
5. concatenare 2 stringhe
6. ricerca di una stringa nell'altra
usa le funzioni della libreria string.h
*/
#include <stdio.h>
#include <string.h>
int main(){
    char str[100]="Ciao";
    char str1[100]="Mondo!";
    //Lunghezza
    printf("La lunghezza dell aprima stringa è: %lu\n", strlen(str));
    printf("\nLa lunghezza della seconda stringa è: %lu\n", strlen(str1));
    //concatenazione
    strcat(str, str1);
    printf("Dopo la concatenazione: %s\n", str);
    //copia di una stringa
    char copia[100];
    strcpy(copia, str);
    printf("Copia di str: %s\n", copia);
    //confronto
    int confronto=strcmp(str, str1);
    if(confronto==0){
        printf("Sono uguali \n");
    }else printf("Sono diverse\n");
    //ricerca di carattere in una stringa
    char *pos=strchr(str, 'o');
    if(pos!=NULL){
        printf("Il carattere o si trova alla posizione: %ld\n", pos-str);
    }else printf("Carattere o non trovato\n");
    return 0;
}