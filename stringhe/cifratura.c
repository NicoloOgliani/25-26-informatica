/*in base alla parola che inserisco stampare lettera 
per lettera aumentata di un tot in base al fattore di cifratura 
nell'ordine alfabetico, se c'è una z riparto dall'inizio, usa la tabella ascii*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* Stringa;
Stringa cifra(Stringa s, int key){
    int len=strlen(s);
    int i=0, controllo;
    Stringa tmp=malloc((len+1)*sizeof(char));
    if(tmp==NULL) exit(1);
    while(s[i]!='\0'){
        controllo=0;
        printf("%c", s[i]);
        if(s[i]+key>122){
            controllo=26;
        }
        tmp[i]=s[i]+key-controllo;
        i++;
    }
    tmp[len]='\0';
    return tmp;
}
Stringa decifra(Stringa s, int key){
    int len=strlen(s);
    int i=0, controllo;
    Stringa tmp=malloc((len+1)*sizeof(char));
    if(tmp==NULL) exit(1);
    while(s[i]!='\0'){
        controllo=0;
        if(s[i]-key<97){
            controllo=26;
        }
        tmp[i]=s[i]-key+controllo;
        i++;
    }
    tmp[len]='\0';
    return tmp;
}

int main() {
    Stringa s=malloc(200*sizeof(char));
    if(s==NULL) return 1;
    Stringa sCifrata;
    int key;
    printf("Inserisci una stringa minuscola: ");
    fgets(s, 200, stdin);
    getchar(); 
    printf("Inserisci il fattore di cifratura: ");
    scanf("%d", &key);
    sCifrata=cifra(s, key);
    printf("Stringa cifrata: %s\n", sCifrata);
    Stringa sDecifrata=decifra(sCifrata, key);
    printf("Stringa decifrata: %s\n", sDecifrata);
    free(s);
    free(sCifrata);
    free(sDecifrata);
    return 0;
}
   
