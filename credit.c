#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <math.h>

int main(void) 
{
    // Get card number
    long n = get_long("Number: ");

    //Count characters (c) and verify Card Type (T) validity
    int c;
    int T = 0;
    long N = n;

    for (c = 0; n > 0; c++)
    {
        n /= 10;

        if (n == 4 || n == 34 || n == 37 || (n >= 51 && n <= 55))
        {
            T = n;
        }
        // printf("\nNumber divided by 10: %ld\n", n);
        // printf("Counted characters: %i\n", c);
        // sleep(1);
    }

    // printf("Full number: %ld\n", N);
    // printf("Card Type: %i\n", T);
    // printf("Card Characters: %i\n", c);

    // Lunh's Algorithm (runs only if Cart Type is valid)

    int prod1 = 0;
    int break1 = 0;
    int sum1 = 0;
    int sum2 = 0;
    int total = 0;

    if ((T != 0) && (c == 13 || c == 15 || c == 16))
    {
        // printf("Card type is valid.\n");
        // printf("Run Lunh.\n");

        // Get digits and add them to final sum
        do
        {
            // Get ult digit and add it to sum1.
            sum1 = sum1 + (N % 10);
            // printf("Sum1 is: %i\n", sum1);

            // Remove digit.
            N /= 10;
            // printf("-N minus 1 character: %ld\n", N);

            // Get penult digit and multiply it by 2
            prod1 = 0;
            prod1 = prod1 + ((N % 10) * 2);
            // printf("Prod1 is : %i\n", prod1);

            // If penult digit is 10 or larger, break it down and add it to sum2
            if (prod1 >= 10)
            {
                // printf("Prod1 was 10 or more.\n");
                do
                {
                    break1 = 0;
                    break1 = break1 + (prod1 % 10);
                    prod1 /= 10;
                    sum2 = sum2 + break1;
                }
                while (prod1 > 0);
            }

            // Else, add it straight to sum2
            else
            {
                sum2 = sum2 + prod1;
                // printf("Sum2 is: %i\n", sum2);
            }

            N /= 10;
            // printf("-N minus 1 character: %ld\n", N);
            // printf("______Return to do.\n");
        }
        while (N > 0);

        //Define Sums and Total
        total = sum1 + sum2;
        // printf("Sum1: %i\n", sum1);
        // printf("Sum2: %i\n", sum2);
        // printf("Total: %i\n", total);

        if (total % 10 == 0)
        {
            if ((c == 13 || c == 16) && (T == 4))
            {
                printf("VISA\n");
            }

            else if ((c == 15) && (T == 34 || T == 37))
            {
                printf("AMEX\n");
            }

            else if ((c == 16) && (T >= 51 && T <= 55))
            {
                printf("MASTERCARD\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

}
