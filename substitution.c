#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

bool checkAlphabeticalString(string str0);
string makeCaps(string str1);
bool findDups(string str2);
string getCipher(string str3);
string cipher;
string capsKey;
int keyLenght;

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Assign keyLenght and determine if key is alphabetical.
        keyLenght = strlen(argv[1]);
        int alphabetical = checkAlphabeticalString(argv[1]);

        if (alphabetical == 1 && keyLenght != 26)
        {
            printf("Key must contain 26 alphabetical characters.\n");
            return 1;
        }

        if (alphabetical == 0 && keyLenght == 26)
        {
            printf("All characters must be alphabetical.\n");
            return 1;
        }

        if (alphabetical == 1 && keyLenght == 26)
        {
            // Make all characters caps and check for duplicates.
            string testKey = argv[1];
            makeCaps(testKey);
            capsKey = testKey;
            int validInput = findDups(testKey);

            if (validInput == 1)
            {
                // key = argv[1];
                printf("Input is valid.\n");
                string plain = get_string("plaintext:  ");
                getCipher(plain);
                printf("ciphertext: %s\n", cipher);
                return 0;
            }

            else
            {
                printf("Key must not contain duplicate characters.\n");
                return 1;
            }

        }

        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

// Function to check if  all characters are alphabetical.
bool checkAlphabeticalString(string str0)
{
    for (int i = 0; i < keyLenght; i++)
    {
        if ((str0[i] >= 'a' && str0[i] <= 'z') || (str0[i] >= 'A' && str0[i] <= 'Z'))
        {
            ;
        }
        else
        {
            return false;
        }
    }
    return true;
}

string makeCaps(string str1)
{
    for (int i = 0; i < keyLenght; i++)
    {
        if (str1[i] > 'Z')
        {
            // printf("Character %c capitalized.\n", str1[i]);
            str1[i] = str1[i] - 32;
        }
    }

    return str1;
}

bool findDups(string str2)
{
    for (int i = 0; i < keyLenght; i++)
    {
        for (int j = i + 1; j < keyLenght; j++)
        {
            if (str2[i] == str2[j])
            {
                return false;
            }
        }
    }
    return true;
}


string getCipher(string str3)
{
    int inputLenght = strlen(str3);
    for (int i = 0; i < inputLenght; i++)
    {
        // printf("For loop started.\n");
        if (str3[i] >= 'a' && str3[i] <= 'z')
        {
            // printf("Character %i is lowercase.\n", i + 1);
            // Find character's place in alphabet.
            int place = str3[i] - 97;

            // Substitute for character in key and make lowercase.
            str3[i] = capsKey[place] + 32;
            // printf("Character %i is now %c.\n", i + 1, capsKey[place] + 32);
        }

        else if (str3[i] >= 'A' && str3[i] <= 'Z')
        {
            // printf("Character %i is uppercase.\n", i + 1);
            // Find character's place in alphabet.
            int place = str3[i] - 65;

            // Substitute for character in key and keep uppercase.
            str3[i] = capsKey[place];
            // printf("Character %i is now %c.\n", i + 1, capsKey[place]);
        }
    }

    cipher = str3;
    return cipher;
}