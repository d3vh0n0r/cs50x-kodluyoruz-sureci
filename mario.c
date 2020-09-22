#include <stdio.h>
#include <cs50.h>

//definition taking height size by prompt
int get_hash_number(){
    int hash_number = 0;

    printf("enter height: ");
    
    hash_number = get_int("");

    return hash_number;
}

//definition of making block with hash system
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
    int hash_number = 0;

    do{
        hash_number = get_hash_number();
    }
    while(hash_number  < 1 || hash_number > 8);

    make_block(hash_number);
}

