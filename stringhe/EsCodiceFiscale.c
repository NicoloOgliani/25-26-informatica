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
#include <ctype.h>
#include <string.h>

//ccc
void crea_ccc(char *cognome, char *ris) {
    char consonanti[15];
    char vocali[15];
    int cntConsonanti = 0, cntVocali = 0; 
    int i = 0;

    while (cognome[i] != '\0') {
        char lettera = cognome[i];
        if (lettera == 'a' || lettera == 'e' || lettera == 'i' || lettera == 'o' || lettera == 'u' ||
            lettera == 'A' || lettera == 'E' || lettera == 'I' || lettera == 'O' || lettera == 'U') {
            vocali[cntVocali++] = lettera;//metto nella stringa vocali le vocali trovate
            //sia minuscole che maiuscole
        } else if ((lettera >= 'a' && lettera <= 'z') || (lettera >= 'A' && lettera <= 'Z')) {
            consonanti[cntConsonanti++] = lettera;
            //metto le consonanti trovate nella stringa consonanti sia minusc che maiusc
        }
        i++;
    }

    i = 0;
    while (i < 3 && cntConsonanti > 0) {
        ris[i++] = consonanti[cntConsonanti--];//metto nella nuova str le consonanti al contrario
    }
    while (i < 3 && cntVocali > 0) {
        ris[i++] = vocali[cntVocali--];//metto nella nuova str le vocali al contrario
    }
    while (i < 3) {
        ris[i++] = 'X';
    }
    ris[3] = '\0';

    //inverto perchè avevo fatto al contrario
    char temp;
    temp = ris[0]; 
    ris[0] = ris[2]; 
    ris[2] = temp;
}

//nnn
void crea_nnn(char *nome, char *ris) {
    char consonanti[15];
    char vocali[15];
    int cntConsonanti = 0, cntVocali = 0;
    int i = 0;

    while (nome[i] != '\0') {
        char lettera = nome[i];
        if (lettera == 'a' || lettera == 'e' || lettera == 'i' || lettera == 'o' || lettera == 'u' ||
            lettera == 'A' || lettera == 'E' || lettera == 'I' || lettera == 'O' || lettera == 'U') {
            vocali[cntVocali++] = lettera;
        } else if ((lettera >= 'a' && lettera <= 'z') || (lettera >= 'A' && lettera <= 'Z')) {
            consonanti[cntConsonanti++] = lettera;
        }
        i++;
    }

    if (cntConsonanti >= 4) {
        ris[0] = consonanti[0];//se ci sono più di 4 consonanti
        ris[1] = consonanti[2];
        ris[2] = consonanti[3];
    } else {
        i = 0;
        while (i < 3 && cntVocali > 0) ris[i++] = consonanti[cntConsonanti--];
        while (i < 3 && cntVocali > 0) ris[i++] = vocali[cntVocali--];
        while (i < 3) ris[i++] = 'X';
        //riempio la stringa finale al conrtrario per non modificare i cnt
    }
    ris[3] = '\0';

    //cambia ordine
    char temp;
    for (i = 0; i < 3; i++) {
        temp = ris[i];
        ris[i] = ris[2-i];
        ris[2-i] = temp;
    }
}

//lettera mese
char mese_in_lettera(char d1, char d2) {
    
}


int main() {
    char cognome[40], nome[40], data[11], genere;
    char parte1[4], parte2[4], anno[3], lettera_mese, giorno[3];
    char codice[16];

    printf("CODICE FISCALE\n\n");
    printf("Inserisci il cognome: \n");
    fgets(cognome, 40, stdin);
    printf("Inserisci il nome: \n");
    fgets(nome, 40, stdin);
    do{
        printf("Inserisci la data: \n");
        fgets(data, 11, stdin);
    }while(strlen(data)!=10 || data[2]!='/' || data[5]!= '/');
    do{
        printf("Inserisci il genere M oppure F: ");
        fgets(&genere, 3, stdin);
    }while(genere != 'M' && genere != 'F');
    //ccc
    crea_ccc(cognome, parte1);
    //nnn
    crea_nnn(nome, parte2);
    //yy
    anno[0] = data[8];
    anno[1] = data[9];
    anno[2] = '\0';
    //lettera mese
    lettera_mese = mese_in_lettera(data[3], data[4]);

    return 0;
}


    


   
    