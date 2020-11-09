#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

float cash;

int main(void)
{
    
    // Get positive float from user.
    do
    {
        cash = get_float("Change owed: ");
    }
    while (cash < 0);
    
    // Translate cash into cents.
    int cents = round(cash * 100);
    
    // Use C to count total coins.
    int C = 0;

    // Determine if quarters apply.
    if (cents / 25 >= 1)
    {
        // printf("Quarters available.\n");
        do
        {
            C++;
            cents -= 25;
        }
        while (cents / 25 >= 1);
        // printf("Cents left after quarters: %i\n", cents);
    }
    
    // Determine if dimes apply.
    if (cents / 10 >= 1)
    {
        // printf("Dimes available\n");
        do
        {
            C++;
            cents -= 10;
        }
        while (cents / 10 >= 1);
        // printf("Cents left after dimes: %i\n", cents);
    }
    
    // Determine if nickels apply.
    if (cents / 5 >= 1)
    {
        // printf("Nickels available.\n");
        do
        {
            C++;
            cents -= 5;
        }
        while (cents / 5 >= 1);
        // printf("Cents left after nickels: %i\n", cents);
    }

    // Determine if pennies apply.
    if (cents > 0)
    {
        // printf("Pennies available.\n");
        do
        {
            C++;
            cents--;
        }
        while (cents > 0);
    }

    // printf("Coins to give: %i\n", C);
    printf("%i\n", C);

}