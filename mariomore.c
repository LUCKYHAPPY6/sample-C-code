#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Please enter a number between 1 and 8 ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < height + 1; j++)
        {
            if (i <= height - j)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");
        for (int k = 1; k < height + 1; k++)
        {
            if (k > height - i)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
