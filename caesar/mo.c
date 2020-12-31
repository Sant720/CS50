#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>

int main(void)
{
    int k = get_int("Key: ");
    int mo = k % 26;
    printf("%i\n", mo);
}