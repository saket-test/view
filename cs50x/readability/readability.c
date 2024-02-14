#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int length;

int main(void)
{
    string text = get_string("Text: ");
    // printf("Text: %s\n", text);
    // int length = strlen(text);
    // printf("length: %i\n",length);

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // printf("%i letters\n", letter_count);
    // printf("%i words\n", word_count);
    // printf("%i sentences\n", sentence_count);

    float L = letter_count * 100.0 / word_count;
    float S = sentence_count * 100.0 / word_count;
    // printf("L: %f\nS: %f\n", L, S);
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 17)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letter_per_text = 0;
    length = strlen(text);
    // printf("length: %i\n",length);
    for (int i = 0; i < length; i++)
    {
        int character = text[i];
        if ((character > 64 && character < 91) || (character > 96 && character < 123))
        {
            letter_per_text++;
        }
    }
    return letter_per_text;
}

int count_words(string text)
{
    int word_per_text = 1;
    length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        int character = text[i];
        if (character == ' ')
        {
            word_per_text++;
        }
    }
    return word_per_text;
}

int count_sentences(string text)
{
    int sentence_per_text = 0;
    length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        int character = text[i];
        if (character == '!' || character == '.' || character == '?')
        {
            sentence_per_text++;
        }
    }
    return sentence_per_text;
}
