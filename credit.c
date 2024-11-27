#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long long card;
    do
    {
        card = get_long("Please enter the credit card number: ");
    }
    while (card < 0);

    int sum = 0;
    int div = 10;
    // calculate the lenghth of the card
    int digits = floor(log10(card)) + 1;
    int first_2 = card / (pow(10, digits - 2));

    for (int i = 0; i < digits; i++)
    {
        int rem = card % div;
        card = floor(card / div);
        if (i % 2 == 0)
        {
            sum += rem;
        }
        else
        {
            rem *= 2;
            if (rem < 10)
            {
                sum += rem;
            }
            else
            {
                sum = sum + (rem - 10) + 1;
            }
        }
     }

     if (digits == 14 || digits < 13 || (sum % 10 != 0))
     {
        printf("INVALID\n");
     }
     else if (digits == 15 && (first_2 == 34 || first_2 == 37))
     {
        printf("AMEX\n");
     }
      else if (digits == 16 && (first_2 >= 51 && first_2 <= 55))
     {
        printf("MASTERCARD\n");
     }
     else if ((digits == 13 || digits == 16) && (first_2 / 10 == 4))
     {
        printf("VISA\n");
     }
     else
     {
        printf("INVALID\n");
     }
}


