#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

bool checkDigit(string str);
string getCipher(string str2, int key);
int key, validInput;
string plain;
string cipher;

int main(int argc, string argv[])
{
    // Assign value to validInput only if user provides to arguments.
    if (argc == 2)
    {
        validInput = checkDigit(argv[1]);
    }

    // Run code only if user provided a valid input.
    if (validInput != 0)
    {
        // Asign input to key.
        key = atoi(argv[1]);

        // Get plain text, translate, and print cipher.
        plain = get_string("plaintext:  ");
        getCipher(plain, key);
        printf("ciphertext: %s\n", cipher);
        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Check if arg[1] is a valid input (numerical).
bool checkDigit(string str1)
{
    for (int i = 0, len1 = strlen(str1); i < len1; i++)
    {
        if (str1[i] < '0' || str1[i] > '9')
        {
            return false;
        }
    }

    return true;
}

// Translate plain to cipher. Takes plain and key as input.
string getCipher(string str2, int k)
{
    for (int j = 0, len2 = strlen(str2); j < len2; j++)
    {
        // Calculate remainder of key to prevent multiple overflow.
        int mo = k % 26;

        // Calculate output.
        if (str2[j] >= 'a' && str2[j] <= 'z')
        {
            // Loop around alphabet if mo still overflows.
            // mo is always greater than 0. Subtract 1 to compensate.
            if (str2[j] + mo > 122)
            {
                int sub = 122 - str2[j];
                mo = mo - sub;
                str2[j] = (97 - 1) + mo;
            }

            else
            {
                str2[j] = str2[j] + mo;
            }
        }

        // Repeat for caps.
        if (str2[j] >= 'A' && str2[j] <= 'Z')
        {
            if (str2[j] + mo > 90)
            {
                int sub = 90 - str2[j];
                mo = mo - sub;
                str2[j] = (65 - 1) + mo;
            }

            else
            {
                str2[j] = str2[j] + mo;
            }
        }
    }

    // Assign translated string to cipher and return.
    cipher = str2;
    return cipher;
}