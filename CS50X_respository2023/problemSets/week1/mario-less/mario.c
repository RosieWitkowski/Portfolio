#include <cs50.h>
#include <stdio.h>

int getHeight();
void printBlocks(int height);

int main(void)
{
    // Prompt for height (1 to 8, inclusive)
    int height = getHeight();

    // Print blocks
    printBlocks(height);
}

int getHeight()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // Height must be between 1 and 8, inclusive

    return height;
}

// Final version:

void printBlocks(int height)
{
    // Initial number of row loops = 1
    int rowLoops = 1;
    // Initial number of dotLoops = height-1
    int spaceLoops = height;

    // Loops through column for number of height
    for (int column = 0; column < height; column++)
    {
        // Loops through row number of spaceLoops
        for (int dots = 1; dots < spaceLoops; dots++)
        {
            printf(" ");
        }
        spaceLoops--;

        // Loops through row for number of rowLoops
        for (int row = 0; row < rowLoops; row++)
        {
            printf("#");
        }
        rowLoops++;

        printf("\n");
    }
}

// VERSION 1: A left-aligned pyramind (easier):
/*
void printBlocks(int height)
{
    // Initial number of row loops = 1
    int loops = 1;

    // Loops through column for number of height
    for (int column = 0; column < height; column++)
    {

      // Loops through row, number of loops (row increases to exit loop, when column loops it increases number of loops)
      for (int row = 0; row < loops; row++)
      {
          printf("#");
      }

      loops++;
      printf("\n");
    }
}
*/


// VERSION 2: A right-aligned pyramind (harder, next step remove *):
/*
void printBlocks(int height)
{
    // Initial number of row loops = 1
    int rowLoops = 1;
    // Initial number of dotLoops = height-1
    int dotLoops = height;

    // Loops through column for number of height
    for (int column = 0; column < height; column++)
    {
        // Loops through row number of dotLoops
        for (int dots = 1; dots < dotLoops; dots++)
            {
                printf(".");
            }
            dotLoops--;

        // Loops through row for number of rowLoops
        for (int row = 0; row < rowLoops; row++)
        {
            printf("#");
        }
        rowLoops++;

      printf("\n");

    }

}
*/