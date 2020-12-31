#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool digitsOnly(string str);

int main(void)
{
    string s = get_string("Number: ");
    int x = digitsOnly(s);

    (x == 0) ? printf("Not a number\n") : printf("That's a number\n");

}

bool digitsOnly(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }

    return true;
}
