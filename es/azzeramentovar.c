#include<stdio.h>

int azzera(int* punutatore)
{
    *punutatore = 0;
}

int main()
{
    
    int x=4;
    
    
    printf("%d\n",x);
    azzera(&x);
    printf("%d\n",x);
    

}