/*data una stringa scrivila capovolta scambiando gli elementi con la malloc*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void capovolgi_stringa(char str[], char str1[]){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        str1[i] = str[len - i - 1];
    }
    str1[len] = '\0';
    printf("%s\n", str1);
}
int main(){
    char str[100];
    printf("Inserisci una stringa: ");
    fgets(str, 100, stdin);
    char *str1 = malloc((strlen(str) + 1) * sizeof(char));
    if(str1 == NULL){
        printf("Errore di allocazione della memoria\n");
        return 1;
    }
    printf("stringa invertita: ");
    capovolgi_stringa(str, str1);
    free(str1);
    return 0;
    
}