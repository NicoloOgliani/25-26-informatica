#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Canzone {
    int id;
    char titolo[50];
    char artista[50];
    int durata;
    struct Canzone* next;
} Canzone;

typedef struct Lista {
    Canzone* testa;
    int lunghezza;
} Lista;

int id_univoco = 0;

void stampa_canzone(Canzone *c);
void set_canzone(Canzone *c);
Lista* crea_lista();
void stampa_lista(Lista *l);
void inserisci_canzone_lista(Lista *l);
void ricerca_canzone_artista(Lista *l, char* artista);
void libera_memoria(Lista* l);
void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist);
void stampa_playlist(Lista* playlist);
void cancella_canzone_playlist(Lista *playlist);

int main() {
    Lista* lista_canzoni = crea_lista();
    Lista* playlist = crea_lista();

    int scelta;
    char artista[50];

    do {
        printf("\n===== SPOTIFY 0.0.0.1 =====\n");
        printf("1. Inserisci nuova canzone nella lista\n");
        printf("2. Stampa lista canzoni\n");
        printf("3. Cerca canzoni per artista\n");
        printf("4. Aggiungi canzone alla playlist\n");
        printf("5. Stampa playlist\n");
        printf("6. Cancella canzone dalla playlist\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                inserisci_canzone_lista(lista_canzoni);
                break;
            case 2:
                stampa_lista(lista_canzoni);
                break;
            case 3:
                printf("Inserisci artista da cercare: ");
                fgets(artista, 50, stdin);
                ricerca_canzone_artista(lista_canzoni, artista);
                break;
            case 4:
                inserisci_canzone_playlist(lista_canzoni, playlist);
                break;
            case 5:
                stampa_playlist(playlist);
                break;
            case 6:
                cancella_canzone_playlist(playlist);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }

    } while (scelta != 0);

    libera_memoria(lista_canzoni);
    libera_memoria(playlist);
    return 0;
}

void stampa_canzone(Canzone *c) {
    printf("id: %d, titolo: %s, artista: %s, durata: %d\n", c->id, c->titolo, c->artista, c->durata);
}

void set_canzone(Canzone *c) {
    int i;
    c->id = id_univoco;
    id_univoco++;

    printf("Inserisci titolo: ");
    fgets(c->titolo, 50, stdin);
    for (i = 0; c->titolo[i] != '\0'; i++) {
        if (c->titolo[i] == '\n') {
            c->titolo[i] = '\0';
            break;
        }
    }

    printf("Inserisci l'artista: ");
    fgets(c->artista, 50, stdin);
    for (i = 0; c->artista[i] != '\0'; i++) {
        if (c->artista[i] == '\n') {
            c->artista[i] = '\0';
            break;
        }
    }

    printf("Inserisci la durata della canzone: ");
    scanf("%d", &c->durata);
    getchar();
}

Lista* crea_lista() {
    Lista* l = (Lista*)malloc(sizeof(Lista));
    l->testa = NULL;
    l->lunghezza = 0;
    return l;
}

void stampa_lista(Lista *l) {
    printf("Lista canzoni disponibili:\n");
    Canzone* current = l->testa;
    while (current != NULL) {
        stampa_canzone(current);
        current = current->next;
    }
    if (l->lunghezza == 0) {
        printf("La lista è vuota.\n");
    } else {
        printf("Lunghezza lista: %d\n", l->lunghezza);
    }
}

void inserisci_canzone_lista(Lista *l) {
    Canzone* nuova_canzone = (Canzone*)malloc(sizeof(Canzone));
    set_canzone(nuova_canzone);
    nuova_canzone->next = NULL;
    if (l->testa == NULL) {
        l->testa = nuova_canzone;
    } else {
        Canzone* current = l->testa;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nuova_canzone;
    }
    l->lunghezza++;
    printf("Canzone inserita con successo.\n");
}

void ricerca_canzone_artista(Lista *l, char* artista) {
    int i;
    for (i = 0; artista[i] != '\0'; i++) {
        if (artista[i] == '\n') {
            artista[i] = '\0';
            break;
        }
    }

    printf("Canzoni dell'artista %s:\n", artista);
    Canzone* current = l->testa;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->artista, artista) == 0) {
            stampa_canzone(current);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Nessuna canzone trovata per questo artista.\n");
    }
}

void libera_memoria(Lista* l) {
    if (l == NULL || l->testa == NULL) {
        free(l);
        return;
    }

    Canzone* current = l->testa;
    Canzone* prev = NULL;

    do {
        prev = current;
        current = current->next;
        if (current == l->testa) {
            prev->next = NULL;
            break;
        }
    } while (current != NULL);

    current = l->testa;
    while (current != NULL) {
        Canzone* temp = current;
        current = current->next;
        free(temp);
    }
    free(l);
}

void inserisci_canzone_playlist(Lista *lista_canzoni, Lista *playlist) {
    printf("Inserisci l'id della canzone da aggiungere alla playlist: ");
    int id;
    scanf("%d", &id);
    getchar();

    Canzone* current = lista_canzoni->testa;
    while (current != NULL) {
        if (current->id == id) {
            Canzone* nuova_canzone = (Canzone*)malloc(sizeof(Canzone));
            strcpy(nuova_canzone->titolo, current->titolo);
            strcpy(nuova_canzone->artista, current->artista);
            nuova_canzone->durata = current->durata;
            nuova_canzone->id = current->id;
            if (playlist->testa == NULL) {
                playlist->testa = nuova_canzone;
                nuova_canzone->next = nuova_canzone;
            } else {
                Canzone* coda = playlist->testa;
                while (coda->next != playlist->testa) {
                    coda = coda->next;
                }
                coda->next = nuova_canzone;
                nuova_canzone->next = playlist->testa;
            }
            playlist->lunghezza++;
            printf("Canzone aggiunta alla playlist.\n");
            return;
        } else {
            current = current->next;
        }
    }
    printf("Canzone con id %d non trovata nella lista canzoni.\n", id);
}

void stampa_playlist(Lista* playlist) {
    if (playlist->testa == NULL) {
        printf("La playlist è vuota\n");
        return;
    }
    printf("Playlist:\n");
    Canzone* current = playlist->testa;
    do {
        stampa_canzone(current);
        current = current->next;
    } while (current != playlist->testa);
    printf("Lunghezza playlist: %d\n", playlist->lunghezza);
}

void cancella_canzone_playlist(Lista *playlist) {
    if (playlist->testa == NULL) {
        printf("La playlist è vuota\n");
        return;
    }
    printf("Inserisci l'id della canzone da cancellare dalla playlist: ");
    int id;
    scanf("%d", &id);
    getchar();

    Canzone* current = playlist->testa;
    Canzone* prev = NULL;

    do {
        if (current->id == id) {
            if (prev == NULL) {
                if (current->next == playlist->testa) {
                    free(current);
                    playlist->testa = NULL;
                } else {
                    Canzone* coda = playlist->testa;
                    while (coda->next != playlist->testa) {
                        coda = coda->next;
                    }
                    coda->next = current->next;
                    playlist->testa = current->next;
                    free(current);
                }
            } else {
                prev->next = current->next;
                free(current);
            }
            playlist->lunghezza--;
            printf("Canzone cancellata dalla playlist.\n");
            return;
        }
        prev = current;
        current = current->next;
    } while (current != playlist->testa);

    printf("Canzone con id %d non trovata nella playlist.\n", id);
}

































































