#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 0;
    
    int *n = malloc(4);
    while (x < 3)
    {
        *n = x;
        printf("%d\n", *n);
        x++;
    }
    
    free(n);
    return 0;
}