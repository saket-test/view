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
bool has_cycle(int winner, int loser);
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

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
    // for (int i = 0; i < pair_count; i++)
    // {
    //     printf("Pair %i:\nWinner: %i\nLoser: %i\n",i,pairs[i].winner,pairs[i].loser
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         printf("locked[%i][%i]: %i\n",i,j,locked[i][j]);
    //     }
    // }
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO -- rank = j, name = candidate, ranks[] = voter's preference number
    for (int k = 0, s = candidate_count; k < s; k++)
    {
        if (strcmp(candidates[k], name) == 0)
        {
            ranks[rank] = k;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // for (int i = 0, s = candidate_count; i < s; i++)
    // {
    //     for (int j = i + 1; j < s; j++)
    //     {
    //         preferences[i][j] = 0;
    //     }
    // }
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int upper_candidate = ranks[i];
            int lower_candidate = ranks[j];
            preferences[upper_candidate][lower_candidate]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // pair_count = 0;
    for (int i = 0, s = candidate_count; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                // printf("pair value: %i\n", preferences[i][j]);
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
                // printf("pair_count: %i\n", pair_count);
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // printf("HHHHHHHHHHH\n");
    int strength[pair_count];
    for (int i = 0; i < pair_count; i++)
    {
        int winner_strength = preferences[pairs[i].winner][pairs[i].loser];
        int loser_strength = preferences[pairs[i].loser][pairs[i].winner];
        strength[i] = winner_strength - loser_strength;

        // printf("repeat\n");
    }
    for (int i = 0; i < pair_count - 1; i++)
    {
        int max_index = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (int j = i + 1; j < pair_count; j++)
        {
            if (strength[max_index] < strength[j])
            {
                max_index = j;
            }
        }

        // Swap the found minimum element with the first element
        pair temp = pairs[max_index];
        pairs[max_index] = pairs[i];
        pairs[i] = temp;
    }
    // for (int i = 0; i < pair_count - 1; i++)
    // {
    //     int swapped = 0;
    //     for (int j = 0; j < pair_count - 1; j++)
    //     {
    //         if (strength[j + 1] > strength[j])
    //         {
    //             pair temp = pairs[j + 1];
    //             pairs[j + 1] = pairs[j];
    //             pairs[j] = temp;
    //             swapped = 1;
    //         }
    //     }
    //     if (swapped == 0)
    //     {
    //         for (int x = 0; x < pair_count; x++)
    //         {
    //             printf("s: %i\n",strength[x]);
    //         }
    //         break;
    //     }
    // }
    return;
}

bool has_cycle(int winner, int loser)
{
    if (locked[loser][winner] == true)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] == true && has_cycle(winner, i))
        {
            return true;
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (!has_cycle(winner, loser))
        {
            locked[winner][loser] = true;
            // printf("pairs[i].winner: %i pairs[i].loser: %i\n", pairs[i].winner, pairs[i].loser);
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    // int win_rate[candidate_count];
    // for (int i = 0; i < candidate_count;i++)
    // {
    //     win_rate[i] = 0;
    // }
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         if (locked[i][j] == true)
    //         {
    //             win_rate[i]++;
    //         }
    //     }
    // }
    // int winner_index_array[candidate_count];
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     winner_index_array[i] = -1;
    // }
    // int max_wins = 0;
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     if (win_rate[i] > max_wins)
    //     {
    //         max_wins = win_rate[i];
    //     }
    // }
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     int index = 0;
    //     if (win_rate[i] == max_wins)
    //     {
    //         winner_index_array[index] = i;
    //         index++;
    //     }
    // }
    // for (int i = 0; winner_index_array[i] != -1; i++)
    // {
    //     printf("%s\n",candidates[winner_index_array[i]]);
    // }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                break;
            }
            else if (j == candidate_count - 1)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
    return;
}
