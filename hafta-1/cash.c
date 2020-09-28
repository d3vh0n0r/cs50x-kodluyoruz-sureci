#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_money_value(void)
{
    float dollars = get_float("enter the value: ");
    int cents = round(dollars*100);
    return cents;
}

void greedy_algorithm(int cents)
{
    
    int cent_given = 0;
    while(cents - 25 >= 0){
        cent_given++;
        cents -= 25;
    }
    while(cents - 10 >= 0){
        cent_given++;
        cents -= 10;
    }
    while(cents - 5 >= 0){
        cent_given++;
        cents -= 5;
    }
    while(cents - 1 >= 0){
        cent_given++;
        cents -= 1;
    }
    printf("%i\n", cent_given);

    
}

int main(void)
{
    greedy_algorithm(get_money_value());
}
