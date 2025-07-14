// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 4

// Menu itmes have item name and price
typedef struct
{
    string item;
    float price;
}
menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(string item);

int main(void)
{
    // Gets menu (assigns values of menu_item)
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    // Prints menu
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");

    // Running cost initialized variable
    float total = 0;
    while (true)
    {
        // Gets input
        string item = get_string("Enter a food item: ");
        // Breaks loop when input is empty
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }

        // Running cost using call function
        total += get_cost(item);
    }

    // Prints total to 2 decimal points
    printf("Your total cost is: $%.2f\n", total);
}

// Add at least the first four items to the menu array
void add_items(void)
{
    menu[0].item = "Burger";
    menu[0].price = 9.5;

    menu[1].item = "Vegan Burger";
    menu[1].price = 11.0;

    menu[2].item = "Hot Dog";
    menu[2].price = 5.0;

    menu[3].item = "Cheese Dog";
    menu[3].price = 7.0;
}

// Search through the menu array to find an item's cost
float get_cost(string item)
{
    // Linear search through menu items
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        // If input same as menu item's name
        if (strcasecmp(item, menu[i].item) == 0)
        {
            // Return price of that item
            return menu[i].price;
        }
    }
    // Error
    return 12345678910.0;
}
