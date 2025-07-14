// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

// Define struct called 'avg_temp'
typedef struct
{
    string city;
    int temp;
} avg_temp;

// Global variable
avg_temp temps[NUM_CITIES];

// Prototype
void sort_cities(void);

int main(void)
{
    // Initialization
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    // Function call (sort)
    sort_cities();

    // Print every city name and temperature
    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
// Optional sorting method used: bubble sort
void sort_cities(void)
{
    int placeHolder = 0; // Placeholder for temperature
    string placeHolder2 = "Error"; // Placeholder for city's name

    // Repeat for every item in array
    for (int i = 0; i < NUM_CITIES; i++)
    {
        // Loop through pairs in array
        for (int n = 0; n < NUM_CITIES; n++)
        {
            // If an earlier item is more than the next
            if (temps[n].temp < temps[n + 1].temp)
            {
                placeHolder = temps[n].temp;
                placeHolder2 = temps[n].city;

                // Swap (temperature)
                temps[n].temp = temps[n + 1].temp;
                temps[n + 1].temp = placeHolder;

                // Swap (name)
                temps[n].city = temps[n + 1].city;
                temps[n + 1].city = placeHolder2;
            }
        }
    }
}
