#include <stdio.h>
#include <cs50.h>
#include <unistd.h>

int main(void) {
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int y = n - 1; y > i; y--)
        {
            printf(" ");
            //sleep(1);
        }
        
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }
            printf("  ");
            for (int j = 0; j <= i; j++)
            {
                printf("#");
            }
            printf("\n");
    }
}
