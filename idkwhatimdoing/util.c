#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int n_played;
    int *res;
    int final_score;
}Team;


void* my_malloc(size_t t);
void my_free(void* t);

int main()
{
    int n_squadre;
    scanf("%d",&n_squadre);
    Team *teams = my_malloc(n_squadre * sizeof(Team));
    
    

}