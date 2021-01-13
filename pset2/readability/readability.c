#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void print_grade(int index);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = letters * 100.0 / words;    // average of letters for 100 words
    float S = sentences * 100.0 / words;  // average of sentences for 100 words

    float index = round(index = (0.0588 * L) - (0.296 * S) - 15.8); // Coleman-Lieu index of readability formula

    print_grade(index);

}


int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = text[i];

        if ((c > 64 && c < 91) || (c > 96 && c < 123)) // check if ASCII value is a letter (capital or not)
        {
            letters ++;
        }
    }
    return letters;
}


int count_words(string text)
{
    int words = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = text[i];

        if (c == 32) // ASCII value for space ' '
        {
            words++;
        }
    }
    // to count the last word since the sentence doesn't end with a space
    words++;
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int c = text[i];

        if (c == 46 || c == 33 || c == 63) // ASCII value for '.', '!', and '?'
        {
            sentences++;
        }
    }
    return sentences;
}


void print_grade(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index >= 16)
    {
        printf("Grade 16+");
    }
    else 
    {
        printf("Grade %i", index);
    }

    printf("\n");
}