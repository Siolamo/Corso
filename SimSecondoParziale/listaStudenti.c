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
//restituisce valore <0 se d1 precede di d2
//viceversa
int confronto(Dato d1,Dato d2)
{
    int r;
    r = d1.numero_esami - d2.numero_esami;
    if(r!=0)
    {
        return -r; //se la differeneza è negativa dobbiamo invertire di sengo cuz it means d2>d1
    }
    else {
        if((float)d1.somma_voti/d1.numero_esami<(float)d2.somma_voti/d2.numero_esami)
        {
            return 1;
        }
        else if((float)d1.somma_voti/d1.numero_esami>(float)d2.somma_voti/d2.numero_esami)
        {
            return -1;
        }
        else 
        {
            return 0;
        }
    }
}

void ins_ord(Lista *l1, Dato d)
{
    while(*l1&&confronto((*l1)->dato, d)<0)
    {
        l1 = &(*l1)->next;
    }
    insTesta(l1, d);
}

void ordina(Lista l1, Lista *pl2)
{
    nuovaLista(pl2);
    while(l1)
    {
        ins_ord(pl2, l1->dato);
        l1 = l1->next;
    }
}