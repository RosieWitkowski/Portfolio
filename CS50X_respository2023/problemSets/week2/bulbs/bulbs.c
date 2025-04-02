#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

// Prototypes
void numberToBinary(int number);
void print_bulb(int bit);

int main(void)
{
    // Get size
    string text = get_string("Text: ");

    // Loop through each letter/symbol in text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // For each letter, convert to number
        int number = (int) text[i];
        // For each number, conver to binary and print
        numberToBinary(number);
        // Print new line after every letter
        printf("\n");
    }
}

void numberToBinary(int number)
{
    // Assign a position for the bit and its maximum possible value
    int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int value[] = {128, 64, 32, 16, 8, 4, 2, 1};

    // Greedy algorithm
    for (int i = 0; i < 8; i++)
    {
        if (number >= value[i])
        {
            number -= value[i];
            binary[i] = 1;
        }
        else
        {
            binary[i] = 0;
        }
        print_bulb(binary[i]);
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
