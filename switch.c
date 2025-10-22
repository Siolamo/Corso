#include <stdio.h>

int main()
{
    /*
    Cos'è uno switch?

    uno switch è un metodo che si usa quando si deve verificare più volte il valore di una variabile,
    per esempio: in una calcolatrice a 2 numeri nel momento in cui stiamo scegliendo il segno dovremmo fare 4 condizioni.
    una per il +
    una per -
    una per il *
    e una per il /
    */
conCondizione:
    {
        int a,b;
        char operatore;
        printf("inserisci a\n");
        scanf("%d",&a);
        printf("\nInserisci l'operatore\n");
        scanf(" %c", &operatore);
        printf("\nInserisci b\n");
        scanf("%d",&b);

        if(operatore=='+')
        {
            printf("%d",a+b);
        }
        else if(operatore=='-')
        {
            printf("%d", a-b);
        }
        else if(operatore=='*')
        {
            printf("%d", a*b);
        }
        else if(operatore=='/')
        {
            if(b != 0)//condizione sotto la condizione dell / per verificare che il divisore non sia 0
            {
                printf("%d", a/b);  
            }
            else
            {
                printf("Errore: divisione per zero");
            }
        }
        else
        {
            printf("Operatore non valido");
        }
        printf("\n")
    }
    /*
    Viene fuori un programma molto lungo e notiamo che la lungezza è dovuta principalmente dal fatto che 
    ci sono tante condizioni per verificare il valore di 'operatore'.
    tutto questo si puo fare molto più rapidamente utilizzando uno switch:
    */

conSwitch:
    {
        int c,d;
        char operatore2;
        printf("inserisci c\n");
        scanf("%d",&c);
        printf("\nInserisci l'operatore\n");
        scanf(" %c", &operatore2);
        printf("\nInserisci d\n");
        scanf("%d",&d);

        switch(operatore2)  //gli si passa come parametro la variabile con cui si vuole andare a lavorare
        {
            case '+':  // case, fa esattamente quello che dice, nel caso(case) che 'operatore2' sia '+' esegue tutto quello dopo i ':'
                printf("%d", c + d);
                break; //break, neccessario, in quanto lo switch ha un caso 'default' che esegue comunque anche se si soddisfa uno dei 'case'
                       // viene visto dal programma come, punto di interuzione, quando arriva al break, interrompe lo switch e continua con il resto del programma
            case '-':
                printf("%d", c - d);
                break;
            case '*':
                printf("%d", c * d);
                break;
            case '/':
                if(d != 0)      //condizione sotto il case dell / per verificare che il divisore non sia 0
                {
                    printf("%d", c / d);
                }
                else
                {
                    printf("Errore: divisione per zero");
                }
                break;
            default: //caso di default, un caso che lo switch esegue sempre (se non si sono messi gli appositi 'break' nei 'case' precedenti)
                    //usato quando la variabile passata allo switch(in questo caso operatore2) non soddisfa nessuno dei precedenti 'case'
                printf("Operatore non valido");
                break;
        }

        pritnf("\n")
    }

}