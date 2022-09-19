#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Ask for input
    string text = get_string("The text:\n ");
    
    // Defining the variables
    int let, sen, wor;
    
    int sl = strlen(text);
    
    let = 0;
    sen = 0;
    wor = 0;
    
    // Getting into the loop
    for(int z = 0; z < sl; z++)
    {
        //for each character calculate
        char i = text[z];
        
        if (isalpha(i) != 0)
        {
            let++;
        }
    
        if (i == '.' || i == '?' || i == '!')
        {
            sen++;
        }
        
        if (i == ' ')
        {
            wor++;
        }
    }
// Otherwise it is not gonna count the last word
wor = wor + 1;
        
// Convert integers to floats and do the math
float L = ((float)let / (float)wor) * 100;
float S = ((float)sen / (float)wor) * 100;
        
    float index = 0.0588 * L - 0.296 * S - 15.8;
        
// Truncating
int finality = round(index);
        
    if (finality > 16)
    {
        printf("Grade 16+\n");
    }
        
    else if (finality < 1)
    {
        printf("Before grade 1\n");
    }

    else 
    {
        printf("Grade %i\n", finality);
    }
       
}