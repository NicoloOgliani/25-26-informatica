/*date le informazioni di alcuni studenti:
cognome, nome, classe, maticola, n_certifi
e le informazioni riguardo le certificazioni di ogni studente:
matricola, esame(corso, livello) */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Studente{
	char Cognome[20];
	char Nome[20];
	char classe[3];
	int matricola;
	int n_certif;
};

struct Certificazione{
	int matricola;
	struct esame{
		char corso[20];
		int livello;
	}esame;
};

int main(){
	struct Studente *studenti;
	struct Certificazione *certificazioni;
	int n, i, j, c_max=0, num=0, i_max;
	
	//Allochiamo i primi 2 studenti 
	n = 3;
	studenti = (struct Studente*)malloc(n * sizeof(struct Studente));
    certificazioni = (struct Certificazione*)malloc(n * sizeof (struct Certificazione));
    if (studenti == NULL) {
        printf("Errore: allocazione memoria fallita\n");
        return 1;
    }
	if (certificazioni == NULL) {
        printf("Errore: allocazione memoria fallita\n");
        return 1;
    }

    //inseriamo gli elementi e stampiamoli
    strcpy(studenti[0].Cognome, "Rossi");
	strcpy(studenti[0].Nome, "Giulio");
	strcpy(studenti[0].classe, "4I");
	studenti[0].matricola = 123;  
	studenti[0].n_certif = 0;  
	
	strcpy(studenti[1].Cognome, "Verdi");
	strcpy(studenti[1].Nome, "Carlo");
	strcpy(studenti[1].classe, "3I");
	studenti[1].matricola = 456;  
	studenti[1].n_certif = 0; 
	
	strcpy(studenti[2].Cognome, "Gialli");
	strcpy(studenti[2].Nome, "Sofia");
	strcpy(studenti[2].classe, "4I");
	studenti[2].matricola = 789;
	studenti[2].n_certif = 0; 
	 
	//adesso inseriamo in base alle matricole i corsi e il livello
	certificazioni[0].matricola = 123;
	strcpy(certificazioni[0].esame.corso,"inglese");
	certificazioni[0].esame.livello = 3;
	
	certificazioni[1].matricola = 123;
	strcpy(certificazioni[1].esame.corso,"tedesco");
	certificazioni[1].esame.livello = 1; 
	
	certificazioni[2].matricola = 789;
	strcpy(certificazioni[2].esame.corso,"spagnolo");
	certificazioni[2].esame.livello = 1;  
	
	//visualizziamo gli studenti
	printf("=== Lista Studenti ===\n");
    for (i = 0; i < n; i++) {
        printf("Studente %d:\n", i + 1);
        printf("  Cognome: %s\n", studenti[i].Cognome);
        printf("  Nome: %s\n", studenti[i].Nome);
        printf("  Classe: %s\n", studenti[i].classe);
        printf("  Matricola:  %d\n", studenti[i].matricola);
        printf("  Numero Certificazioni:  %d\n\n", studenti[i].n_certif);
    }
    //visualizziamo le certificazioni relative alle matricole
	printf("=== Lista Certificazioni ===\n");
    for (i = 0; i < n; i++) {
        printf("  Matricola: %d\n", certificazioni[i].matricola);
        printf("  Corso: %s\n", certificazioni[i].esame.corso);
        printf("  Livello: %d\n\n", certificazioni[i].esame.livello);
    }
    
    //calcoliamo il numero delle certificazioni di ogni studente
    for(i=0; i<n; i++){
    	num = studenti[i].matricola;
    	for(j=0; j<n; j++){
    		if(certificazioni[j].matricola == num){
    			studenti[i].n_certif +=1;
			}
		}
	}
	
	//visualizziamo gli studenti
	printf("=== Lista Studenti ===\n");
    for (i = 0; i < n; i++) {
        printf("Studente %d:\n", i + 1);
        printf("  Cognome: %s\n", studenti[i].Cognome);
        printf("  Nome: %s\n", studenti[i].Nome);
        printf("  Classe: %s\n", studenti[i].classe);
        printf("  Matricola:  %d\n", studenti[i].matricola);
        printf("  Numero Certificazioni:  %d\n\n", studenti[i].n_certif);
    }
	
	//calcoliamo lo studente con pių certificazioni
	c_max = studenti[0].n_certif;
	i_max = 0;
	for(i=0; i<n; i++){
    		if(studenti[i].n_certif > c_max){
    			c_max = studenti[i].n_certif;
    			i_max = i;
			}
	}	
	printf("Lo studente con piu\' certificazioni e\': %s, %s, %s, matricola: %d",studenti[i_max].Cognome , studenti[i_max].Nome, studenti[i_max].classe, studenti[i_max].matricola);
	free(studenti);
	free(certificazioni);
}
