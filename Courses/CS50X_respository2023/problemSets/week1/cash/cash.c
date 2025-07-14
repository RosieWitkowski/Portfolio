#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

// Greedy algorithm for finding the amount of coins to use as change
int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Loop until valid input
    int cents;
    do
    {
        cents = get_int("Cents: ");
    }
    while (cents < 0wget https://cdn.cs50.net/2022/fall/psets/1/mario-more.zip
);
    return cents;
}

int calculate_quarters(int cents)
{
    int coins = 0;
    while (cents > 24)
    {
        coins++;
        cents -= 25;
    }
    return coins;
}

int calculate_dimes(int cents)
{
    int coins = 0;
    while (cents > 9)
    {
        coins++;
        cents -= 10;
    }
    return coins;
}

int calculate_nickels(int cents)
{
    int coins = 0;
    while (cents > 4)
    {
        coins++;
        cents -= 5;
    }
    return coins;
}

int calculate_pennies(int cents)
{
    int coins = 0;
    while (cents > 0)
    {
        coins++;
        cents -= 1;
    }
    return coins;
}