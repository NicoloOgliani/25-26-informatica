/*Scrivere un programma che inverta ogni riga contenuta 
nel file righe.txt e riporti il risultato sullo schermo. 
Per esempio la riga "PROVA DI STAMPA"  diventa 
"APMATS ID AVORP"*/
#include <stdio.h>
#include <string.h>
int main(){
    FILE *fp;
    char frase[200];
    //apro file in lettura
    fp=fopen("APPEND8_04righe.txt", "r");
    if(fp==NULL){
        printf("Errore apertura file\n");
        return 1;
    }
    //leggo ogni riga del file
    while(fgets(frase, sizeof(frase), fp)!=NULL){
        //rimuovo newline
        frase[strcspn(frase, "\n")]='\0';
        //inverto la riga
        int len=strlen(frase);
        char invertita[200];
        for(int i=0; i<len; i++){
            invertita[i]=frase[len-1-i];
        }
        invertita[len]='\0';
        //stampo la riga invertita
        printf("%s\n", invertita);
    }
}
