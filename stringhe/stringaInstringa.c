#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* Stringa;
void compatta(Stringa buffer, int len){
    if(len>0 &&buffer[len-1]=='\n'){
        buffer[len-1]='\0';
        len--;
    }
}
int cerca(Stringa s1, Stringa s2){
    int i=0, j=0, trovata=0;
    while(s1[i]!='\0' && s2[j]!='\0' && trovata==0){
        while(s1[i]==s2[j]&& s2[j]!='\0'){
            i++;
            j++;
        }
        if(s2[j]=='\0'){
            trovata=1;
        }else{
            trovata=0;
        }
        i++, j=0;
    }
    return trovata;
}
int main(){
    Stringa s1=(Stringa)malloc(50*sizeof(char));
    if(s1==NULL) return 1;
    Stringa s2=(Stringa)malloc(50*sizeof(char));
    if(s2==NULL) return 1;
    printf("Inserisci la prima stringa: ");
    fgets(s1, 50, stdin);
    int len=strlen(s1);
    compatta(s1, len);
    printf("Inserisci la parola da cercare: ");
    fgets(s2, 50, stdin);
    len=strlen(s2);
    compatta(s2, len);
    int risultato=cerca(s1, s2);
    if(risultato==1){
        printf("La seconda stringa è contenuta nella prima\n");
    }else{
        printf("La seconda stringa non è contenuta nella prima\n");
    }
    free(s1);
    free(s2);
    return 0;
}
