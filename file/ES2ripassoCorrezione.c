#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char autore[30];
    char titolo[30];
    char ISBN[30];
    int anno;
}Libri;
void aggiungiLibro(){
    FILE *fp=fopen("libreria.dat", "ab");
    Libri l;
    if(fp==NULL){
        printf("Errore nell'apertura del file.\n");
        return;
    }
    printf("Inserisci il nome dell'autore:");
    scanf("%s", l.autore);
    getchar();
    printf("Inserisci il titolo del libro:");
    scanf("%s", l.titolo);
    getchar();
    printf("Inserisci l'ISBN del libro:");
    scanf("%s", l.ISBN);
    getchar();
    printf("Inserisci l'anno di pubblicazione:");
    scanf("%d", &l.anno);
    getchar();
    fwrite(&l, sizeof(Libri), 1, fp);
    fclose(fp);
    printf("Libro aggiunto con successo.\n");
}
void visualizzaLibri(){
    FILE *fp=fopen("libreria.dat", "rb");
    Libri l;
    if(fp==NULL){
        printf("Errore apertura");
        return;
    }
    printf("Libreria: ");
    while(fread(&l, sizeof(Libri), 1, fp)==1){
        printf("Nome: %s, titolo: %s, ISBN: %s, anno: %d\n", l.autore, l.titolo, l.ISBN, l.anno );
    }
    fclose(fp);

}
void ricercaLibro(){
    FILE *fp=fopen("libreria.dat", "rb");
    Libri l;
    char isbn[30];
    int trovato=0;
    if(fp==NULL){
        printf("Errore apertura");
        return;
    }
    printf("Inserisci il codice isbn da cercare:\n");
    scanf("%[^\n]", isbn);
    getchar();
    while(fread(&l, sizeof(Libri), 1, fp)==1){
        if(strcmp(isbn, l.ISBN)==0){
            printf("Trovato autore: %s, titolo: %s, isbn: %s\n",l.autore, l.titolo, l.ISBN );
            trovato=1;
        }
    }
    if(!trovato)
        printf("Libro non trovato");
        fclose(fp);
}
void modificaLibro(){
    FILE *fp=fopen("libreria.dat", "rb+");
    Libri l;
    char isbn[30];
    int trovato=0;
    if(fp==NULL){
        printf("Errore apertura");
        return;
    }
    printf("Inserisci l'isbn del libro: \n");
    scanf("%[^\n]", isbn);
    getchar();
    while(fread(&l, sizeof(Libri), 1, fp)==1 && !trovato){
        if(strcmp(isbn, l.ISBN)==0){
            printf("Inserisci il nuovo isbn:\n");
            scanf("%[^\n]", l.ISBN);
            getchar();

            fseek(fp, -sizeof(Libri), SEEK_CUR);
            fwrite(&l, sizeof(Libri), 1, fp);
            printf("Modifica eseguita\n");
            trovato=1;
        }
    }
    if(!trovato)
        printf("Libro non trovato\n");
    fclose(fp);
}
void eliminaLibro(){
    FILE *fp=fopen("libreria.dat", "rb");
    FILE *fpTmp=fopen("temp.dat", "wb");
    char isbn[20];
    Libri l;
    if (fp == NULL) {
        printf("Libreria vuota!\n");
        return;
    }
    if (fpTmp == NULL) {
        printf("errore sul file temporaneo!\n");
        return;
    }
    printf("Inserisci isbn: \n");
    scanf("%[^\n]", isbn);
    getchar();
    while(fread(&l, sizeof(Libri), 1, fp)){
        if(strcmp(isbn, l.ISBN)==0){
            printf("Libro trovat\n");
        }
        else{
            fwrite(&l, sizeof(Libri), 1, fpTmp);
        }
    }
    fclose(fp);
    fclose(fpTmp);
    fp=fopen("temp.dat", "rb");
    fpTmp=fopen("libreria.dat", "wb");
    while(fread(&l, sizeof(Libri), 1, fp)){
        fwrite(&l, sizeof(Libri), 1, fpTmp);
    }
    fclose(fp);
    fclose(fpTmp);
}
void separaLibri(){
    FILE *fp=fopen("libreria.dat", "rb");
    FILE *fpPre=fopen("pre.dat", "ab");
    FILE *fpPost=fopen("post.dat", "ab");
    Libri l;
    while(fread(&l, sizeof(Libri), 1, fp)){
        if(l.anno<2000)
            fwrite(&l, sizeof(Libri), 1, fpPre);
        else
            fwrite(&l, sizeof(Libri), 1, fpPost);
    }
    fclose(fp);
    fclose(fpPre);
    fclose(fpPost);
    fpPre=fopen("pre.dat", "rb");
    fpPost=fopen("post.dat", "rb");
    printf("Libri pre 2000\n");
    while(fread(&l, sizeof(Libri), 1, fpPre)){
        printf("Autore: %s, titolo: %s, isbn:%s, anno: %d\n", l.autore, l.titolo, l.ISBN, l.anno);
    }
    printf("Libri post 2000\n");
    while(fread(&l, sizeof(Libri), 1, fpPost)){
        printf("Autore: %s, titolo: %s, isbn:%s, anno: %d\n", l.autore, l.titolo, l.ISBN, l.anno);
    }
    fclose(fpPre);
    fclose(fpPost);
}
int main(){
    int scelta;
    do{
        printf("Menu:\n");
        printf("1. Aggiungi un libro\n");
        printf("2. Visualizza i libri\n");
        printf("3. Ricerca libro\n");
        printf("4. Modifica l'isbn di un libro\n");
        printf("5. Elimina libro\n");
        printf("6. Separa la lista dei libri in base all'anno(prima/dopo 2000)\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();
        switch(scelta){
            case 1:
                aggiungiLibro();
                break;
            case 2:
                visualizzaLibri();
                break;
            case 3:
                ricercaLibro();
                break;
            case 4:
                modificaLibro();
                break;
            case 5:
                eliminaLibro();
                break;
            case 6:                
                separaLibri();
                break;
            case 0:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    }while(scelta !=0);
    return 0;
}
