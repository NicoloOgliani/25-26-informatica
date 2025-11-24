/*eliminare gli spazi*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef char* Stringa;
int eliminaSpazi(Stringa s){
    int i=0, j=0;
    for(i=0; s[i]!='\0'; i++){
        if(s[i]==' '){
            for(j=i; s[j]!='\0'; j++){
                s[j]=s[j+1];
            }
            s[j]='\0';
        }
    }
}
int main(){
    Stringa s=(Stringa)malloc(50*sizeof(char));
    if(s==NULL) return 1;
    printf("Inserisci una stringa: ");
    fgets(s, 50, stdin);
    eliminaSpazi(s);
    printf("%s", s);
}