/*
1. Prompt for height (1 to 8, inclusive), using do{}while()
2. Print blocks
    a. Prints a hashtag * (1), then new line
    b. Prints hashtag * (1 + 1) then new line
    c. Prints hashtag (1 + 1 + 1) then new line
    c. Repeat until hashtag (n) where n = height
*/

printf("#\n");

printf("#");
printf("#\n");

printf("#");
printf("#");
printf("#\n");

printf("#");
printf("#");
printf("#");
printf("#\n");

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