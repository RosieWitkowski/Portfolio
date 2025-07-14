// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototype
string replace(string word);

int main(int argc, string argv[])
{
    // Take command-line argument
    string word = argv[1];

    // Error handling
    if (argc != 2)
    {
        printf("Enter a single input after execution: ./no-vowels word\n");
        return 1;
    }
    word = replace(word);
    printf("Word: %s\n", word);
}

string replace(string word)
{

    // Keys
    char changeVowels[] = {'a', 'e', 'i', 'o'};
    char changeVowels2[] = {'A', 'E', 'I', 'O'};
    char newVowels[] = {'6', '3', '1', '0'};

    // Loops through every letter
    for (int i = 0, l = strlen(word); i < l; i++)
    {
        // Checks against every item in array
        for (int n = 0; n < 4; n++)
        {
            if (word[i] == changeVowels[n] || word[i] == changeVowels2[n])
            {
                word[i] = newVowels[n];
            }
        }
    }
    return word;
}