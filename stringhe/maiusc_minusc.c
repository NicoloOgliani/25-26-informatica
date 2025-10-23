/*Completare la seguente funzione iniziata in classe:
void maiuscole_minuscole(s1inga s1, Bool maiusc_to_minusc), chiedendo all'utente una s1inga
e stampando quella definitiva, fai una funzione*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef enum { FALSE, TRUE } Bool;
void maiuscole_minuscole(char s1[], Bool maiusc_to_minusc) {
    for (int i = 0; s1[i] != '\0'; i++) {
        if (maiusc_to_minusc) {
            s1[i] = tolower(s1[i]);
        } else {
            s1[i] = toupper(s1[i]);
        }
    }
}
int main() {
    char* s1;
    Bool maiusc_to_minusc;
    int scelta;
    printf("Inserisci una stringa: ");
    fgets(s1, 50, stdin);
    printf(" 1. maiuscole in minuscole 0. minuscole in maiuscole ");
    scanf("%d", &scelta);
    if (scelta == 1) {
        maiusc_to_minusc = TRUE;
    } else {
        maiusc_to_minusc = FALSE;
    }
    maiuscole_minuscole(s1, maiusc_to_minusc);
    printf("stringa finale: %s", s1);
    return 0;
}