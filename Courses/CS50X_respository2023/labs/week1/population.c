#include <cs50.h>
#include <stdio.h>

int getStartSize();
int getEndSize(int startSize);
int calculateYears(int startSize, int endSize);

int main(void)
{
    // Prompt for start and end size
    int startSize = getStartSize();
    int endSize = getEndSize(startSize);

    // Calculate number of years until threshold
    int years = calculateYears(startSize, endSize);

    // Print number of years
    printf("Years: %i\n", years);
}

int getStartSize()
{
    int startSize;
    do
    {
        startSize = get_int("Please enter a start size, greater than or equal to 9: ");
    }
    while (startSize < 9);
    // Start size cannot be less than 9

    return startSize;
}

int getEndSize(int startSize)
{
    int endSize;
    do
    {
        endSize = get_int("Please enter an end size, which is greater than the start size: ");
    }
    while (endSize < startSize);
    // End size cannot be less than start size

    return endSize;
}

int calculateYears(int startSize, int endSize)
{
    // Initializes years, to be recorded
    int years = 0;
    // Calculates loss and growth
    int gained;
    int lost;
    // Caclulates new population, while recording number of years
    while (startSize < endSize)
    {
        gained = startSize / 3;
        lost = startSize / 4;
        startSize = startSize + gained;
        startSize = startSize - lost;
        years++;
    }


    return years;
}