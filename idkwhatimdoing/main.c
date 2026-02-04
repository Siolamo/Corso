#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long t_scanf(const char *fmt, ...);

void rev_int(int *a)
{
    *a = (*a&0x000000FF) <<24 |
         (*a&0X0000FF00) << 8 |
         (*a&0X00FF0000) >> 8 |
         (*a&0XFF000000) >> 24;
}
void* my_malloc(size_t size);

void my_free(void* ptr);



typedef struct {
    char b[2]; //char[4] = 4 byte
    int a; //int  = 4 byte !=3
}mystruct; //4+2=6;

mystruct n;



// **** ! **** 

double my_sqrt(double x);
unsigned int my_rand(void);
void my_srand(unsigned int seed);
int main()
{
    
    printf("%d\n", sizeof(n.a) + sizeof(n.b));
    int x=16;
    printf("%.2f\n", my_sqrt(x));
    my_srand(time(NULL));
    printf("%d\n",sizeof(mystruct));
     for (int i = 0; i < 10; i++)
        printf("%u\n", my_rand());
 
    //     t_scanf("%d", &a );
    //     while(1)
    //     {
    //     char s[5];
    //     char c;
    //     //gets(s);

    /*
    int *a=malloc(2*sizeof(int));
    a[0] = 1;
    a[1] = 4;
    printf("%d %d\n", a[0],a[1]);
    int i=0;
    int b = sizeof(int);
    size_t c = sizeof(int);
    */
    //     printf("%d\n", a & 0x000000FF);
        
    //     b = b +1;
    //     printf("b=%d\n", *b);
    //     }
    // }}


}

