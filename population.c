#include <cs50.h>
#include <stdio.h>

int main()
{

  int start, end;
  
  // TODO: Prompt for start size
  
  do
  {
   start = get_int("Start Size: ");
  }
  while (start < 9);
  
// TODO: Prompt for end size

  do
  {
    end = get_int("End Size: ");
  }
  while (end < start);
    
// TODO: Calculate number of years until we reach threshold
 int years = 0;
 
 while (start < end)
 {
 start = start + (start / 3) - (start / 4);
 years++;
 
 }

// TODO: Print number of years
 {
 printf("Required Years: %i\n", years);
 }
 
}
