#ifndef LIB_H
struct structStudente
{
    char nome[20];
    char cognome[20];
    int matricola;
    int voti[5];
    float media;
    struct structStudente *next;
};
typedef struct structStudente nodoStudente;
typedef nodoStudente *listaStudente;

struct structCorsto
{
    char descrizione[20];
    int id;
    listaStudente lp;
    listaStudente ln;
    listaStudente lt;
};
typedef struct structCorsto corso;

void inserisci_coda_lista(char *name,char *surname,int mat,int *grades,corso *cf);
void modifica_voti(int mat,int *grades,corso *cf);
void elimina_studente(int mat,corso *cf);
void inverti_positivi(listaStudente *lis);
void stampaLista(listaStudente lis);
listaStudente crea_unica_lista(listaStudente *lp,listaStudente *ln);








#endif // LIB_H
