/*date due stringhe scrivere la stringa in alternata
es: ciao, casa --> cciaasoa, fallo con le funzioni*/
#include <stdio.h>
#include <string.h>
void alterna(char str1[], char str2[], char *risultato){
    int len1=strlen(str1);
    int len2=strlen(str2);
    int i=0, j=0;
    int k=0;
    while(i<len1 || j<len2){
        if(i<len1){
            risultato[k++]=str1[i++];
        }
        if(j<len2){
            risultato[k++]=str2[j++];
        }
    }
    risultato[k]='\0';

}
int main(){
    char str1[100], str2[100];
    char *risultato[200];
    printf("Inserisci la prima stringa: ");
    scanf("%s", str1);
    printf("Inserisci la seconda stringa: ");
    scanf("%s", str2);
    alterna(str1, str2, &risultato);
    printf("stringa alternata: %s ", risultato);
    return 0;
}

