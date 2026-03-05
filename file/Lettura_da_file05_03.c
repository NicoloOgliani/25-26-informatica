//leggi dal file 
#include <stdio.h>
int main(){
    FILE *file=fopen("dati.txt", "r");
    char riga[100];
    if(file==NULL){
        printf("Errore di aprtura file\n");

    }
    while(fgets(riga, sizeof(riga), file)!=NULL){
        printf("%s", riga);
    }
    fclose(file);
    return 0;
}