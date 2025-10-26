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
la chiamata di una funziona creata da noi sarà: (andare a linea 122)
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
    printf("il primo valore è: %d e il secondo è: %d\n",a,b );
    return a+b;
}

/*
in questo caso abbiamo una funzione che:
1) int: restiusice un intero
2) sommaConParametri: si chiama così
3) (int a, int b): richiede due parametri INTERI

I parametri, all'interno della funzione (sommaConParametri), vengono visti come due normalissime variabili,
in quella funzione avrei potuto usare a e b come volevo, in questo caso, ne sto semplicemente restituendo la somma.

Quindi, ovunque io vado a chiamare questa funzione, ne dovrò specificare i parametri es: (vai a linea 123)
ma andando alla linea 123, vediamo che chiamando la funzione così, quando andiamo ad eseguire il programma ci mostra solo il printf che
vediamo in linea 74, questo perchè con quella chiamata noi e come se stessimo scrivendo _ = a+b nello script senza farci effettivamente niente, senza stamparlo.
quindi, in questo caso, se vogliamo vedere anche l'effetivo risultato di 'return a+b' dovremmo fare un printf che lo scriva (linea 124);
in questo caso il %d del printf in linea 124 viene rimpiazzato col valore di 'return a+b' che vediamo in linea 75, dove a e b sono i 
valori che gli passiamo appunto come parametri, in questo caso a=5 e b=3.

Se invece dobbiamo per esempio, invece che scrivere il risultato di a+b, ci serve tenere quel risultato in una variabile nel main
per poi andarlo a utilizzare in futuro, possiamo farlo!
dobbiamo prima di tutto guardare cosa restituisce la funzione (in questo caso con SommaConParametri, restituisce un intero (Linea 80)).
poi dobbiamo creare una variabile dello stesso tipo (in questo caso int);
e chiamare la funziona nell'assegnazione del valore della variabile (esempio linea 121)
così la variabile risultato creata a linea 121 verrà sostituita con il valore di 'return a+b' dove a=7, b=12;

*/


/*
!ATTENZIONE
! ORA ABBIAMO VISTO 3 MODI PER CHIAMARE UNA FUNZIONE
?1) int r  = miafunzione();
?2) miafunzione();
?3) printf("%d", mianfunzione());
! BISOGNA RICORDARSI CHE OGNI VOLTA CHE SI CHIAMA UNA FUNZIONE VERRà SEMPRE ESEGUITO
! TUTTO IL CODICE AL SUO INTERNO
! QUINDI ANCHE SE HO:
? int r = sommaConParametri(8,23); //un assegnazione di un valore
!E DENTRO 'sommaConParametri' HO SCRITTO UN PRINTF
!IL PRINTF VERRà SCRITTO!
!(e qualsiasi altra cosa io abbia scritto nella funzione, verrà eseguita)
*/

int main()
{
   //int risultato = sommaConParametri(7,12);
    miaFunzione();
    //sommaConParametri(5,3);
    printf("il risultato è: %d\n",sommaConParametri(5,3));
}

//! IMPORTANTISSIMO DA RICORDARE
//! LA FUNZIONE PRINCIPALE è IL MAIN ED è QUELLA CHE VIENE ESEGUITA QUANDO SI FA L'ESEGUIBILE
//! PER FARVI CAPIRE, LE FUNZIONI 'FunzioneComplessa()' e 'FunzioneComplessa2()' ESISTONO
//! MA NON VERRANO MAI ESEGUITE PERCHè NON CHIAMATE NEL MAIN O NON CHIAMATE IN NESSUNA DELLE FUNZIONE CHE POI VENGONO CHIAMATE NEL MAIN.

//l'avviso sopra anche per dirvi che volendo posso chiamare una funzione da me creata all'interno di un altra funzione:

int AltraFunzione()
{
    return sommaConParametri(5,3) / 2  //ho fatto una funzione a caso che restituisce la somma di due numeri diviso due
}

//addirittura volendo posso anche passare i parametri di una funzione come parametri ad un altra funzione:

int AltraAltraFunzione(int x,int y, int c)
{
    return sommaConParametri(x,y) / c //nel main io scriverei qualcosa tipo: AltraAltraFunzione(5,8,3)
                                      // e passerebbe come parametri 5 e 8 ad sommaConParametri e poi ne divide il risultato (quello che ritorna sommaConParametri) per il numero c (in questo caso 3)
}


//!ATTENZIONE
/*
Se io ora provassi a chiamarre o 'AltraFunzione' o 'AltraAltraFunzione' in main non andrebbe,
perchè bisogna ricordarsi che lo script viene sempre letto dall'alto al basso.
Quindi se io faccio una chiamata di una funzione che non ho ancora dichiaro non andrà
fra è letteralmente come scrivere:

int main()
{
  a=3;      //si capisce che c'è qualcosa che non va no?
  int a;    //sto assegnando un valore a una variabile non ancora dichiarata
}

darà errore.

quindi se io faccio 
--------------------------------
int miaFunzione()
{codice}


int main()
{
    miaFunzione();
}
----------------------------
è giusto

ma se io faccio :
-----------------------------
int main()
{
    miaFunzione();
}

int miaFunzione()
{codice}
----------------------------------

darà errore perchè abbiamo dichiarato la funzione dopo la chiamata
(vale anche quando si chiama una funzione dentro un'altra funzione)
*/