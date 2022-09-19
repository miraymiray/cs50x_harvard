#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
   
   do 
   {
// ask for height input
       h = get_int("Height; ");
   }
   while (h > 8 || h < 1);
   
   for(int r = 0; r < h; r ++)
   {
// space has to be less than height - row - 1 for a pyramid
      for (int s = 0; s < h - 1 - r; s++) 
      {
// for the places which don't have hashes, space
            printf(" ");
      }
      for (int c = 0; c <= r; c++)
      {
// put the hashes
            printf("#");
      }
// a newline
      printf("\n");
   }
}