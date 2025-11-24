/*verificfare se una stringa è palindroma
es. anna=anna*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* Stringa;
int lunghezza(Stringa s){
    int i=0;
    while(i!='\0'){
        i++;
    }
    return i-1;
}
int Palindroma(Stringa s, int dim){
    int flag=0, i=0, j=0;
    for(i=0, j=dim-1; i<dim/2; i++, j--){
        if(s[i]!=s[j]){
            flag=1;
        }else flag=0;
    }
    return flag;
}
int main(){
    int dim=0, palindroma=0;
    Stringa s=(Stringa)malloc(50*sizeof(char));
    if(s==NULL){
        return 1;
    }
    printf("Inserisci una stringa: ");
    fgets(s, 50, stdin);
    printf("\n%s", s);
    dim=lunghezza(s);
    palindroma=Palindroma(s, dim);
    if(palindroma==0){
        printf("La frase è palindroma");
    }else{
        printf("La frase non è palindroma");
    }
    
}