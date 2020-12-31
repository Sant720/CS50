#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name, dear?\n");
    printf("Hello, %s\n, how are you?", name);
}