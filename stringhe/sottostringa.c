/*data una stringa trovare la sottostringa, 
voglio che funzioni anche quando inserisco più di una parola
es= ciao a tutti (ciao)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stringa_in_stringa(const char *s1, const char *s2) {
    int dim1 = strlen(s1);
    int dim2 = strlen(s2);
    int cnt = 0;

    if (dim2 == 0) return 0;

    for (int i = 0; i <= dim1 - dim2; i++) {
        int flag = 1;
        for (int j = 0; j < dim2; j++) {
            if (s1[i + j] != s2[j]) {
                flag = 0;
                break;
            }
        }
        cnt += flag;
    }
    return cnt;
}
int main() {
    char s1[100];
    char s2[100];
    printf("Inserisci una stringa: ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = 0;//tolgo il \n
    printf("Inserisci una sottostringa: ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = 0;//tolgo il \n
    int occorrenze = stringa_in_stringa(s1, s2);
    printf("la parola compare %d volte ", occorrenze);

    return 0;
}
