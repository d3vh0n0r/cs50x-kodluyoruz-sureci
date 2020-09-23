#include <stdio.h>
#include <cs50.h>

/*
EXAMPLE OUTPUT
Note: program allows between 1 and 8

enter the height: 15
enter the height: sdgdsg
enter the height: 
enter the height: 3
  #  #
 ##  ##
###  ###
*/


//definition of get the value by prompt
int get_height_func(void)
{
    float height; // i used float because of when i tried int it gives error
    height = get_float("enter the height: ");
    return height;
}

//definition of making block system
void block_maker(int height)
{   
    int space_counter = height-1; //each time we need different space value so we should make variable to be dynamic
    int hash_counter = 1; //same reason above
    for(int i = 0; i < height; i++)
    {
        for(int sc = space_counter; sc > 0; sc--) //we typed spaces
        {
            printf(" ");
        }

        for(int x = 0; x < hash_counter; x++) //we typed first section of the block
        {
            printf("#");
        }
        
        printf("  "); //between space
        
        for(int z = 0; z < hash_counter; z++) //we typed second section of the block
        {
            printf("#");
        }

        printf("\n");
        space_counter--; //so we should -1 the space and +1 the "#" till we hit the height value
        hash_counter++;

    }
}

int main(void)
{
    int height = get_height_func();
    
    while(true) //we used while for get input till user prompt the proper answer
    {
        if(height >= 1 && height <= 8)
        {
            block_maker(height);
            break; //we got the proper answer and made the block by block_maker function so we done, we break the loop
        }
        else
        {
            height = get_height_func();
        }
    }
    
    
}
