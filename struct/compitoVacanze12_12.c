/*compito vacanze di natale*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string;
typedef struct Canzone{
    string titolo;
    string artista;
    int durata;
    int id;
    Canzone* next;
}Canzone;
typedef struct Playlist{
    string nome;
    Canzone* head;
    Canzone* coda;
}Playlist;
typedef struct lista{
    Playlist* p;
    struct lista* next;
}lista;
void stampaMenu(){
    printf("1. Crea playlist\n");
    printf("2. Aggiungi canzone\n");
    printf("3. Rimuovi canzone\n");
    printf("4. Stampa playlist\n");
    printf("5. Esci\n");

}
void stampaCanzone(Canzone* c){
    printf("ID: %d\nTitolo: %s\nArtista: %s\nDurata: %d\n",c->id,c->titolo,c->artista,c->durata);
}
void setCanzone(Canzone* c, int id, string titolo, string artista, int durata){
    printf("Inserimento canzone...\n");
    printf("Inserisci titolo: ");
    fgets(titolo, 20, stdin);
    printf("Inserisci artista: ");
    fgets(artista, 20, stdin);
    printf("Inserisci durata: ");
    scanf("%d",&durata);
    c->id=id;
}
lista* creaPlaylist(lista* head){
    Playlist* p=(Playlist*)malloc(sizeof(Playlist));
    char nome[20];
    printf("Inseriscinome playlist: ");
    fgets(nome, 20, stdin);
}
































































