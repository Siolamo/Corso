#include <stdio.h>
#include <stdlib.h>
#include "listaStudenti.h"
int main(int argc, char *argv[])
{
    FILE *f;
    if(argc!=2)
    {
        printf("Uso: %s file.dat\n",argv[0]);
        exit(1);
    }
   if(!(f = fopen(argv[1], "rb")))
   {
    printf("Errore nella lettura del file %s\n", argv[1]);
    exit(100);
   }

   Record r;
   Lista l;
   nuovaLista(&l);
   while(fread(&r, sizeof(Record), 1, f))
   {
    aggiorna(&l, r);
   }

   stampaLista(l);
   printf("\n------------------------------------\n");
   printf("Stampa lista ordinata\n");
   Lista l2;
   ordina(l, &l2);
   stampaLista(l2);

   if((fclose(f)!=0))
   {
    printf("errore durante la chiusura del file %s\n",argv[1]);
    exit(3);
   }
   
  
}