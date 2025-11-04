/*Scrivere un programma in linguaggio C che calcoli e 
visualizzi il codice fiscale (senza il carattere di controllo finale) 
chiedendo all’utente di inserire nome, cognome, data di nascita nel 
formato GG/MM/AAAA, sesso (M o F).
Sarà necessario verificare la correttezza degli input, quindi nome e 
cognome devono essere composti solo da lettere; la data deve essere 
composta solo da numeri (oltre agli eventuali /, si può scegliere se far 
inserire un valore della data alla volta o tutta la data con il separatore /); 
il sesso può avere solo la lettera M o F.
Per il controllo di nome, cognome e data, si suggerisce di leggere 
l’input carattere per carattere usando getchar().
Il codice fiscale è un codice alfanumerico di 16 caratteri che serve per identificare in modo univoco ogni cittadino italiano.
È composto in questo modo:
CCC NNN YYMDD LLLL C
dove:
CCC → prime tre lettere del cognome, formate prendendo le consonanti (o le vocali, se le consonanti non bastano);
NNN → prime tre lettere del nome, con una regola simile a quella del cognome (ma se ci sono quattro consonanti, si prendono la 1ª, 3ª e 4ª);
YY → ultime due cifre dell’anno di nascita;
M → lettera che rappresenta il mese di nascita (A = gennaio, B = febbraio, C = marzo, D = aprile, E = maggio, H = giugno, L = luglio, M = agosto, P = settembre, R = ottobre, S = novembre, T = dicembre);
DD → giorno di nascita (per le donne si aggiunge 40 al giorno);
LLLL → codice del comune di nascita (per questo esercizio useremo G186, che è il codice del comune di Ostiglia);
C → lettera di controllo calcolata con una formula basata sui precedenti 15 caratteri.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char nome[40], cognome [40];
    int giorno, mese, anno, sesso;
    printf("Inserisci il nome: ");
    fgets(nome, 40, stdin);
    printf("Inserisci il cognome: ");
    fgets(cognome, 40, stdin);
    do{
        printf("Inserisci la data di nascita (GG/MM/AAAA): ");
        scanf("%d/%d/%d", &giorno, &mese, &anno);
    }while(giorno < 1 || giorno > 31 || mese < 1 || mese > 12 || anno < 1900 || anno > 2025);
    do{
        printf("Inserisci il sesso (M/F): ");
        scanf(" %d", &sesso);
    }while(sesso != 'M' && sesso != 'F');
    char Strccc[4], Strnnn[4], Stryy[3], Strm, Strdd[3], Strllll[5];
    int i=0, j=0;
    //Calcolo CCC
    int consonanti_cognome = 0, vocali_cognome = 0;
    while(cognome[i] != '\0' && consonanti_cognome < 3){
        if((cognome[i] >= 'A' && cognome[i] <= 'Z') || (cognome[i] >= 'a' && cognome[i] <= 'z')){
            if(cognome[i] != 'A' && cognome[i] != 'E' && cognome[i] != 'I' && cognome[i] != 'O' && cognome[i] != 'U' &&
               cognome[i] != 'a' && cognome[i] != 'e' && cognome[i] != 'i' && (cognome[i] != 'o' && cognome[i] != 'u')){
                Strccc[j] = cognome[i];
                consonanti_cognome++;
                j++;
            }else{
                i++;
            } 
        }  
    }
    

    

}

