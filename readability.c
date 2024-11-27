#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

int count_letter(string text);
int count_word(string text);
int count_sentence(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    // Count the number of letters, words, and sentences in the text
    int letters = count_letter(text);
    int words = count_word(text);
    int sentences = count_sentence(text);
    float l = (letters / (float) words) * 100;
    float s = (sentences / (float) words) * 100;
    // Compute the Coleman-Liau index
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);
    // Print the grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// count # of letters, words & sentences

int count_letter(string text)
{
    int letter = 0;
    int N = strlen(text);
    for (int i = 0; i < N; i++)
        {
            if (isalpha(text[i]))
            {
                letter += 1;
            }
        }
    // printf("letter %i \n", letter);
    return letter;
}

int count_word(string text)
{
    int word = 0;
    int N = strlen(text);
    for (int i = 0; i < N; i++)
        {
            if (isspace(text[i]))
            {
                word += 1;
            }
        }
    if (word > 0)
    {
        word += 1;
    }

    // printf("word %i \n", word);
    return word;
}

int count_sentence(string text)
{
    int sentence = 0;
    int N = strlen(text);
    for (int i = 0; i < N; i++)
        {
            if (text[i] == '.'  || text[i] == '!' || text[i] == '?')
            {
                sentence += 1;
            }
        }
     // printf("sentences %i \n", sentence);
     return sentence;
}




