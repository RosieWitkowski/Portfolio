#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
int countLetters(string text);
int countWords(string text);
int countSentences(string text);
int calculate(int letters, int words, int sentences);

int main(void)
{
    /*
    index = 0.0588 * L - 0.296 * S - 15.8
    L = average number of letters per 100 words
    S = average number of sentences per 100 words
    */

    /*
    space or comma = new word
    . ! ? = new sentence
    */

    /*
    if more than 16: Grade 16+
    if less than 1: Before Grade 1
    */

    // Get text
    string text = get_string("Text: ");

    // Count letters
    int letters = countLetters(text);

    // Count words
    int words = countWords(text);

    // Count sentences
    int sentences = countSentences(text);

    // Calculate
    int grade = calculate(letters, words, sentences);

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int countLetters(string text)
{
    int sum = 0;
    // Loop through each letter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Do not tolerate numbers or symbols
        if (isalpha(text[i]))
        {
            sum += 1;
        }
    }
    return sum;
}

int countWords(string text)
{
    int sum = 1;
    // Loop through each letter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Tests if new word
        if (text[i] == ' ')
        {
            sum += 1;
        }
    }
    return sum;
}

int countSentences(string text)
{
    int sum = 0;
    // Loop through each letter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Tests if new sentence
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sum += 1;
        }
    }
    return sum;
}

int calculate(int letters, int words, int sentences)
{
    // Calculate, using type-casting double to maintain precision
    double averageLetters = ((letters / (double) words) * 100);
    double averageSentences = ((sentences / (double) words) * 100);
    double answer = (0.0588 * averageLetters) - (0.296 * averageSentences) - 15.8;

    // Round to nearest whole number
    answer = round(answer);

    // Return rounded answer
    return answer;
}