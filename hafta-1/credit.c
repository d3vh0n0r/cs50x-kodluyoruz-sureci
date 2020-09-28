#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get card number by user input 
    long card = get_long("Number: ");


    //to find card number length code block
    long card_number = card;
    int card_length_counter = 0;
    while(card_number != 0)
    {
        card_number /= 10;
        card_length_counter++;
    }
    
   
    //validation that card is real or not
    int underlined_numbers = 0;
    int others = 0;
    int number_control;
    long card_no = card;
    while(card_no > 0)
    {
        others += card_no % 10;
        card_no /= 10;
        number_control = (card_no % 10)*2;
        if(number_control > 9)
        {
            underlined_numbers += number_control%10;
            number_control /= 10;
            underlined_numbers += number_control;
        }
        else
        {
            underlined_numbers += number_control;
        }

        card_no /= 10;
    }
    int result = underlined_numbers + others;


    if(result % 10 == 0)
    {
        //validation card length
        if(card_length_counter == 13 || card_length_counter == 15 || card_length_counter == 16)
        {
            //finding the first 2 number
            long first_two = card;
            for(int i = 0; i < card_length_counter-2; i++)
            {
                first_two /= 10;
            }


            //which company the card is
            if(first_two == 34 || first_two == 37)
            {
                printf("AMEX\n");
            }
            else if(first_two >= 51 && first_two <= 55)
            {
                printf("MASTERCARD\n");
            }
            else if(first_two / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
