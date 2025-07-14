#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Converts text to binary

// Prototypes
void numberToBinary(int number);
bool isSpace(int position[]);

// Global variable, tests if first in new line
bool first = true;

int main(void)
{
    // Get input
    string word = get_string("Text: ");
    // Loop through every letter in every word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Convert to number
        int number = (int) word[i];
        // Convert number to binary
        numberToBinary(number);
    }
    printf("\n");
}

void numberToBinary(int number)
{
    // Assign a position for the bit and its maximum possible value
    int position[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int value[] = {128, 64, 32, 16, 8, 4, 2, 1};

    // Greedy algorithm
    for (int i = 0; i < 8; i++)
    {
        if (number >= value[i])
        {
            number -= value[i];
            position[i] = 1;
        }
        else
        {
            position[i] = 0;
        }
    }

    // Identify if 'space' in binary
    if (first == false)
    {
        if (isSpace(position) == true)
        {
            printf("\n(");
            for (int i = 0; i < 8; i++)
            {
                printf("%i", position[i]);
            }
            printf(")\n");
            first = true;
            // new line so don't want space before next word
        }
        else
        {
            printf(" ");

            // Print result, one bit at a time
            for (int i = 0; i < 8; i++)
            {
                printf("%i", position[i]);
            }
            first = false;
        }
    }
    else
    {
        // Print first word with no space
        for (int i = 0; i < 8; i++)
        {
            printf("%i", position[i]);
        }
        first = false;
    }
}

bool isSpace(int position[])
{
    // Space in binary
    int space[] = {0, 0, 1, 0, 0, 0, 0, 0};

    // Loops through every bit in word
    for (int i = 0; i < 8; i++)
    {
        // False if any bit is not equal to space bit
        if (position[i] != space[i])
        {
            return false;
        }
    }
    return true;
}