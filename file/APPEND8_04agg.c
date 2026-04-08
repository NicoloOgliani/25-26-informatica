/* Esempio di apertura file in append*/ 
#include <stdio.h>
int main(){
	FILE *fp;
	char frase[200];
	char scelta;
	
	//apriamo il file in append
	fp = fopen("righe.txt", "a");
	if (fp == NULL){
		printf("errore apertura file\n");
		return 1;
	}
	do{
		printf("Inserisci una frase: ");
		fgets(frase, sizeof(frase), stdin);
		//scriviamo la frase sul file
		fputs(frase, fp);
		
		printf("Vuoi inserire un'altra frase? (s/n): ");
		scanf("%c", &scelta);
		getchar();
	}while(scelta=='s' || scelta=='S');
	fclose(fp);
	printf("Le frasi sono state salvate sul file righe.txt");
	return 0;
}