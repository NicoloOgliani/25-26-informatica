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
#include <stdlib.h>
#include <string.h>

typedef char* string;

int calcola_frequenza(string str, char c){
    int freq=0, i=0;
    while(str[i]!='\0'){
        if(str[i]==c)   freq++;
        i++;
    }
    return freq;
}

int main(){
    char str[30], str1[30], c;
    string copia;
    int len, frequenza=0;
    printf("Inserisci la str: ");
    fgets(str, 30, stdin);
    printf("Inserisci la str1: ");
    fgets(str1, 30, stdin);

    //calcolo lunghezza stringa
    len = strlen(str);
    printf("lunghezza str:  %d", len);

    //compara stringhe
    if(strcmp(str, str1) == 0){
        printf("Le due stringhe sono uguali.\n");
    }  
    else{
        printf("Le due stringhe sono diverse.\n");
    }                   
    //Copia stringhe
    copia = (string)malloc(len*sizeof(char));
    strcpy(copia, str);
    printf("La stringa copiata: %s\n", copia);

    //Cerca carattere e stampa la frequenza
    printf("inserisci il carattere da cercare: ");
    scanf(" %c", &c);
    frequenza = calcola_frequenza(str, c);
    printf("Il carattere %c è presente %d volte.\n", c, frequenza);

    //concatena due stringhe
    strcat(str, str1);
    printf("La stringa concatenata: %s\n", str);
    free(copia);
    return 0;
}