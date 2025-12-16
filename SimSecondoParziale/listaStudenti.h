typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct
{
    int matricola;
    char esame[40];
    Data d;
    int voto;
    
}Record;


typedef struct{
    int matricola;
    int somma_voti;
    int numero_esami;
} Dato;

typedef struct nodo {
    Dato dato;
    struct nodo *next;
} Nodo ;

typedef Nodo* Lista;

void StaData(Data d);
void nuovaLista(Lista *l);
void aggiorna(Lista *l,Record r);
void stampaLista(Lista l);
void ordina(Lista l1, Lista *pl2);