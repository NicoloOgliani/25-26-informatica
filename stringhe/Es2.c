/*stringa con malloc*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *buffer;
    int len;
    printf("Inserisci la lunghezza della stringa: ");
    scanf("%d", &len);
    buffer=(char*)malloc((len+1)*sizeof(char));
    if(buffer==NULL) return 1;
    printf("Inserisci una stringa: ");
    getchar();
    fgets(buffer, len+1, stdin);
    printf("Hai inserito: %s\n", buffer);
    free(buffer);
    return 0;
}