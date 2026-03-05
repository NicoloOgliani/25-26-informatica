//scrittura dati formattati
#include <stdio.h>
int main(){
    FILE *file=fopen("dati.txt", "r");
    char nome[100];
    int eta=0;
    float media=0;
    if(file==NULL){
        printf("Errore di aprtura file\n");
        return 1;
    }
    fprintf(file, "%s %d %f", "Luca", 12, 6.5);
    fclose(file);
    return 0;
}