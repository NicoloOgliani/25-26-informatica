/*date due stringhe scrivere la stringa in alternata
es: ciao, casa --> cciaasoa, fallo con le funzioni*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char* Stringa;
void compatta(Stringa buffer, int len){
    if(len>0 &&buffer[len-1]=='\n'){
        buffer[len-1]='\0';
        len--;
    }
}
void alterna(Stringa s1, Stringa s2, Stringa s3){
    int i=0, j=0;
    int len1=strlen(s1);
    int len2=strlen(s2);
    for(i=0; i<len1 || i<len2; i++){
        if(i<len1){
            s3[j]=s1[i];
            j++;
        }
        if(i<len2){
            s3[j]=s2[i];
            j++;
        }
    }
    s3[j]='\0';
}
int main(){
    int i=0, j=0, len;
    Stringa s1=(Stringa)malloc(50*sizeof(char));
    if(s1==NULL) return 1;
    Stringa s2=(Stringa)malloc(50*sizeof(char));
    if(s2==NULL) return 1;
    Stringa s3=(Stringa)malloc(100*sizeof(char));
    if(s3==NULL) return 1;
    printf("Inserisci la prima stringa: ");
    fgets(s1, 50, stdin);
    len=strlen(s1);
    compatta(s1, len);
    printf("Inserisci la seconda stringa: ");
    fgets(s2, 50, stdin);
    len=strlen(s2);
    compatta(s2, len);
    alterna(s1, s2, s3);
    printf("Stringa alternata: %s", s3);
    free(s1);
    free(s2);
    free(s3);
    return 0;
}


