#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

string makeCaps(string str1);
bool findDups(string str2);
int stringLenght;

int main(void)
{
    string input = get_string("Input: ");
    string testInput = input;
    stringLenght = strlen(testInput);

    makeCaps(testInput);
    printf("String in caps: %s\n", testInput);

    int validInput = findDups(testInput);

    printf("Duplicate characters: %i\n", validInput);
}

string makeCaps(string str1)
{
    for (int i = 0; i < stringLenght; i++)
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
    for(int i = 0; i < stringLenght; i++)
    {
        for(int j = i + 1; j < stringLenght; j++)
        {
            if  (str2[i] == str2[j])
            {
                return false;
            }
        }
    }
    return true;
}