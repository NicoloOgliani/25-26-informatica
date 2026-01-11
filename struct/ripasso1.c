#include <stdio.h>
#include <stdlib.h>
//LISTA SEMPLICEMENTE COLLEGATA
typedef struct Nodo{
    int dato;
    struct Nodo* next;
}Nodo;
typedef struct{
    Nodo* testa;
    int lunghezza;
}Lista;
//LISTA CIRCOLARE
typedef struct nodoC{
    int dato;
    struct nodoC next;
}nodoC;
typedef struct{
    nodoC* testa;
    int lunghezza;
}listaC;
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
//DAL PRINCIPIO
void cancellaInizio(Lista* lista){
    if(lista->testa==NULL){
        return;
    }
    Nodo* temp=lista->testa;
    lista->testa=lista->testa->next;
    free(temp);
    lista->lunghezza--;
}
//DALLA FINE
void cancellaFine(Lista* lista){
    if(lista->testa==NULL) return;
    if(lista->testa->next==NULL){
        free(lista->testa);
        lista->testa=NULL;
    }
    else{
        Nodo* current=lista->testa;
        while(current->next->next!=NULL){
            current=current->next;
        }
        free(current->next);
        current->next=NULL;
    }
    lista->lunghezza--;

}
//PER VALORE
void cancellaPerValore(Lista* lista, int valore){
    if(lista->testa==NULL) return;
    //se l'elemento è in testa
    if(lista->testa->dato==valore){
        Nodo* temp=lista->testa;
        lista->testa=lista->testa->next;
        free(temp);
        lista->lunghezza--;
        return;
    }
    //ricerca
    Nodo* current=lista->testa;
    while(current->next!=NULL){
        if(current->next->dato==valore){
            Nodo* temp=current->next;
            current->next=current->next->next;
            free(temp);
            lista->lunghezza--;
            return;
        }
        current=current->next;

    }
}
//STAMPA
void stampaLista(Lista* lista){
    Nodo* current=lista->testa;
    printf("Lista: ");
    while(current!=NULL){
        printf("%d", current->dato);
        current=current->next;
    }
    printf("NULL");
    printf("%d", lista->lunghezza);
}
//LIBERA MEMORIA
void liberaMemoria(Lista* lista){
    Nodo* current=lista->testa;
    while(current!=NULL){
        Nodo* temp=current;
        current=current->next;
        free(temp);
    }
    free(lista);
}
//CIRCOLARI
//CREAZIONE LISTA
void creaListaC(){
    listaC* lista=(listaC*)malloc(sizeof(listaC));
    lista->testa=NULL;
    lista->lunghezza=0;
    return lista;
}
//INSERIMENTO
//ALLA FINE
void inserisciFineC(listaC* lista, int valore){
    nodoC* nuovonodo=(nodoC*)malloc(sizeof(nodoC));
    nuovonodo->dato=valore;
    if(lista->testa==NULL){
        lista->testa=nuovonodo;
        nuovonodo->next=nuovonodo;
    }
    else{
        nodoC* current=lista->testa;
        while(current->next!=lista->testa){
            current=current->next;
        }
        nuovonodo->next=lista->testa;
        current->next=nuovonodo;
    }
    lista->lunghezza++;

}
//ALL'INIZIO
void inserisciInizioC(listaC* lista, int valore){
    nodoC* nuovonodo=(nodoC*)malloc(sizeof(nodoC));
    nuovonodo->dato=valore;
    if(lista->testa==NULL){
        lista->testa=nuovonodo;
        nuovonodo->next=nuovonodo;
    }
    else{
        nodoC* current=lista->testa;
        while(current->next!=lista->testa){
            current=current->next;
        }
        nuovonodo->next=lista->testa;
        current->next=nuovonodo;
        lista->testa=nuovonodo;
    }
    lista->lunghezza++;
}