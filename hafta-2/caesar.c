#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[]){


    

    if(argc == 2 && argv[1] != 0 && isdigit(argv[1][0]))
    {

    string uncrypted_text = get_string("plaintext: ");
    string encrypted_text = uncrypted_text;
    
    unsigned int key = atoi(argv[1]);
    
    int updated_value;
    int ascii_char_start = 98;
    unsigned int key_counter = key;

    for(int i = 0, length = strlen(encrypted_text); i < length; i++)
    {
        if(((int)encrypted_text[i] >= 32 && (int)encrypted_text[i] <= 47) || ((int)encrypted_text[i] >= 58 && (int)encrypted_text[i] <= 63))
        {
            //do nothing.
        }
        else
        {
            updated_value = uncrypted_text[i] + key;
            if(islower(uncrypted_text[i]) && (updated_value > 122)) //if letter is lower case and letter ascii value + key total is over the 122 (it's equal 'z' so last  upper case letter on ASCII table) then set letter's ascii value to 97 (it's equal to 'a') and keep that loop till key_counter(program gets it by terminal input) is 0. So we can change the letter to letter not anything else(like ! | [ , etc.).
            {
                while(key_counter != 0)
                {
                    while(uncrypted_text[i] < 122 && key_counter != 0)
                    {
                        uncrypted_text[i]++;
                        key_counter--;
                    }
                    
                    if(key_counter == 0)
                    {
                        key_counter = key;
                        break;
                    }
                    else
                    {
                        uncrypted_text[i] = 96;
                    }
                }
            }
            else if(isupper(uncrypted_text[i]) && (updated_value > 90 && updated_value < 97)) //if letter is upper case and letter ascii value + key total is over the 90 (it's equal 'Z' so last  upper case letter on ASCII table) then set letter's ascii value to 65 (it's equal to 'A') and keep that loop till key_counter(program gets it by terminal input) is 0. So we can change the letter to letter not anything else(like ! | [ , etc.).
            {
                while(key_counter != 0)
                {
                    while(uncrypted_text[i] < 90 && key_counter != 0)
                    {
                        uncrypted_text[i]++;
                        key_counter--;
                    }
                    
                    if(key_counter == 0)
                    {
                        key_counter = key;
                        break;
                    }
                    else
                    {
                        uncrypted_text[i] = 64;
                    }
                }
            }
            else //if encrypted_text[i] letter ascii value + key is not over the 90('Z') or 122('z'), just do the process.
            {
                encrypted_text[i] += key;
            }

        }
        
    }

    printf("ciphertext: %s\n", encrypted_text);

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    return 0;
}
