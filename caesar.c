#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digit(string cl_input);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    // Make sure every character in argv[1] is a digit
    if (only_digit(argv[1]) == false)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int num = atoi(argv[1]);
    // Prompt user for plaintext
    string plain_text = get_string("Plain text: ");
    // For each character in the plaintext:
    int n = strlen(plain_text);

    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    // Rotate the character if it's a letter
    {
        char new_c = rotate(plain_text[i], num);
        printf("%c", new_c);
    }
    printf("\n");
}

bool only_digit(string cl_input)
{
    int n = strlen(cl_input);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(cl_input[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        return (c - 'a' + n) % 26 + 'a';
    }
    else
    {
        return c;
    }
}
