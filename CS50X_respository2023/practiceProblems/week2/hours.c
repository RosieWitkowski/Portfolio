#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Prototype
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // Total weeks
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // Hours per week
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // Option selector with error handling and toupper function
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // Answer to one decimal place
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float answer = 0;
    // Total
    if (output == 'T')
    {
        for (int i = 0; i < weeks; i++)
        {
            answer += hours[i];
        }
    }
    // Average
    else
    {
        for (int i = 0; i < weeks; i++)
        {
            answer += hours[i];
        }
        answer = answer / weeks;
    }
    return answer;
}