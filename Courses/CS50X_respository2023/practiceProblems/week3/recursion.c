// Program to convert string to int, like atoi
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    // Get input
    string input = get_string("Enter a positive integer: ");

    // Error handling for invalid input (not a number)
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Base case
    if (input[0] == '\0')
    {
        return 0;
    }

    // Index of last char, before null
    int i = strlen(input) - 1;
    // Convert to number
    int number = input[i] - '0';
    // Move null to left
    input[i] = '\0';

    return number + (10 * convert(input));
}
