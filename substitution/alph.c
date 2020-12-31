#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    string input = get_string("Input in CAPS: ");

    // Initialize alphabet array (upper and lower case).
    char alphabet[26];
    int arrayLenght = 26;
    int upperCase = 'A';
    int order = 1;

    for (int alph = 0; alph < arrayLenght; alph++, order++, upperCase++)
    {
        alphabet[alph] = upperCase;
        // printf("%i: %c\n", order, upperCase);
    }

    for (int i = 0, int a = 0; i < arrayLenght; i++)
    {
        do
        {
            if (input[i] == alphabet[a])
            {
                printf("Input contains letter %c.\n", alphabet[a]);
            }
            a++;
        }
        while (input[i] != alphabet[a]);

        if (input[i] == alphabet[a])
        {

        }


    }


    // for (int j = 0; j < keyLenght; j++)
    // {
    //     if (str2[j] = )
    // }
}