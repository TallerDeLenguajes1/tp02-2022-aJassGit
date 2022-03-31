#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    #define N 5
    #define M 7
    int i,j;
    int mt[N][M];
    int *pointer;
    pointer = mt[0];
    for(i = 0;i<N; i++)
    {
        for(j = 0;j<M; j++)
        {
            *(pointer + (i*M+j))=1+rand()%100;
            printf("%i ", mt[i][j]);
        }
    printf("\n");
    }   

    return 0;
}
