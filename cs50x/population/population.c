#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Possitive Integer: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("Possitive Integer: ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    // int n = start_size;
    int count = 0;
    // while (n < end_size)
    for (int n = start_size; n < end_size; count++)
    {
        n = n + (n / 3) - (n / 4);
    }
    // TODO: Print number of years
    printf("Years: %i\n", count);
}
