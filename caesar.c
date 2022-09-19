#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// a string and an integer arguments
int main(int argc, string argv[])
{
    // checking it is equal to 2 - error
    if (argc != 2)
    {
        printf("Usage: ./ceasar key \n");
        return 1;
    }

    // checking if the argument is alphabet - error
    for (int key = 0; key < strlen(argv[1]); key++)
    {
        if (isalpha(argv[1][key]))
        {printf("Usage: ./caesar key\n");
            return 1;
        }
    }

// converting to integer
    int key = atoi(argv[1]) % 26;
    
    //text input
    string txt = get_string("plaintext: ");

    printf("ciphertext: ");

    // loop for text
    for (int i = 0, length = strlen(txt); i < length; i++)
    {
        if (!isalpha(txt[i]))
        {
            //if it is not alpha then just print it
            printf("%c", txt[i]);
            continue;
        }
        // checking if the letter is uppercase
        int ascıı = isupper(txt[i]) ? 65 : 97;
        
        // calculating lowercase "a" or uppercase "A"
        int pi = txt[i] - ascıı;
        
        // algorithm
        int ci = (pi + key) % 26;

        // print the finality
        printf("%c", ci + ascıı);
    }
    
    printf("\n");
    
    return 0;
}