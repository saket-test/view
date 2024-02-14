#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int i = 0;
    int score = 0;
    while (word[i])
    {
        char a = word[i];
        if (a > 64 && a < 91)
        {
            int x = a - 'A';
            int y = POINTS[x];
            score += y;
            printf("score %c: %i\n", a, score);
        }

        else if (a > 96 && a < 123)
        {
            int x = a - 'a';
            int y = POINTS[x];
            score += y;
            printf("score %c: %i\n", a, score);
        }
        i++;
    }
    return score;
}

// 1. a = 97, z = 122, A = 65, Z = 90
// If lowercase letter (96 < letter < 123) -> subtract 96
// If uppercase letter (65 < letter < 91) -> subtract 65
// 2. Pick score from array by POINTS[index]
// 3. Compare both scores

// 4. Print result
