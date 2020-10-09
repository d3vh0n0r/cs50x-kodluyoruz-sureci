#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int shift(char letter);
bool argv_check(string argv, char check_type);

int main(int argc, string argv[])
{
    if(argv[1] != '\0' && argc == 2 && argv_check(argv[1], 'a'))
    {
        string uncrypted_text = get_string("plaintext: ");
        string encrypted_text = uncrypted_text;

        int ascii_overflow_check, counter;

        for(int i = 0, j = 0, ut_length = strlen(uncrypted_text), argv_length = strlen(argv[1]); i < ut_length; i++, j++)
        {
            if(j == argv_length)
            {
                j = 0;
            }
            
            

            ascii_overflow_check = encrypted_text[i] + shift(argv[1][j]);
            counter = shift(argv[1][j]);

            if((encrypted_text[i] >= 32 && encrypted_text[i] <= 47) || (encrypted_text[i] >= 58 && encrypted_text[i] <= 64))
            {
                j--;
            }

            if(encrypted_text[i] >= 97 && encrypted_text[i] <= 122)
            {
                while(counter != 0)
                {
                    if(encrypted_text[i] > 122)
                    {
                        encrypted_text[i] = 97;
                        
                    }

                    encrypted_text[i]++;
                    

                    counter--;
                } 
                
                
            } 
            else if(encrypted_text[i] >= 65 && encrypted_text[i] <= 90)
            {
                while(counter != 0)
                {
                    if(encrypted_text[i] > 90)
                    {
                        encrypted_text[i] = 65;
                        printf("encrypted_text[i] = 65'ye sıfırlandı.: %i\n", encrypted_text[i]);
                    }

                    encrypted_text[i]++;
                    printf("encrypted_text[i]: %i\n", encrypted_text[i]);

                    counter--;
                }
            }
            else
            {
                
            }
        }

        printf("ciphertext: %s\n", encrypted_text);
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    return 0;
}


int shift(char letter)
{
    int key = 0;
    int letter_ascii = (int) tolower(letter);

    if((letter_ascii >= 32 && letter_ascii <= 47) || (letter_ascii >= 58 && letter_ascii <= 64))
    {
        return 0;
    }
    else
    {
        key = letter_ascii - 97;
        
    }

    return key;
}

bool argv_check(string argv, char check_type)
{
    /*
    this funct returns boolean value.
    Note: to use this funct, string.h must be defined.

    example usage:
    argv_check(argv[1], 'a'); -contraction of alpha
    argv_check(argv[5], 'd');  -contraction of digit
    */

    bool stat;
    if(check_type == 'a')
    {
        for(int i = 0, argv_length = strlen(argv); i < argv_length; i++)
        {
            if(isalpha(argv[i]))
            {
                stat = true;
            }
            else
            {
                stat = false;
                break;
            }
        }
    }
    else if(check_type == 'd')
    {
        for(int i = 0, argv_length = strlen(argv); i < argv_length; i++)
        {
            if(isdigit(argv[i]))
            {
                stat = true;
            }
            else
            {
                stat = false;
                break;
            }
        }
    }
    else
    {
        return 1;
    }
    
    return stat;
}
