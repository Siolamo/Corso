#include "listaStudenti.h"
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

void nuovaLista(Lista *l)
{
    *l = NULL;
}


void insTesta(Lista *l, Dato d)
{
    Nodo *aux;
    aux = (Nodo*)malloc(sizeof(Nodo));
    if(aux==NULL)
    {
        printf("errore nella creazione del nodo!\n");
        exit(1);
    }
    aux->dato = d;
    aux->next= *l;
    *l = aux;

}

void aggiorna(Lista *l, Record r) 
{
    while(*l && (*l)->dato.matricola != r.matricola)
    {
        l = &(*l)->next;
    }
    if(*l==NULL)
    {
        Dato d;
        d.matricola = r.matricola;
        d.somma_voti = r.voto;
        d.numero_esami = 1;
        insTesta(l, d);
        
    }
    else 
    {
        (*l)->dato.numero_esami++;
        (*l)->dato.somma_voti+=r.voto;
            
    }
}

void stampaLista(Lista l)
{
    printf("[\n");
    while(l)
    {
        printf("{matricola: %d, n_esami: %d, sooma_voti: %d, media:%.2f}\n",l->dato.matricola, l->dato.numero_esami, l->dato.somma_voti, (float)l->dato.somma_voti/l->dato.numero_esami);
        l= l->next;
    }
    printf("]\n");
}

void insOrdPerNV(Lista *l,Dato d)
{
    while(*l && (*l)->dato.numero_esami> d.numero_esami)
    {
        l = &(*l)->next;
    }
    insTesta(l, d);
}

void insSort(Lista l)
{
    Lista l2;
}