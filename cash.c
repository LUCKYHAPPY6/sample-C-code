#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt the user for change owed, in cents
    int balance;
    do
    {
        balance = get_int("Change owed: ");
    }
    while (balance < 0);

    int num_quarter = balance / 25;
    balance -= num_quarter * 25;
    int num_dime = balance / 10;
    balance -= num_dime * 10;
    int num_nickel = balance / 5;
    balance -= num_nickel * 5;
    int num_cent = balance / 1;
    int total_number_coin = num_quarter + num_dime + num_nickel + num_cent;
    printf("%d\n", total_number_coin);
}
