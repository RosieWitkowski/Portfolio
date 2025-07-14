#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Caesar cipher (rotating) encryption
int main(int argc, string argv[])
{
    // Get word and key
    int key = (int) argv[1];
    string word = get_string("plaintext: ");

    // Invalid input handling
    if (isalnum(key) != true || argc != 1)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
    // Loop through every character in word
    printf("ciphertext: \n");
    for (int i = 0, n = strlen(word); i < n; i ++)
    {
        // Ignores non-alphabetical characters
        if (isalpha(word[i]))
        {
        // Use type-casting to find numeric ASCII value
        int letterNumber = (int) word[i];

        // Change by key
        letterNumber += (int)key;

        // Print
        printf("%c ", letterNumber);
        }
    }
    printf("\n");
    }
}