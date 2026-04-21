/*Creare una rubrica telefonica utilizzando un file bin
aggiornare e creare il file rubrica
stampa liste contatti
elimina un contatto in base al nome
separa il file rubrica in due in base al sesso*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nome[30];
    char telefono[15];
    char sesso;
}contatto;

void aggiungiContatto(){
    FILE *fp = fopen("rubrica.dat", "ab");

    if(fp==NULL){
        printf("Errore apertura file\n");
        return;
    }

    contatto c;
    printf("Inserisci il nome: ");
    scanf("%s[^\n]", c.nome);
    getchar();

    printf("Inserisci il numero di telefono: ");
    scanf("%s[^\n]", c.telefono);
    getchar();
    
    printf("Inserisci il sesso: ");
    scanf("%c", &c.sesso);
    getchar();
    

    fwrite(&c, sizeof(contatto), 1, fp);
    fclose(fp);
}

void stampaContatti(){
    FILE *fp = fopen("rubrica.dat", "rb");

    if(fp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    contatto c;
    printf("\n----RUBRICA----\n");
    while(fread(&c, sizeof(contatto), 1, fp) ==1){
        printf("Nome: %s, Telefono %s, sesso:%c\n", c.nome, c.telefono, c.sesso);
    }
    fclose(fp);
}
void eliminaContatto(){
    FILE *fp=fopen("rubrica.dat", "rb");
    FILE *fpTmp=fopen("temp.dat", "wb");
    if(fp==NULL || fpTmp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    char cerca[30];
    printf("Inserisci il nome del contatto da eliminare: ");
    scanf(" %[^\n]", cerca);

    getchar();
    contatto c;
    while(fread(&c, sizeof(contatto), 1, fp)==1){
        if(strcmp(c.nome, cerca)==0){
            printf("Contatto eliminato: %s\n", c.nome);
        } else {
            fwrite(&c, sizeof(contatto), 1, fpTmp);

        }
    }
    fclose(fp);
    fclose(fpTmp);
    fp=fopen("temp.dat", "rb");
    fpTmp=fopen("rubrica.dat", "wb");
    while(fread(&c, sizeof(contatto), 1, fp)==1){
        fwrite(&c, sizeof(contatto), 1, fpTmp);
    }
    fclose(fp);
    fclose(fpTmp);

}
void separaContattiPerSesso(){
    FILE *fp=fopen("rubrica.dat", "rb");
    FILE *fpM=fopen("maschi.dat", "wb");
    FILE *fpF=fopen("femmine.dat", "wb");
    contatto c;
    while(fread(&c, sizeof(contatto), 1, fp)==1){
        if(c.sesso=='M' || c.sesso=='m'){
            fwrite(&c, sizeof(contatto), 1, fpM);
        } else if(c.sesso=='F' || c.sesso=='f'){
            fwrite(&c, sizeof(contatto), 1, fpF);
        }
    }
    
    fclose(fp);
    fclose(fpM);
    fclose(fpF);
    fpM=fopen("maschi.dat", "rb");
    fpF=fopen("femmine.dat", "rb");
    printf("\n----Contatti Maschili----\n");
    while(fread(&c, sizeof(contatto), 1, fpM)==1){
        printf("Nome: %s, Telefono %s, sesso:%c\n", c.nome, c.telefono, c.sesso);
    }
    printf("\n----Contatti Femminili----\n");
    while(fread(&c, sizeof(contatto), 1, fpF)==1){
        printf("Nome: %s, Telefono %s, sesso:%c\n", c.nome, c.telefono, c.sesso);
    }
    fclose(fpM);
    fclose(fpF);
}
void eliminaPerTelefono(){
    FILE *fp=fopen("rubrica.dat", "rb");
    FILE *fpTmp=fopen("temp.dat", "wb");
    if(fp==NULL || fpTmp==NULL){
        printf("Errore apertura file\n");
        return;
    }
    char cerca[15];
    printf("Inserisci il numero di telefono del contatto da eliminare: ");
    scanf(" %[^\n]", cerca);

    getchar();
    contatto c;
    while(fread(&c, sizeof(contatto), 1, fp)==1){
        if(strcmp(c.telefono, cerca)==0){
            printf("Contatto eliminato: %s\n", c.nome);
        } else {
            fwrite(&c, sizeof(contatto), 1, fpTmp);

        }
    }
    fclose(fp);
    fclose(fpTmp);
    fp=fopen("temp.dat", "rb");
    fpTmp=fopen("rubrica.dat", "wb");
    while(fread(&c, sizeof(contatto), 1, fp)==1){
        fwrite(&c, sizeof(contatto), 1, fpTmp);
    }
    fclose(fp);
    fclose(fpTmp);

}

int main(){
    int scelta;

    do{
        printf("\nMenù Rubrica: \n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza contatti\n");
        printf("3. Elimina contatto\n");
        printf("4. Separa contatti per sesso\n");
        printf("5. Elimina contatto per telefono\n");
        printf("0. esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                aggiungiContatto();
                break;
            case 2:
                stampaContatti();
                break;
            case 3:
                eliminaContatto();
                break;
            case 4:
                separaContattiPerSesso();
                break;
            case 5:
                eliminaPerTelefono();
                break;
            case 0:
                printf("esci dal programma\n");
                break;
            default:
                printf("scelta non valida\n");   
        }

    }while(scelta != 0);


}