typedef int Dato;
typedef struct nodo{
    Dato dato;
    struct nodo *next;
}Nodo;

typedef Nodo *Lista;


void stampaLista(Lista l);
void insTesta(Lista *pl, Dato d);
Lista* ricerca(Lista* pl, Dato d);
void insOrd(Lista* l, Dato d);
void rimuoviTesta(Lista *l);
int rim_elem(Lista* pl, Dato d);
void nuovaLista(Lista *pl);
Lista insertionSort(Lista l1);
Lista insertionSortConEliminazione(Lista l1);