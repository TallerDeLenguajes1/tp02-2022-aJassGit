#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    #define N 20

    int i;
    int vt[N];
    
    for(i = 0;i<N; i++)
    {
    *(vt+i)=1+rand()%100;
    printf("%i", vt[i]);
    }

    return 0;
}