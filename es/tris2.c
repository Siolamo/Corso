#include <stdio.h>

int main()
{
    int x1,x2,x3,y1,y2,y3;
    scanf("%d%d%d%d%d%d", &x1,&y1,&x2,&y2,&x3,&y3);
    int yl = y1+y2+y3;
    int xl = x1+x2+x3;
    // Due segmenti (x1,y1)-(x2,y2) e (x1,y1)-(x3,y3) hanno la stessa pendenza
    // se (y2 - y1)*(x3 - x1) == (y3 - y1)*(x2 - x1)
    if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1))
        printf("good");
    else
        printf("not so good");

//stampo la tabella der tris cuz così capisco shit
    for(int y=3;y>=1;y+=aggiunta)
    {
        for(int x=1;x<=3;x++)
        {
            printf("this is: x%d,y%d",x,y);
        }
        printf("\n");
    }

}