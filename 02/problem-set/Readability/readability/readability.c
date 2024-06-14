#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_letter_count(int strc, string str);
int get_word_count(int strc, string str);
int get_sentence_count(int strc, string str);
int coleman_liau_algorithm(string str);

int main()
{
    string text = get_string("Text: ");
    int index = coleman_liau_algorithm(text);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int coleman_liau_algorithm(string str)
{
    int string_length = strlen(str);
    int letter_count = get_letter_count(string_length, str);
    int word_count = get_word_count(string_length, str);
    int sentence_count = get_sentence_count(string_length, str);

    float L = ((float) letter_count / (float) word_count) * 100;
    float S = ((float) sentence_count / (float) word_count) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}

int get_letter_count(int strc, string str)
{
    int letter_count = 0;
    for (int i = 0; i < strc; i++)
    {
        if (isalpha(str[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

int get_word_count(int strc, string str)
{
    int word_count = 1;
    for (int i = 0; i < strc; i++)
    {
        if (isspace(str[i]))
        {
            word_count++;
        }
    }
    return word_count;
}

int get_sentence_count(int strc, string str)
{
    int sentence_count = 0;
    for (int i = 0; i < strc; i++)
    {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
