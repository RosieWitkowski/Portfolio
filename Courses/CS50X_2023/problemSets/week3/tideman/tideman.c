#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_Cycle(int i);
bool check_Cycle2(int n);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        // If name is valid
        if (strcmp(name, candidates[i]) == 0)
        {
            // ranks[ith preference] = candidate
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Recall that rank = 0 > rank = 1, etc.
    // When candidate[i] rank > candidate[x] rank
    for (int candidate_A = 0; candidate_A < candidate_count; candidate_A++)
    {
        for (int candidate_B = candidate_count - 1; candidate_B > -1; candidate_B--)
        {
            // Do not add a preference if rank of candidates is equal (because this is not possible)
            if (candidate_A != candidate_B && candidate_A < candidate_B)
            {
                preferences[ranks[candidate_A]][ranks[candidate_B]] += 1;
            }
        }
    }

    // When candidate[i] rank < candidate[x] rank
    for (int candidate_A = candidate_count - 1; candidate_A > -1; candidate_A--)
    {
        for (int candidate_B = 0; candidate_B < candidate_count; candidate_B++)
        {
            if (candidate_A != candidate_B && candidate_A > candidate_B)
            {
                preferences[ranks[candidate_A]][ranks[candidate_B]] += 0;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int index = 0;
    pair_count = 0;
    int value = 0;

    // Loop through candidates_A
    for (int i = 0; i < candidate_count; i++)
    {
        // Loop through candidates_B
        for (int n = 0; n < candidate_count; n++)
        {
            // When i is preffered, and number of wins is not divisible by 2 (tie)
            if (preferences[i][n] > 0 && (preferences[i][n] % 2 != 0))
            {
                value = preferences[i][n];
                // Until all votes are added
                do
                {
                    pairs[index].winner = i;
                    pairs[index].loser = n;

                    pair_count++;
                    index++;
                    value--;
                }
                while (value > 0);
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    // IDEA EIGHT (after removing changes to global variable value of preferences[i][n])
    int holder = 0;
    int holder2 = 0;
    int holder3 = 0;
    int holder4 = 0;

    // For all items in array
    for (int i = 0; i < pair_count; i++)
    {
        // For each individual item
        for (int n = 0; n < pair_count - 1; n++)
        {
            // For each individual item
            for (int x = 0; x < pair_count - 1; x++)
            {
                // Compare to next (pairs[0], pairs[1], ...), if next is greater than: swap
                if (preferences[pairs[n].winner][pairs[x].loser] < preferences[pairs[n + 1].winner][pairs[x + 1].loser])
                {
                    // Value
                    holder = preferences[pairs[n].winner][pairs[x].loser];
                    // Swap value
                    preferences[pairs[n].winner][pairs[x].loser] = preferences[pairs[n + 1].winner][pairs[x + 1].loser];
                    preferences[pairs[n + 1].winner][pairs[x + 1].loser] = holder;

                    // Winner & loser
                    holder2 = pairs[x].winner;
                    holder3 = pairs[x].loser;
                    // Winner & loser to swap
                    holder4 = pairs[x + 1].winner;

                    // Swap winner & loser
                    pairs[x].winner = holder4;
                    pairs[x].loser = pairs[x + 1].loser;
                    pairs[x + 1].winner = holder2;
                    pairs[x + 1].loser = holder3;
                }
            }
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        // If adding an edge will NOT form a cycle
        if (check_Cycle(i) == false)
        {
            // Lock edge from W to L = true
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
        // If adding an edge WILL form a cycle
        else
        {
            // No edge
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
}

bool check_Cycle(int i)
{
    // Base case 1
    if (i == -1)
    {
        // All combinations true, therefore cycle is true
        return true;
    }

    // Base case 2
    else if (pairs[i].winner != pairs[0].loser && pairs[i].loser != pairs[0].winner)
    {
        // Cycle is false
        return false;
    }

    // Recursive case 1
    else
    {
        // Looks at all previous pairs and current next pair, to look for a possible loop back to i (a cycle)
        return check_Cycle(i--);
    }
}

bool check_Cycle2(int n)
{
    /*
    // Test
    locked[pairs[n].winner][pairs[n].loser] = true;

    // Look at all possible win/loss
    for (int i = 0; i < pair_count; i++)
    {

        // Look only at those that are locked
        if (locked[pairs[i].winner][pairs[i].loser] == true)
        {
            // Test for cycle
            if (pairs[i].loser != pairs[i + 1].winner)
            {
                return  false;
            }
        }

    }

    return true;
    */
    locked[pairs[n].winner][pairs[n].loser] = true;

    for (int x = 0; x < n; x++)
    {
        if (locked[pairs[x].winner][pairs[x].loser] == true)
        {
            if (pairs[x].winner == pairs[0].loser)
            {
                return true;
            }
        }
    }

    return false;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (locked[pairs[i].winner][pairs[i].loser] == true)
        {
            // Print winnter
            printf("%s\n", candidates[i]);
            return;
        }
    }
}