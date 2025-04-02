// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

// Prototype
int max(int array[], int n);

int main(void)
{
    // Get size of the array
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    // Get each item in the array
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    // Print using function call
    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    // Initialize variable to compare
    int max = array[n - 1];

    // Loop through array (doesn't need to compare last item, note < less than so == n-2)
    for (int i = 0; i < n - 1; i++)
    {
        // Compare to variable max
        if (array[i] > max)
        {
            // Change value inside max
            max = array[i];
        }
    }

    return max;
}
