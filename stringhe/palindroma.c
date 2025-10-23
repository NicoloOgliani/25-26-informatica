/*verificfare se una stringa è palindroma
es. anna=anna*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* String;
int lunghezza(String s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i-1;
}
int Palindroma(String s, int dim){
    int flag=0, i=0, j=0;
    for( i=0, j=dim-1; i<dim/2; i++, j--){//potevamo anche menntere j>dim/2
        if(s[i]!=s[j]){
            flag=1;
        }
    }
    return flag;
}
int main(){
    int dim=0, palindroma=0;
    String s=(String)malloc(50*sizeof(char));
    if(s==NULL){
        printf("Errore di allocazione");
        return 1;
    }
    printf("Inserisci una stringa: ");
    fgets(s, 50, stdin);
    printf("\n%s", s);
    dim=lunghezza(s);
    printf("\n%d", dim);
    palindroma=Palindroma(s, dim);
    if(palindroma==1){
        printf(" La parola non è palindroma");
    }
    else printf(" La parola è palindroma");
}