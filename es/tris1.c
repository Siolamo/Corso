#include <stdio.h>

int main()
{
    int x1,x2,x3,y1,y2,y3;
    scanf("%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3);
    int yl = y1+y2+y3;
    int xl = x1+x2+x3;
    if(yl%3==0||xl%3==0||(xl==6&&yl==6))
    {
        printf("NICE");
    }

//stampo la tabella der tris cuz così capisco shit
    for(int y=3;y>=1;y--)
    {
        for(int x=1;x<=3;x++)
        {
            printf("this is: x%d,y%d",x,y);
        }
        printf("\n");
    }

}