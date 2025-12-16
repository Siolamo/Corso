#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"


void stampaLista(Lista l)
{   
    printf("[");
    while (l!=NULL)
    {
        printf(" %d ", l->dato);
        l=l->next;
    }
    printf("]\n");
}


void insTesta(Lista *pl,Dato d)
{
    Nodo *aux;
    aux = (Nodo *)malloc(sizeof(Nodo));
    if(aux==NULL)
    {
        exit(100);
    }
    aux->dato=d;
    aux->next=*pl;
    *pl = aux;
}


Lista* ricerca(Lista* pl, Dato d)
{
    while(*pl)
    {
        if((*pl)->dato == d)
            break;
    
        pl = &(*pl) -> next;
    }

    return pl;

}

void insOrd(Lista* l, Dato d)
{
   
    while (*l&& (*l)->dato<d)
        l = &(*l)->next;    
    
    insTesta(l,d);
}

void rimuoviTesta(Lista *l)
{
    Nodo *c = *l;
    *l = (*l)->next;
    free(c);
}


int rim_elem(Lista* pl, Dato d)
{
    while(*pl&& (*pl)->dato!=d)
        pl = &(*pl)->next;
    
    if(*pl!=NULL)
    {
        rimuoviTesta(pl);
        return 1;
    }
    else
        return 0;

}


void elim_tutti(Lista* pl, Dato d)
{
    while(*pl)
    {
        printf("dato in lista= %d\ndato da eliminare= %d\n",(*pl)->dato,d);
        if((*pl)->dato==d)
        {
            rimuoviTesta(pl);
            elim_tutti(pl, d);
        }

        pl = &(*pl)->next;
    }
}

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

int len(Lista l)
{
    int n=0;
    while(l)
    {
        n++;
        l=l->next;
    }
    return n;
}
void insInMid(Lista *l, Dato d)
{
    int leng = len(*l);
    for(int i=0; i<leng/2;i++)
    {
        l = &(*l)->next;
    }
    insTesta(l,d);
    
    
}

void insCoda(Lista* lp, Dato d)
{
    
    while(*lp)
        lp = &(*lp)->next;

    insTesta(lp,d);

}

Lista insertionSort(Lista l1)
{
    Lista l2;
    nuovaLista(&l2);
    while(l1)
    {
        insOrd(&l2, l1->dato);
        l1 = l1->next;
    }
    return l2;
}

Lista insertionSortConEliminazione(Lista l1)
{
    Lista l2;
    nuovaLista(&l2);
    while(l1)
    {
        insOrd(&l2, l1->dato);
        rimuoviTesta(&l1);
    }
    return l2;
}