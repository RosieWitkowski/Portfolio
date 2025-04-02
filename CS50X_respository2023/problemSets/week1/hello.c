#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get name
    string name = get_string("What is your name? ");

    // Print name
    printf("Hello, %s!\n", name);
}