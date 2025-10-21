/*data una stringa contare il numero delle vocali*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char* String;

void compatta(String buffer, int len){
    if(len>0 && buffer[len-1]=='\n'){
        buffer[len-1]='\0';
        len--;// serve a togliere il carattere invio perchè fgets prende anche l'invio
    }
}
int conteggio(String frase){
    int cnt=0;
    for(int i=0; frase[i]!='\0'; i++){
        char c=tolower(frase[i]);//includiamo la libreria <ctype.h>
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            cnt++;
    }
    return cnt;
}//trasformiamo tutte le maiuscole in minuscole così nell'if
// non includiamo anche il conrollo delle maiuscole
int main(){
    char buffer[200];
    String frase;
    int len;

    printf("Inserisci una stringa: ");
    fgets(buffer, sizeof(buffer), stdin);
    len=strlen(buffer);
    compatta(buffer, len);
    frase=(String)malloc((len+1)*sizeof(char));
    if(frase==NULL){
        printf("C'è stato un errore\n");
        return 1;
    }

    strcpy(frase, buffer);
    printf("Il numero delle vocali è: %d", conteggio(frase));

    free(frase);
    return 0;
}