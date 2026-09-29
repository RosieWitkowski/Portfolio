#include <cs50.h>
#include <stdio.h>

int getHeight(void);
void printShape(int height);

int main(void)
{
    // Get height
    int height = getHeight();

    // Print shape
    printShape(height);
}

int getHeight(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

void printShape(int height)
{
    // Initialize number of loops for spaces for right sided triangle
    int spaceLoop = height;
    // Initialize number of loops for gaps, in right sided trianglestyle50 mario.c
    int rowLoop = 1;

    // Loops for columns, of height inputted
    for (int i = 0; i < height; i++)
    {

        // RIGHT SIDE

        // To forms a right-sided triangle, loops in descending amounts of gaps
        for (int gap = 1; gap < spaceLoop; gap++)
        {
            printf(" ");
        }
        // Decrease amount of loops for gap, for next row
        spaceLoop--;

        // Loops through number of hashtags in a row, increasing each time (for both right and left)
        for (int row = 0; row < rowLoop; row++)
        {
            printf("#");
        }

        // GAP BETWEEN TRIANGLES

        printf("  ");

        // LEFT SIDE

        // Loops through number of hashtags in a row, increasing each time (for both right and left)
        // Does not require a gap first, like right side
        for (int row = 0; row < rowLoop; row++)
        {
            printf("#");
        }

        // Number of loops of hashtags per row, for both left and ride, increased per each column
        rowLoop++;

        // END OF COLUMN

        // Starts new line, then loop starts again for next column
        printf("\n");
    }
}