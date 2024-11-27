#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int score(string word);

int main(void)
{
     string player1_word = get_string("Please enter a word: ");
     string player2_word = get_string("Please enter a word: ");
     int score1 = score(player1_word);
     int score2 = score(player2_word);

     if (score1 > score2)
     {
        printf("Player 1 wins!\n");
     }
     else if  (score1 < score2)
     {
       printf("Player 2 wins!\n");
     }
     else
     {
        printf("Tie!\n");
     }
}

int score(string word)
{
    char letter[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int point[] = {1, 3, 3, 2, 1, 4,2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10,1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;
    int n = strlen(word);

    for (int i = 0; i < n ; i++ )
    {
        word[i] = tolower(word[i]);
        for (int j = 0; j < 26; j++)
        {
            if (letter[j] == word[i])
        {
            score += point[j];
        }
        }
    }
    return score;
}
