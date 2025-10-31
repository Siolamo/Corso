#include <stdio.h>

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    if(x>8||y>8)
    {
        printf("tua madre troia la scacchiera è 8x8 ritardato di merda <3");
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