#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = 0;
    do
    {
        h = get_int("Heght: ");
    }
    while (h < 1 || h > 8);

    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}