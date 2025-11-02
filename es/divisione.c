#include<stdio.h>

void divisione(int a, int b, int* quoziente, int* resto)
{
    if(b!=0)
    {
        *quoziente=a/b;
        *resto= a%b;
    }
    else
    {
        printf("fat dar in tal cul");
    }
}

int main()
{
    int quoz;
    int rest;
    int a,b;
    printf("inserisci 2 numeri:\n");
    scanf("%d%d",&a,&b);
    divisione(a,b,&quoz,&rest);
    printf("%d,%d\n", quoz,rest);
}