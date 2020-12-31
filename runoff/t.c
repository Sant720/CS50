#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    int candidate_count = get_int("Count: ");
    int mayority = (candidate_count / 2) + 1;

    // if (candidate_count != 2 && candidate_count % 2 == 0)
    //     mayority = (candidate_count / 2);
    // else
    //     mayority = (candidate_count / 2) + 1;

    printf("Mayority: %i\n", mayority);
}