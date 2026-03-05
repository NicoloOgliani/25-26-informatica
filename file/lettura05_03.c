//lttura dati formattati
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
    fscanf(file, "%s %d %.2f", nome, &eta, &media);
    printf("nome: %s eta: %d media: %.2f", nome, eta, media);
    fclose(file);
    return 0;
}