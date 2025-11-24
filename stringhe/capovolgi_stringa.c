/*data una stringa scrivila capovolta scambiando gli elementi con la malloc*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* Stringa;
Stringa capovolgi(Stringa s){
    char tmp;
    for(int i=0; i<strlen(s); i++){
        tmp=s[i];
        s[i]=s[strlen(s)-i-1];
        s[strlen(s-i-1)]=tmp;

    }
}
int main(){
    Stringa s=(Stringa)malloc(sizeof(s)*sizeof(char));
    if(s==NULL) return 1;
    printf("Inserisci una stringa: ");
    fgets(s, 50, stdin);
    capovolgi(s);
    printf("Stringa capovolta: %s", s);
    free(s);
    return 0;
}