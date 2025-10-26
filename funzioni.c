#include <stdio.h>

/*
Cos'è una funzione?
Una funzione non è nient altro che un blocco di codcice eseguibile alla chiamata
esempio di funzione:
*/
int miaFunzione()
{
    return 0;
}

/*
Studiamo la sintassi:
int miaFunzione()

int è quello che restituirà la funzione.
vediamo che alla fine della funzione c'è un 'return 0;', 0 è un intero
se li al posto di int avessi scritto per esempio char, avrei dovuto mettere un return di tipo char, es: retunrn 'c';
avessi avuto una funzioned che non restituisce niente, avrei messo void

miaFunzione, è il nome della funzione, la posso chiamare come voglio, l'avrei potuta chiamare anche pippo baudo

*/

/*
La chiamata delle funzioni è molto semplice,
sappiate che anche printf e scanf sono 2 funzioni
al che ci porta a questa sintassi:
printf();
quindi
la chiamata di una funziona creata da noi sarà: (andare a linea)
*/

/*
Le funzioni, si comportano esattamente come di blocchi di codice come detto prima, infatti possiamo fare quello che vogliamo
dentro a una fuznione
es 1:
*/

int FunzioneComplessa()
{
    int a,b; //le variabili che diachiaro dentro a una funzione vengono viste solo
             // e soltatno da quella funzione (in poche parole, non posso usare, QUESTI SPECIFICI a e b, nel main o da altre parte)
    a=5;
    b=8;
    return a + b;
}

/*
Es 2:
*/

void FunzioneComplessa2()  //void perchè questa funzione non restituisce nulla (non c'è il return)
{
    printf("heaven are you watching, it's time to make a very special deal");
}

/*
Abbiamo visto nella funziona qua sopra, che possiamo utilizzare delle variabili come facciamo nel main.
Ma se noi volessimo fare una funzione che al posto di fare la somma soltanto con a=5 e b=8, ci faccia la somma
con dei numeri che vogliamo noi?

qui entrano in gioco i Parametri.

i parametri di una funzione sono dei valori che vengono passati "esternamente" alla chiamata della funzione, e vengono specificati(creati) nella funzione alla sua dichiarazione:
esempio:


*/

int sommaConParametri(int a, int b)
{
    return a+b;
}

/*
in questo caso abbiamo una funzione che:
1) int: restiusice un intero
2) sommaConParametri: si chiama così
3) (int a, int b): richiede due parametri INTERI


*/

int main()
{
    miaFunzione()
}



