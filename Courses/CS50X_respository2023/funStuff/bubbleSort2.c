#include <cs50.h>
#include <stdio.h>

// Consider using a library rather than implementing myself

int main(void)
{
    // Get array size
    int size;
    do
    {
    size = get_int("Size: ");
    }
    while (size < 2);

    int array[size];

    // Get array values
    for (int i = 0; i < size; i++)
    {
        array[i] = get_int("Number: ");
    }

    int placeHolder = 0;
    int placeHolder2 = 0;

    // Repeat for every item in array
    for (int i = 0; i < size; i++)
    {
        // Loop through pairs in array
        for (int n = 0; n < size; n++)
        {
            // If an earlier item is less than the next
            if (array[n] > array[n+1])
            {
                placeHolder = array[n];

                // Swap
                array[n] = array[n+1];
                array[n+1] = placeHolder;
            }
        }
    }

    // Print each item
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    // Print a new line
    printf("\n");

    // For better effeciency, add 'if no swaps quit'
}