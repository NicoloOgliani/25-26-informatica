/* Registarte le informazioni di alcuni Libri ad esempio 
	titolo, autore, anno e prezzo, determinare il libro 
	più costoso e il più vecchio. 
	Eliminare un libro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LIBRO{
	char titolo[40];
	char autore[20];
	int anno;
	float prezzo;
};
typedef char* Stringa;
void Compattamento(Stringa buffer, int lunghezza){				
	
    if(lunghezza>0 && buffer[lunghezza-1]=='\n'){
        buffer[lunghezza-1] = '\0';
        lunghezza--;
    }
}

int main(){
	struct LIBRO *libri;
	char libro[40];
	int i, j, n=3, datato, i_costoso, i_datato, lun;
	float costoso;
	
	//allocazione dei primi 3 elementi
	libri = (struct LIBRO*)malloc(n * sizeof(struct LIBRO));
    
    if (libri == NULL) {
        printf("Errore: allocazione memoria fallita\n");
        return 1;
    }
    
    //inserimento dei dati
	strcpy(libri[0].titolo, "L'amore mio non muore");
	strcpy(libri[0].autore, "Roberto Saviano");
	libri[0].anno = 2025;
	libri[0].prezzo = 19.5;

	strcpy(libri[1].titolo, "La tua voce e\' un drago alato");
	strcpy(libri[1].autore, "Alessandra Battaglia");
	libri[1].anno = 2024;
	libri[1].prezzo = 18.5;
	
	strcpy(libri[2].titolo, "Il diritto di contare");
	strcpy(libri[2].autore, "Margot Lee Shetterly");
	libri[2].anno = 2017;
	libri[2].prezzo = 14;
	/*
	//visualizzazione dati
	printf("=== Lista Libri ===\n");
    for (i = 0; i < n; i++) {
        printf("Libro %d:\n", i + 1);
        printf("  Titolo: %s\n", libri[i].titolo);
        printf("  Autore: %s\n", libri[i].autore);
        printf("  Anno: %d anni\n", libri[i].anno);
        printf("  Prezzo: euro %.2f\n\n", libri[i].prezzo);
    }*/
    
    //supponiamo di voler aggiungere un libro
    //reallochiamo a 4 elementi
    n += 1;
    libri = (struct LIBRO*)realloc(libri, n * sizeof(struct LIBRO));
    
    if (libri == NULL) {
        printf("Errore: ridimensionamento fallito\n");
        return 1;
    }
	
	strcpy(libri[3].titolo, "Orgoglio e pregiudizio");
	strcpy(libri[3].autore, "Jane Austen");
	libri[3].anno = 1813;
	libri[3].prezzo = 9;
	
	//Visualizziamo l'Array
    for (i = 0; i < n; i++) {
        printf("Libro %d:\n", i + 1);
        printf("  Titolo: %s\n", libri[i].titolo);
        printf("  Autore: %s\n", libri[i].autore);
        printf("  Anno: %d anni\n", libri[i].anno);
        printf("  Prezzo: euro %.2f\n\n", libri[i].prezzo);
    }
    
    //cerchiamo quello più costoso
    costoso = libri[0].prezzo;
    i_costoso = 0;
    for (i = 1; i < n; i++) {
        if( libri[i].prezzo > costoso){
        	costoso = libri[i].prezzo;
			i_costoso = i;	
		}  	
    }
    printf("Il libro piu\' costoso e\': %s\n", libri[i_costoso].titolo);
	
	//cerchiamo quello più vecchio
	datato = libri[0].anno;
    i_datato = 0;
    for (i = 1; i < n; i++) {
        if( libri[i].anno < datato){
        	datato = libri[i].anno;
			i_datato = i;	
		}  	
    }
    printf("Il libro piu\' datato e\': %s\n", libri[i_datato].titolo);
    
    //eliminiamo un libro 
    printf("\nInserisci il tiolo del libro da eliminare: ");		
	fgets(libro, 50, stdin); 
	lun = strlen(libro);
	Compattamento(libro, lun);
	for (i = 0; i < n; i++) {
		if( !(strcmp(libri[i].titolo,libro)) ){
			for(j=i; j<(n-1); j++){
				strcpy(libri[j].titolo,libri[j+1].titolo);
				strcpy(libri[j].autore,libri[j+1].autore);
				libri[j].anno = libri[j+1].anno;
				libri[j].prezzo = libri[j+1].prezzo;
			}
			n-=1;	
		}  	
    }
    
    //reallochiamo il nuovo array 
    libri = (struct LIBRO*)realloc(libri, n * sizeof(struct LIBRO));
    
    if (libri == NULL) {
        printf("Errore: ridimensionamento fallito\n");
        return 1;
    }
    //Visualizziamo l'Array
    for (i = 0; i < n; i++) {
        printf("Libro %d:\n", i + 1);
        printf("  Titolo: %s\n", libri[i].titolo);
        printf("  Autore: %s\n", libri[i].autore);
        printf("  Anno: %d anni\n", libri[i].anno);
        printf("  Prezzo: euro %.2f\n\n", libri[i].prezzo);
    }
	
	free(libri);
	libri=NULL;
}
