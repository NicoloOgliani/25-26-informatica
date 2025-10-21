/*eliminare gli spazi*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char* String;

int elimina_spazi(char *c){
    int j=0;
    for(int i =0; c[i]!='\0'; i++){
        if(c[i]!=' ' && c[i]!= '\t'){
            c[j++]=c[i];
        }
    }
    c[j]='\0';
    return j;
}
void compatta(String buffer, int len){
    if(len>0 && buffer[len-1]=='\n'){
        buffer[len-1]='\0';
        len--;
    }
}
int main(){
    char buffer[200];
    String frase;
    int len;

    printf("Inserisci una stringa: ");
    if(fgets(buffer, sizeof(buffer), stdin)==NULL){
        printf("C'è stato un errore\n");
        return 1;
    }
    len=strlen(buffer);
    compatta(buffer, len);
    int newlen=elimina_spazi(buffer);

    frase=(String)malloc((newlen+1)*sizeof(char));
    if(frase==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    strcpy(frase, buffer);
    printf("La frase definitiva è %s", frase);

    free(frase);
    return 0;
}