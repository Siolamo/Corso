#include <stdio.h>

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(x>8||y>8)
    {
        printf("la scacchiera non è così grande");
        return 0;
    }
    if((x+y)%2==0)  
    {
        printf("bianco");
    }
    else
    {
        printf("negro");
    }
    printf("\n");
}