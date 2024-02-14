#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get input - Card number
    long card = get_long("Number: ");

    // Find length of number
    int length = 0;
    long x = card + 0;
    while (x)
    {
        x /= 10;
        length++;
    }
    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    // printf("%i\n", length);

    //// Finding 1st and 2nd digits
    long y = card;
    for (int j = 0; j < length - 2; j++)
    {
        y /= 10;
    }
    int first_two_digits = y;
    y /= 10;
    int first_digit = y % 10;

    // printf("first: %i\n", first_digit);
    // printf("first two digits: %i\n", first_two_digits);

    //// Calculate CheckSum
    // Define sums of alternate number sets
    int sum_doubles = 0;
    int sum_singles = 0;

    int i = 0;
    while (card)
    {
        if (i % 2 == 1)
        {
            int digit_double = (card % 10) * 2;
            if (digit_double < 10)
            {
                sum_doubles += digit_double;
            }
            else
            {
                int digit_double_sum = 0;
                while (digit_double)
                {
                    digit_double_sum += digit_double % 10;
                    digit_double /= 10;
                }
                sum_doubles += digit_double_sum;
            }
        }
        else if (i % 2 == 0)
        {
            sum_singles += card % 10;
        }
        card /= 10;
        i++;
    }
    // printf("doubles: %i\nSingles: %i\n", sum_doubles, sum_singles);
    int total_sum = sum_doubles + sum_singles;

    if (total_sum % 10 == 0)
    {
        if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (first_two_digits < 56 && first_two_digits > 50))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }

    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
