#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    string s = get_string("Number String: ");
    int x = atoi(s);
    printf("%i\n", x);
}