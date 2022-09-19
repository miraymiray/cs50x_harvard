#include "helpers.h"
#include <cs50.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int period = 0; period < height; period++)
    {
     for(int group = 0; group < width; group++)
     {
         float aver = (image[period][group].rgbtBlue + image[period][group].rgbtGreen + image[period][group].rgbtRed)/3.00;
         int avg = round(aver);
         
         image[period][group].rgbtBlue = avg;
         image[period][group].rgbtRed = avg;
         image[period][group].rgbtGreen = avg;
     }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int period = 0; period < height; period++)
    {
     for(int group = 0; group < width; group++)
     {
         int sepiaRed = round(.393 * image[period][group].rgbtRed + .769 * image[period][group].rgbtGreen + .189 * image[period][group].rgbtBlue);
         int sepiaGreen = round(.349 * image[period][group].rgbtRed + .686 * image[period][group].rgbtGreen + .168 * image[period][group].rgbtBlue);
         int sepiaBlue = round(.272 * image[period][group].rgbtRed + .534 * image[period][group].rgbtGreen + .131 * image[period][group].rgbtBlue);
         
         image[period][group].rgbtRed = (sepiaRed > 255)? 255 : sepiaRed;
         image[period][group].rgbtGreen =(sepiaGreen > 255)? 255 : sepiaGreen;
         image[period][group].rgbtBlue = (sepiaBlue > 255)? 255: sepiaBlue;
     }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int period = 0; period < height; period++)
    {
     for(int group = 0; (group < width/2); group++)
     {
         int RED = image[period][group].rgbtRed;
         int GREEN = image[period][group].rgbtGreen;
         int BLUE = image[period][group].rgbtBlue;
         image[period][group].rgbtBlue = image[period][width - group - 1].rgbtBlue;
         image[period][group].rgbtRed = image[period][width - group - 1].rgbtRed;
         image[period][group].rgbtGreen = image[period][width - group - 1].rgbtGreen;
         image[period][width - group - 1].rgbtBlue = BLUE;
         image[period][width - group - 1].rgbtRed = RED;
         image[period][width - group - 1].rgbtGreen = GREEN;
     }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    for(int period = 0; period < height; period++)
    {
        for(int group = 0; group < width; group++)
        {
         int rBlue = 0;
         int rGreen = 0;
         int rRed = 0;
         float count = 0;
         
         for(int a =-1; a < 2; a++)
         {
             for(int b=-1; b < 2; b++)
             {
                 if (period + a < 0 || period + a > height -1 || group + b < 0 || group + b > width -1)
                 {
                     continue;
                 }
                 
                 rBlue += image[a + period][b + group].rgbtBlue;
                 rGreen += image[a + period][b + group].rgbtGreen;
                 rRed += image[a + period][b + group].rgbtRed;
                 
                 count++;
             }
         }
         temp[period][group].rgbtGreen = round(rGreen/count);
         temp[period][group].rgbtRed = round(rRed/count);
         temp[period][group].rgbtBlue = round(rBlue/count);
        }
    }
    
    for(int period = 0; period < height; period++)
    {
     for(int group = 0; group < width; group++)
     {
         image[period][group].rgbtGreen = temp[period][group].rgbtGreen;
         image[period][group].rgbtRed = temp[period][group].rgbtRed;
         image[period][group].rgbtBlue = temp[period][group].rgbtBlue;   
     }
    }
    return;
}
