#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* Stringa;
int stringa_in_stringa(Stringa s1, Stringa s2){
    int dim1 = strlen(s1);
    int dim2 = strlen(s2);
    int flag = 0;
    int cnt = 0;

    for(int i = 0; i <=dim1-dim2+1; i++){
        if(s1[i] == s2[0]){
            flag = 1;
            for(int j = 1; j < dim2; j++){
                if(s1[i+j] != s2[j]){
                flag = 0;
                break;
                }
            }
            cnt += flag;
        }
    }
    return cnt;
}
int main(){
    char s1[100];
    char s2[100];
    int stringa_in_stringa1=0;
    printf("inserisci una srtringa: ");
    fgets(s1, 100, stdin);
    printf("inserisci una srtringa: ");
    fgets(s2, 100, stdin );
    stringa_in_stringa1 =stringa_in_stringa(s1, s2);
    printf("frequenza %d\n", stringa_in_stringa1);
}
