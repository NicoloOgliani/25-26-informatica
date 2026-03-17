/*scrivere una funzione che preso in ingresso
il nome del file contenente interi, lo modifichi in 
modo tale da contenere gli stessi numeri ma ordinati in
senso decrescente*/
#include <stdio.h>
#include <stdlib.h>
void OrdinaFile(char nomeFile[]){
    FILE *Fp;
    int vett[100], i=0, n;
    Fp=fopen(nomeFile, "r");
    if(Fp==NULL){
        printf("errore apertura file\n");
        exit(1);
    }
    /*Lettura dei numeri daL FILE*/
    while(fscanf(Fp, "%d", &vett[i])==1){
        printf("elemento: %d: %d", i+1, vett[i]);
        i++;
    }
    fclose(Fp);
    /*Ordiniamo i valori*/
    n=i+1;
    for(i=0; i<n; i++){
        
    }
}
int main(){
    char nome[20];
    printf("Inserire il nome del file: ");
    scanf("%s", nome);

    OrdinaFile(nome);

}