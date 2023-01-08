#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i = 0;
    int j = 0;
    int tab[100] = {0};

    srand(time(NULL));
    for(i = 0; i < 100; i++)
    {
        tab[i] = 1 + rand()%100;
        for (j = 0; j < i; j++)
        {
            if (tab[j] == tab[i])
                i--;
        }
    }
    for(i = 0; i < 100; i++)
    {
        printf("%d ", tab[i]);
    }
   
}
