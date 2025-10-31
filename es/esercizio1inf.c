#include <stdio.h>

float mcd(float a,float b)
{
    while(a!=b)
    {
        if(a<b)
        {
            b = b-a;
        }
        else
        {
            a = a-b;
        }
    }
    return a;
}

int main()
{
   
    
    int M;
    scanf("%d",&M);
    /*
    M righe
    riga composta da, M valori
    valore j-esimo della i-esima riga deve essere: n reale = 1/mcd(i,j)

    j * i
    */

    for(int j=0;j<M;M++)
    {
        for(int i=0;i<M;i++)
        {
            printf("%d",mcd(i,j));
        }
        printf("\n");
    }
    float a = 1;
    

}