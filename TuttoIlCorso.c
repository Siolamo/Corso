#include <stdio.h>


/*
boh sigle utili da sapere:
CPU: Central Processing Unit
GPU: Graphic Processing Unit
SSD: Solid-State Drive
GCC: GNU C Compiler
GDB: GNU DeBugger
CSV: Comma Seprated Values
JS: JavaScript
!!Java e Javascript sono 2 cose molto diverse tra loro!!
JSON: JavaScript Object Notation
C: C
PC : Personal Computer
GNU: GNU (is) Not Unix
BIOS: Basic Input Output System

!!Queste qua giù di abbrevviazioni potete saltarle
!!Potete andare alla parte di Teoria
PAT: Port Adress Translation
NAT: Network Adress Translation
DHCP : Dynamic Host Configuration Protocol
DNS : Domain Name System
OS: Operative System
WSL: Windows Subsystem (for) Linux
APT: Advanced Packeg tool
PAC-MAN: PACket-MANager
UFW: Uncomplicated FireWall
SIM: Subscriber Idenity Module
HTML: HyperText Markup Language
CSS: Cascading Style Shit
HTTP: HyperText Transfer Protocol
HTTPS: same // la s sta per safe


!!Teoria
Un po' di teoria prima che vi esco il C:

Quella macchina di merda conosciuta come computer 
ha una struttura fisica che si chiama: struttura di von-neumann
ed è letteralmente la struttura del computer.
Un computer che dio comandi è composto da:

una scheda madre: dove vanno inseriti tutti i componenti.

una CPU: il processore,il cervello del computer

una RAM: Una memoria volatile, funge come una spece di "Memoria" del processore, vanno in RAM tutti i dati, file neccessari
a un programma per funzionare.
Memoria volatilè perchè "allo spegnimento del computer, si svuota, la RAM neccessità di corrente per poter
salvare dati";
In RAM ci vanno anche i file "temporanei", per esempio: 
Quando noi con un editor di testo stiamo modificando un file, prima di salvare quel file, viene allocato nella RAM,
quindi se abbiamo un file non salvato e spegniamo la macchina (mentre il file è in RAM), perderemo il file Per Sempre.
Quando salviamo, il file verrà salvato nel disco fisso (memoria di massa);

Memoria di massa: La memoria di massa, comunemente chiamata disco fisso, è il posto dove tutti i file PERMANENTI
quindi (file salvati, file di sistema)
*/



int main()
{

    // <- cosi si fa un commento su una liena solo.

    /* <- cosi
    si
    fanno
    commenit
    su più
    righe
    
    
    fine del commento su più righe-> */ 

    //sup guyse
    //here u go: how to C
    int x = 1; //una variabile intera chiamata x a cui asseggno il valore di 1


    printf("ciao\n");
    //stasmpa a schermo una stringa
    printf("ciao %d\n",x); 
    //in questa string che stampo a schermo volendo posso "concatenare" anche degli altri valori (numerici,booleani, altre stringhe, ecc..
    /*
     %[letttera] sta indicare che in quella posizione della stringa ci andrà poi ad essere una variabile che passiamo al printf come un altro paramatro (quindi dopo la virgola).

     in C tutte le funziuoni prendono parametri diversi, ogni parametro va separato con una virgola: miaFunzione(parametro1,parametro2);
     per esempio nella printf sarà: printf("ho bevuto %d bottigle", bottigleBevte); dove "ho bevuto %d bottigle" è il primo parametro che si passa alla funzione, e bottigleBevute è il secondo parametro che gli passo.

     lista indicatori:
     %d : per interi;
     %f : per float (numeri con la virgola)
     %c : per i caratteri (a,b,c,d,e,ecc...) ATTENZIONE: tutti i caratteri per essere effettivamente caratteri devono sempre essere dentro degli apici ' '
     con i numeri sopratutto bisonga fare attenzione perchè se in un codice si scrive per esempio printf("%d",1) (corretto) è diverso da scrivere printf("%d",'1') (sbagliato perchè in questo caso 1 
                                                                                                                                                                    sta venendo passato come carattare quindi servirebbe
                                                                                                                                                                    mettere il %c)

    */

    printf("%d\n",1);
    printf("%c\n",'1');

    /*
        Condizioni:
            Le condizioni servono per giestire il comportamento del programma, dando una condizione possiamo scegliere di eseguire solo determiante condizione.
            ad esempio: in un semplice programma che prevede un login con un pin, noi vogliamo che l'utente possa accedere solo se il pin è giusto.
            quindi, fingiamo che il pin sia '4567', la nostra condizione sarà if(pin=="4567") printf("accesso consentito");

    */

    int pin = "4567";
    if(pin=="4567")
    {
        printf("accesso consentito");
    }


}
