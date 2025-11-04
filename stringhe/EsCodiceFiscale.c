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
// Funzioni
void prendi_cognome(char *buf);
void prendi_nome(char *buf);
void prendi_data(char *buf);
void prendi_genere(char *gen);
void crea_ccc(char *cognome, char *ris);
void crea_nnn(char *nome, char *ris);
char mese_in_lettera(char d1, char d2);
void giorno_codice(int g, char gen, char *ris);
void monta_codice(char *c1, char *c2, char *yy, char m, char *dd, char *finale);

int main() {
    char cognome[40], nome[40], data[11], genere;
    char parte1[4], parte2[4], anno[3], lettera_mese, giorno[3];
    char codice[16];

    printf("*** CODICE FISCALE (senza controllo) ***\n\n");

    prendi_cognome(cognome);
    prendi_nome(nome);
    prendi_data(data);
    prendi_genere(&genere);

    // === CCC ===
    crea_ccc(cognome, parte1);

    // === NNN ===
    crea_nnn(nome, parte2);

    // === YY ===
    anno[0] = data[8];
    anno[1] = data[9];
    anno[2] = '\0';

    // === M ===
    lettera_mese = mese_in_lettera(data[3], data[4]);

    // === DD ===
    int g = (data[0] - '0') * 10 + (data[1] - '0');
    giorno_codice(g, genere, giorno);

    // === CODICE FINALE ===
    monta_codice(parte1, parte2, anno, lettera_mese, giorno, codice);

    printf("\nRisultato: %s\n", codice);

    return 0;
}

// Legge cognome con getchar, solo lettere
void prendi_cognome(char *buf) {
    int i = 0;
    char c;
    printf("Cognome: ");
    while ((c = getचार()) != '\n') {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (i < 39) buf[i++] = c;
        }
    }
    buf[i] = '\0';
    if (i == 0) {
        printf("Errore: cognome vuoto!\n");
        prendi_cognome(buf);
    }
}

// Legge nome
void prendi_nome(char *buf) {
    int i = 0;
    char c;
    printf("Nome: ");
    while ((c = getchar()) != '\n') {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (i < 39) buf[i++] = c;
        }
    }
    buf[i] = '\0';
    if (i == 0) {
        printf("Errore: nome vuoto!\n");
        prendi_nome(buf);
    }
}

// Legge data GG/MM/AAAA
void prendi_data(char *buf) {
    int i = 0, ok = 1;
    char c;
    do {
        ok = 1;
        i = 0;
        printf("Data (GG/MM/AAAA): ");
        while ((c = getchar()) != '\n' && i < 10) {
            if ((c >= '0' && c <= '9') || c == '/') {
                buf[i++] = c;
            }
        }
        buf[i] = '\0';

        if (i != 10 || buf[2] != '/' || buf[5] != '/') {
            ok = 0;
            printf("Scrivi GG/MM/AAAA\n");
            continue;
        }

        // Controlla cifre
        for (int j = 0; j < 10; j++) {
            if (j == 2 || j == 5) continue;
            if (buf[j] < '0' || buf[j] > '9') ok = 0;
        }
        if (!ok) printf("Solo numeri!\n");

    } while (!ok);
}

// Legge M o F
void prendi_genere(char *gen) {
    char c;
    do {
        printf("Genere (M/F): ");
        c = getchar();
        while (getchar() != '\n');
        if (c == 'M' || c == 'm') *gen = 'M';
        else if (c == 'F' || c == 'f') *gen = 'F';
        else printf("Scrivi M o F!\n");
    } while (*gen != 'M' && *gen != 'F');
}

// Crea CCC (3 consonanti cognome)
void crea_ccc(char *cognome, char *ris) {
    char consonanti[15] = {0};
    char vocali[15] = {0};
    int nc = 0, nv = 0, i = 0;

    while (cognome[i] != '\0') {
        char lettera = cognome[i];
        if (lettera == 'a' || lettera == 'e' || lettera == 'i' || lettera == 'o' || lettera == 'u' ||
            lettera == 'A' || lettera == 'E' || lettera == 'I' || lettera == 'O' || lettera == 'U') {
            vocali[nv++] = lettera;
        } else if ((lettera >= 'a' && lettera <= 'z') || (lettera >= 'A' && lettera <= 'Z')) {
            consonanti[nc++] = lettera;
        }
        i++;
    }

    i = 0;
    while (i < 3 && nc > 0) {
        ris[i++] = consonanti[--nc];
    }
    while (i < 3 && nv > 0) {
        ris[i++] = vocali[--nv];
    }
    while (i < 3) {
        ris[i++] = 'X';
    }
    ris[3] = '\0';

    // Inverti (perché ho preso dall'ultima)
    char temp;
    temp = ris[0]; ris[0] = ris[2]; ris[2] = temp;
    if (ris[1] != 'X') {
        temp = ris[1]; ris[1] = ris[1]; // no-op, ma per stile
    }
}

// Crea NNN (nome, regola speciale)
void crea_nnn(char *nome, char *ris) {
    char consonanti[15] = {0};
    char vocali[15] = {0};
    int nc = 0, nv = 0, i = 0;

    while (nome[i] != '\0') {
        char lettera = nome[i];
        if (lettera == 'a' || lettera == 'e' || lettera == 'i' || lettera == 'o' || lettera == 'u' ||
            lettera == 'A' || lettera == 'E' || lettera == 'I' || lettera == 'O' || lettera == 'U') {
            vocali[nv++] = lettera;
        } else if ((lettera >= 'a' && lettera <= 'z') || (lettera >= 'A' && lettera <= 'Z')) {
            consonanti[nc++] = lettera;
        }
        i++;
    }

    if (nc >= 4) {
        ris[0] = consonanti[0];
        ris[1] = consonanti[2];
        ris[2] = consonanti[3];
    } else {
        i = 0;
        while (i < 3 && nc > 0) ris[i++] = consonanti[--nc];
        while (i < 3 && nv > 0) ris[i++] = vocali[--nv];
        while (i < 3) ris[i++] = 'X';
    }
    ris[3] = '\0';

    // Inverti per ordine corretto
    char temp;
    for (i = 0; i < 3/2; i++) {
        temp = ris[i];
        ris[i] = ris[2-i];
        ris[2-i] = temp;
    }
}

// Mese → lettera
char mese_in_lettera(char d1, char d2) {
    int m = (d1 - '0') * 10 + (d2 - '0');
    char tabella[12] = {'A','B','C','D','E','H','L','M','P','R','S','T'};
    return tabella[m-1];
}

// Giorno con +40 per donne
void giorno_codice(int g, char gen, char *ris) {
    int valore = g;
    if (gen == 'F') valore += 40;
    ris[0] = '0' + (valore / 10);
    ris[1] = '0' + (valore % 10);
    ris[2] = '\0';
}

// Monta il codice
void monta_codice(char *c1, char *c2, char *yy, char m, char *dd, char *finale) {
    int pos = 0;
    for (int i = 0; i < 3; i++) finale[pos++] = c1[i];
    for (int i = 0; i < 3; i++) finale[pos++] = c2[i];
    for (int i = 0; i < 2; i++) finale[pos++] = yy[i];
    finale[pos++] = m;
    for (int i = 0; i < 2; i++) finale[pos++] = dd[i];
    finale[pos++] = 'G';
    finale[pos++] = '1';
    finale[pos++] = '8';
    finale[pos++] = '6';
    finale[pos] = '\0';
}

    
    



    


   
    