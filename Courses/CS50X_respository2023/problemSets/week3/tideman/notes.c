// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    /*
    // IDEA ONE: sorting using my own strength variable array
    // Variable
    typedef struct
    {
        int amount;
        int winnerIndex;
        int loserIndex;
    } strength;

    // Initial value assigned to zero
    strength strengths[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        strengths[i].amount = 0;
    }

    // Find strength of each pair
    for (int i = 0; i < pair_count--; i++)
    {
        // If two pair array in pairs[] are the same
        if (pairs[i].winner == pairs[i+1].winner && pairs[i].loser == pairs[i+1].loser)
        {
            strengths[i].amount += 1;
            strengths[i].winnerIndex = pairs[i].winner;
            strengths[i].loserIndex = pairs[i].loser;
        }
    }

    // Sort strengths[] in order of strength
    int placeHolder = 0;
    int placeHolder2 = 0;

    for (int i = 0; i < pair_count; i++)
    {
        for (int n = 0; n < pair_count; n++)
        {
            if (strengths[n].amount > strengths[n + 1].amount)
            {
                placeHolder = strengths[n].amount;
                placeHolder2 = strengths[n + 1].amount;

                strengths[n].amount = placeHolder2;
                strengths[n + 1].amount = placeHolder;

                placeHolder = strengths[n].winnerIndex;
                placeHolder2 = strengths[n + 1].winnerIndex;

                strengths[n].winnerIndex = placeHolder2;
                strengths[n + 1].winnerIndex = placeHolder;

                placeHolder = strengths[n].loserIndex;
                placeHolder2 = strengths[n + 1].loserIndex;

                strengths[n].loserIndex = placeHolder2;
                strengths[n + 1].loserIndex = placeHolder;
            }
        }
    }

    // Sort pairs[] in order of strength
    for (int i = 0; i < pair_count; i++)
    {
        pairs[i].winner = strengths[i].winnerIndex;
        pairs[i].loser = strengths[i].loserIndex;
    }
    */

    /*
    // IDEA TWO: Moving based on similarity
    // If two consecutive are the same, more the right to the left
    // If the next is not it will skip
    int placeHolder = 0;
    int placeHolder2 = 0;
    for (int i = 0; i < pair_count; i++)
    {
        for (int n = 0; n < pair_count; n++)
        {
            if (pairs[n].winner == pairs[n+1].winner && pairs[n].loser == pairs[n+1].loser)
            {
                placeHolder = pairs[n].winner;
                placeHolder2 = pairs[n+1].winner;

                pairs[n].winner = placeHolder2;
                pairs[n+1].winner = placeHolder;

                placeHolder = pairs[n].loser;
                placeHolder2 = pairs[n+1].loser;

                pairs[n].loser = placeHolder2;
                pairs[n+1].loser = placeHolder;
            }
        }
    }
    */

    /*
    // IDEA THREE
    int placeHolder = 0;
    int placeHolder2 = 0;
    for (int i = 0; i < pair_count-2; i++)
    {
        if (pairs[i].winner == pairs[i+2].winner && pairs[i].loser == pairs[i+2].loser)
        {
            placeHolder = pairs[i+1].winner;
            placeHolder2 = pairs[i+1].loser;

            pairs[i+1].winner = pairs[i+2].winner;
            pairs[i+1].loser = pairs[i+2].loser;

            pairs[i+2].winner = placeHolder;
            pairs[i+2].loser = placeHolder2;
        }
    }
    */

    /*
    // IDEA FOUR
    int strengths[candidate_count];
    int strengthsLoss[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        strengths[i] = 0;
        strengthsLoss[i] = 0;
    }

    for (int i = 0; i < pair_count--; i++)
    {
        if (pairs[i].winner == pairs[i+1].winner && pairs[i].loser == pairs[i+1].loser)
        {
            // For each candidate i, #pairs[i] where i = winner += 1
            strengths[i] += 1;
            // For each candidate i, #pairs[i] where i = loser += 1
            strengthsLoss[i] +=1 ;
        }
    }

    int placeHolder = 0;
    int placeHolder2 = 0;
    for (int i = 0; i < pair_count--; i++)
    {
        if (strengths[i] > strengths[i+1])
        {
            placeHolder = pairs[i].winner;
            placeHolder2 = pairs[i].loser;

            pairs[i].winner = pairs[i+1].winner;
            pairs[i].loser = pairs[i+1].loser;

            pairs[i+1].winner = placeHolder;
            pairs[i+1].loser = placeHolder2;
        }
    }
    */

    // IDEA FIVE
    /*
    int placeHolder = 0;
    int placeHolder2 = 0;
    int placeHolder3 = 0;
    int placeHolder4 = 0;
    for (int i = 0; i < pair_count - 1; i++)
    {
        bool loop = true;
        while (loop == true)
        {
            if (pairs[i].winner != pairs[i + 1].winner || pairs[i].loser != pairs[i + 1].loser)
            {
                placeHolder = pairs[i].winner;
                placeHolder2 = pairs[i].loser;

                placeHolder3 = pairs[i + 1].winner;
                placeHolder4 = pairs[i + 1].loser;

                pairs[i + 1].winner = placeHolder;
                pairs[i + 1].loser = placeHolder2;

                pairs[i].winner = placeHolder3;
                pairs[i].loser = placeHolder4;

                loop = false;
            }
        }
    }
    */

    /*
    // IDEA 6
    // Sort in order of pairs
    int placeHolder = 0;
    int placeHolder2 = 0;
    for (int i = 0; i < pair_count; i++)
    {
        for (int n = 0; n < pair_count-1; n++)
        {
            if (pairs[i].winner == pairs[n].winner && pairs[i].loser == pairs[i].loser)
            {
                placeHolder = pairs[i + 1].winner;
                placeHolder2 = pairs[i + 1].loser;

                pairs[i + 1].winner = pairs[n].winner;
                pairs[i + 1].loser = pairs[n].loser;

                pairs[n].winner = placeHolder;
                pairs[n].loser = placeHolder2;
            }
        }
    }

    // Sort in order of frequency
    int num[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        num[i] = 0;
    }

    for (int i = 0; i < pair_count; i++)
    {
        for (int n = 0; n < pair_count; n++)
        {
            if (pairs[i].winner == pairs[n].winner && pairs[i].loser == pairs[n].loser)
            {
                num[i] += 1;
            }
        }
    }

    // Sort
    int place1 = 0;
    int place2 = 0;
    for (int i = 0; i < pair_count; i++)
    {
        for (int n = 0; n < pair_count--; n++)
        {
            if (num[n] > num[n+1])
            {
                place1 = pairs[n].winner;
                place2 = pairs[n].loser;

                pairs[n].winner = pairs[n+1].winner;
                pairs[n].loser = pairs[n+1].loser;

                pairs[n+1].winner = place1;
                pairs[n+1].loser = place2;
            }
        }
    }
    */
    /*
    // IDEA SEVEN

    // STEP ONE: FIND AMOUNT OF EACH
    int num[pair_count];
    for (int i = 0 ; i < pair_count; i++)
    {
        num[i] = 0;
    }

    // Look at every struct in the pairs[] array
    int index = 0;
    for (int i = 0; i < pair_count; i++)
    {
        // For each, loop through the pair to find equal
        for (int n = 0; n < pair_count-1; n++)
        {
            if (pairs[n].winner == pairs[n+1].winner && pairs[n].loser == pairs[n+1].loser)
            {
                num[index] +=1;
            }
            else
            {
                index +=1;
            }
        }
    }


    // STEP THREE: ORDER AMOUNT OF EACH
    int placeHolder = 0;
    int holder1 = 0;
    int holder2 = 0;

    while (index > 0)
    {
        if (num[index] > num[index-1])
        {
            holder1 = pairs[index].winner;
            holder2 = pairs[index].loser;

            pairs[index].winner = pairs[index+1].winner;
            pairs[index].loser = pairs[index+1].loser;
            pairs[index+1].winner = holder1;
            pairs[index+1].loser = holder2;

            placeHolder = num[index];
            num[index] = num[index+1];
            num[index+1] = placeHolder;
        }
        index--;
    }
    */




   // Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    bool cycle = true;

    // Loop through pairs index
    for (int i = 0; i < pair_count; i++)
    {
        // TEST FOR CYCLE

        // Test for if adding next edge will form a cycle
        /*for (int n = 0; n < pair_count-1; n++)
        {
            // Test
            if (pairs[n].loser == pairs[n+1].winner && locked[n][n + 1] == true)
            {
                cycle = true;
            }
        }
        // Loop back to start
        if (pairs[pair_count-1].loser == pairs[0].winner && locked[pair_count - 1][0] == true)
        {
            cycle = true;
        }

        // A cycle does NOT form if any pair[] has BOTH arrows FROM it
        // If there are both then the winner of two will be the same
        for (int n = 0; n <= i; n++)
        {
            if (pairs[n].winner == pairs[i].winner || pairs[n].loser == pairs[i].loser)
            {
                cycle = false;
            }
        }

        // If arrow pointing to x (x loss, i win) and i points to
        // If arrow points from i(W) to x(L) and x is a (W) to y

        if (locked[pairs[i].loser][pairs[0].winner] == true)
        {
            cycle = true;
        }


        // Cycle = false, if there is a source
        // From index = zero to index = i
        for (int n = 0; n <= i - 1; n++)
        {
            if (pairs[i].winner == pairs[n+1].winner)
            {
                cycle = true;
            }
        }

        // Find the next set of different candidate pair pairs[], for [i], [n] ([n][x])
        int index = 0;
        pair current;
        pair next;
        for (int n = 1; n < i + 1; n++)
        {
            for (int x = 1; x < i + 1; x++)
            {
                current = pairs[i];
                next = pairs[index + preferences[n - 1][x - 1]];

                if (current.winner == next.winner)
                {
                    cycle = false;
                }

                index++;
            }
        }


        if (i < pair_count)
        {
            if (pairs[i].winner == pairs[i + 1].winner)
            {
                cycle = false;
            }
        }
        else
        {
            // Loop back to start
            if (pairs[i].winner == pairs[0].winner)
            {
                cycle = false;
            }
        }

        int index = 0;
        pair current;
        pair next;
        for (int n = 1; n < i + 1; n++)
        {
            for (int x = 1; x < i + 1; x++)
            {
                current = pairs[i];
                next = pairs[index + preferences[pairs[i].winner][pairs[i].loser]];

                if (current.winner == next.winner)
                {
                    cycle = false;
                }

                index++;
            }
        }
        if (index < pair_count - 1)
        {
            if (pairs[index].loser == pairs[index + 1].winner)
            {
                cycle = true;
            }
        }
        else
        {
            // Loop back to start
            if (pairs[index].loser == pairs[0].winner)
            {
                cycle = true;
            }
        }

        // See if a cycle forms, if current pairs[i] is added
        int index = 0;
        if (i == 0)
        {
            index = 0;
        }
        else
        {
            for (int n = 0; n < i; n++)
            {
                index += preferences[pairs[n].winner][pairs[n].loser];
            }
            index -= i;
        }

        for (int n = 0; n < index; n++)
        {
            if
        }*/








// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    bool cycle = true;

    // Loop through pairs index
    for (int i = 0; i < pair_count; i++)
    {
        // TEST FOR CYCLE

        /*
        for (int x = 0; x < i; x++)
        {
            if (pairs[x].loser != pairs[x + 1].winner)
            {
                cycle = false;
            }
        }
        if (pairs[i].winner != pairs[0].loser)
        {
            cycle = false;
        }


        if (pairs[i].loser == pairs[0].winner)
        {
            cycle = true;
        }


        if (locked[pairs[i].winner][pairs[0].winner] == true || locked[pairs[i].loser][pairs[0].loser] == true)
        {
            cycle = true;
        }*/

        locked[pairs[i].winner][pairs[i].loser] = true;
        for (int n = 0; n < pair_count - 1; n++)
        {
            if (locked[pairs[n].winner][pairs[n].loser] == true)
            {
                if (pairs[n].loser != pairs[n + 1].winner)
                {
                    cycle = false;
                }
            }
            if (locked[pairs[pair_count - 1].winner][pairs[pair_count - 1].loser] == true && locked[pairs[0].winner][pairs[0].loser] == true)
            {
                if (pairs[pair_count-1].loser != pairs[0].winner)
                {
                    cycle = false;
                }
            }
        }



        // ADDING EDGES

        // If adding an edge will NOT form a cycle
        if (cycle == false)
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

        // Reset cycle test
        cycle = true;
    }
    return;
}