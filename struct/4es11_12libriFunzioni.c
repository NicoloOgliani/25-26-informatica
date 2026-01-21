/* parte dell'esercizio LIBRI_4I con funzioni */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Libro {
    char titolo[100];
    char autore[100];
    int anno;
    float prezzo;
};

void inserisciLibroDaTastiera(struct Libro *l) {
    printf("Inserisci titolo: ");
    fgets(l->titolo, sizeof(l->titolo), stdin);
    l->titolo[strcspn(l->titolo, "\n")] = '\0';
    
    printf("Inserisci autore: ");
    fgets(l->autore, sizeof(l->autore), stdin);
    l->autore[strcspn(l->autore, "\n")] = '\0';

    printf("Inserisci anno di pubblicazione: ");
    scanf("%d", &l->anno);

    printf("Inserisci prezzo: ");
    scanf("%f", &l->prezzo);

    getchar(); // pulizia buffer newline
}

void stampa(struct Libro *l){
    printf("  Titolo: %s\n", l->titolo);
    printf("  Autore: %s\n", l->autore);
    printf("  Anno: %d anni\n", l->anno);
    printf("  Prezzo: euro %.2f\n\n", l->prezzo);
}

void calcolaCostoso(struct Libro *libri, int n){
	float costoso;
	int i_costoso,i;
	costoso = libri[0].prezzo;
    i_costoso = 0;
    for (i = 1; i < n; i++) {
        if( libri[i].prezzo > costoso){
        	costoso = libri[i].prezzo;
			i_costoso = i;	
		}  	
    }
    printf("Il libro piu\' costoso e\': %s\n", libri[i_costoso].titolo);
}

int main(){
	struct Libro libri[1];
	int i,n=0;
	
	printf("Inserisci il numero degli elementi da inserire: ");
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
	    printf("\n--- Inserimento libro %d ---\n", i + 1);
	    inserisciLibroDaTastiera(&libri[i]);
	}
    //visualizzazione dati
	printf("=== Lista Libri ===\n");
    for (i = 0; i < n; i++) {
    	stampa(&libri[i]);
    }
    //calcoliamo il pių costoso
    calcolaCostoso(libri,n);
}


