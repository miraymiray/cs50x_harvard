#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score2 < score1) 
    {
        printf("Player 1 wins! \n");
    }
    
    else if (score1 < score2) 
    {
        printf("Player 2 wins! \n");
    }
    
    else if(score1 == score2) 
    {
        printf("Tie! \n");
    }
    
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int players_score = 0;
    
    for(int start = 0; start < strlen(word); start++)
    
    // Checks if it's alphabet
    if (isalpha(word[start]))
    {
        //Convert letters to uppercase 
        word[start] = toupper(word[start]);
        
        // Convert 'word' to integer and minus 65 because of ASCII codes
        players_score = players_score + POINTS[(int)word[start] - 65];
    }
    
    return players_score;
}
