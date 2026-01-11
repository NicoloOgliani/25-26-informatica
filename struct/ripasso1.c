#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{
    int dato;
    struct Nodo* next;
}Nodo;
typedef struct{
    Nodo* testa;
    int lunghezza;
}Lista;
//CREAZIONE LISTA
Lista* creaLista(){
    Lista* lista=(Lista*)malloc(sizeof(Lista));
    lista->testa=NULL;
    lista->lunghezza=0;
    return lista;
}
//INSERIMENTO ELEMENTI
//INIZIO
void inserisciInizio(Lista* lista, int valore){
    Nodo* nuovonodo=(Nodo*)malloc(sizeof(Nodo));
    nuovonodo->dato=valore;
    nuovonodo->next=lista->testa;
    lista->testa=nuovonodo;
    lista->lunghezza++;
}
//FINE
void inserisciFine(Lista* lista, int valore){
    Nodo* nuovonodo=(Nodo*)malloc(sizeof(Nodo));
    nuovonodo->dato=NULL;
    nuovonodo->next=NULL;
    if(lista->testa==NULL){
        lista->testa=nuovonodo;
    }
    else{
        Nodo* current=lista->testa;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=nuovonodo;
    }
    lista->lunghezza++;
}
//IN POSIZIONE SPECIFICA
void inserisci_in_posizione(Lista* lista, int valore, int posizione){
    if(posizione<0 || posizione>lista->lunghezza){
        printf("Posizione non valida");
        return;
    }
    if(posizione==0){
        inserisciInizio(lista, valore);
    }
    Nodo* nuovonodo=(Nodo*)malloc(sizeof(Nodo));
    nuovonodo->dato=valore;
    Nodo* current=lista->testa;
    for(int i=0; i<posizione-1; i++){
        current=current->next;
    }
    nuovonodo->next=current->next;
    current->next=nuovonodo;
    lista->lunghezza++;
}
//RICERCA ELEMENTI
int ricerca(Lista* lista, int valore){
    Nodo* current=lista->testa;
    int posizione=0;
    while(current!=NULL){
        if(current->dato==valore){
            return posizione;
        }
        current=current->next;
        posizione++;
    }
    return-1;
}
//CANCELLAZIONE ELEMENTI