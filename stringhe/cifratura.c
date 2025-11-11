/*in base alla parola che inserisco stampare lettera 
per lettera aumentata di un tot in base al fattore di cifratura 
nell'ordine alfabetico, se c'è una z riparto dall'inizio, usa la tabella ascii*/
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    int fattore;
    printf("Inserisci il fattore di cifratura: ");
    scanf("%d", &fattore);
    getchar();

    printf("Inserisci una stringa: ");
    fgets(str, sizeof(str), stdin);
    for(int i=0; i<strlen(str); i++){
        char c=str[i];
        if(c>='a' && c<='z'){
            c=((c-'a'+fattore)%26)+'a';
        }
        else if(c>= 'A' && c<='Z'){
            c=((c-'A'+fattore)%26)+'A';
        }
        printf("%c", c);
    }
    for(int i=0; i<strlen(str); i++){
        char c=str[i];
        if(c>='a'&& c<='z'){
            c=((c-'a'-fattore+26)%26)+'a';
        }
        else if(c>='A'&& c<='Z'){
            c=((c-'A'-fattore+26)%26)+'A';//se metti lettere trobbo basse torna alla z e fa il contrario
        }
        printf("%c", c);
    }
    
    printf("\n");
    return 0;
}
