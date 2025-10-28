#include <stdio.h>


/*
per una migliore comprensione del testo,
installare l'estensione "Better Comments" su visual studio.
(se vedete che inizio i commenti con //? o //!
è perchè con quella estensione diventano colorati)
*/




/*
?Allerta, in questo script ho creato più di un main solo per fare degli esempi, gli ho tutti chiamati mainN (n incrementa)
?Ricordarsi che soltanto il 'main' originale è quello che viene eseguito nell'eseguibile

Allora, per capire i puntatori dobbiamo prima aver ben chiaro ilo concetto di variabile.
deve essere chiaro che:
quando creiamo una variabile noi stiamo 'allocando dello spazio in memoria per quella variabile',
stiamo dicendo al computer di creare uno spazzietino nella memoria da poter scriverci e leggere un valore.

Ogni spazziettino di memoria che noi creiamo, ha un 'indirizzo', per indirizzo si intende un numero univoco
per distinguire le varie zone della memoria e quando noi creiamo un 'puntatore', creiamo qualcosa che appunta 'punta'
a un indirizzo di memoria.


forsè sarà più chiaro con un esempio pratico:

*/

int incremento(int a)
{
    return a++;
}

int main1()
{
    int x =5;
    printf("%d\n",incremento(x));
}

/*
qui abbiamo visto una funzione abbastanza semplice, gli passo un parametro, un valore, e lo mi restituisce
il valore incrementato.
io però potrei fare anche
*/

int funzioneComplessa(int a)
{
    a++;
    a*=2;
    a+=90/2-a;
    return a;
}

int main2()
{
    int x = 3;
    printf("\n%d\n",funzioneComplessa(x));
    printf("%d\n",x);
}

/*
in questo caso abbiamo una funziuone che fa più operazioni.
!NOTARE BENE
il printf in linea 49 ci restiuisce il valore di x dopo che è passato per tutti i
calcoli di 'funzioneComplessa'
!MA IL VALORE DI 'X' è RIMASTO INVARIATO (per dimostraverlo ho fatto un printf di 'x' dopo che abbiamo chiamato 'funzioneComplessa')
questo perchè, nel main ho creato una variabile x, e a sua volta gli è stato allocato il suo spazio in memoria con un indirizzo;
ma quando vado in 'funzioneComplessa', il 'int a' che si trova in quella funzione ha un altro spazio di memoria tutto suo con un altro indirizzo.
se io avessi voluto sovrascrivere il valore di x, avrei potuto farlo in 2 modi:

1) il metodo che già conoscioamo : x = funzioneComplessa(x); //in questo caso x viene sovrascritta col suo nuovo valore dopo tutti i calcoli di 'funzioneComplessa'

2)avrei dovuto craere una funzione che,in qualche modo, mi va a modificare DIRETTAMETNE il valore di x,
il che si puo fare con i puntatori; avendo l'indirizzo di memoria di una variabile io ne posso andare a modificare direttamente il valore.

semplicemente invece di passare 'x' alla funzione, ora proveremo a passargli l'indirizzo di memoria di x.


prima di tutto la funzione va modificata così
!NOTARE BENE
ho reso la funzione sottostante un 'void' in quanto, andando a modificare direttamente il valore di una variabile, non neccessito di alcun return.
*/

void miaFunzione(int* a) //l'* indica che si tratta di un puntatore.
{
   //!ATTENZIONE
   /*
   ora in questa funzione 'a' è uguale ad un indirizzo di memoria, quindi
   se eseguo un operazione tipo 'a++' NON STO INCREMENTANDO IL VALORE DI A
   sto cambiando indirizzo di memoria.
   Per riferirci al valore di 'a' dobbiamo usare la sintassi '*a'.

   */

   //a++ sbagliato, così mi sto riferendo alla zona di memoria di indice 'a'+1 (gli indirizzi d8 memoria sono dei numeri anche loro, possono esswre incrementati anche loro).
   //! ATTENZIONE, anche scrivere '*a++;' é sbagliato!
   //L'operatore '++' ha più priorità rispetto a '*', vuol dire che noi stiamo prima incrementando a (che èun indirizzo di memoria),
   // e poi con '*' stiamo prendendo il valore della zona di memoria con indirizzo 'a++'.

  (*a)++; //questa è la sintassi cotretta per incrementare il valore di a, prima si prende il suo valore
  //diamo precedenza all'operatore '*' con le parentesi, poi incrementiamo  ('++') il valore;
  *a = *a/2;
  *a = *a * 7;
  //non metto un return perchè come detto prima se vado a modificare direttamente il valore di una variabile non glielo metto.
  //(commento post aver scritto la riga qua sopra) guyse, ci sono dei casi dove anche se una funzione va modificare direttamente il valore di una variabile si mette il return
  // ovviamente dipende dall'obbietivo della funzione, da cosa deve fare la funzione (più avanti nel codice provo a fare un esempio pratico.
}


int main3()
{
    int z=5;
    //miaFunzione(z) //!ATTENZIONE! questa chianata è errata! (infatti l'ho commentata)
    //la funzione 'miaFunzione' richiede come parametro un 'int*', che è un indirizzo per una zona di memoria.
    // con questa chiamata, non stiamo passando l'indirizzo di memoria della nostra variabile z, ma  stiamo passando il valore 5 come se fosse un indirizzo di memoria!!
    //(per questo c è un linguaggio pericoloso, perchè se io vado ad eseguire questo programma, tutte le operazioni che vado ad eseguire in "miaFunzione"  (in questo caso) andranno
    // eseguite su 'qualcosa' che principalmente potrebbe essere un qualsiasi file, con indirizzo di memoria '5'!

    //per chiamare correttamente la funzione 'miaFunzione' io gli devo passare l'INDIRZZO della mia variabile z.
    //e per passare l'indirizzo, basta aggiungere una 'e commerciale' (&) prima del nome della variabile nella chiamata:
    prtinf("\nvalore di z prima della funzione: %d\n", z);
    miaFunzione(&z); //?Chiamata Corretta!
    prtinf("\nvalore di z dopo la funzione: %d\n", z);
    //quindi in questo caso, facendo un printf di z, vedrò che è cambiato il suo valore!



}

int main() //qua chiamo tutti i vari main perchè, per comodità ho diviso il programma in più
           //parti (non avevo sbatti di fare 300 programmi diversi)
{
    main2();
    main3()
}