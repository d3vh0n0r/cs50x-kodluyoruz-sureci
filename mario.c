#include <stdio.h>
#include <cs50.h>

//definition taking height value by prompt
int get_hash_number(){

    int hash_number = 0;
    
    hash_number = get_int("enter height: ");
    
    return hash_number;
    
}

//definition of block system
void make_block(int hash_number){

    int hash_query = 1;

    for(int i = 0; i < hash_number; i++){
       
        for(int j = hash_number - hash_query; j > 0; j--){
            printf(" ");
        }
        
        for(int z = 0; z < hash_query; z++){
            printf("#");
        }

        if(hash_query < hash_number){
            hash_query++;
        }

        printf("\n");

    }
}

int main(void){

    //program will keep ask till get the right value by user   
    while(true){
        //calling get_hash_number func to get value
        int hash_number = get_hash_number();

        if(hash_number >= 1 && hash_number <= 8)
        {
            //calling make_block func
            make_block(hash_number);

            //we got the right answer so we kill the program
            break;
        }
    }
    

}
