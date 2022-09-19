#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Ask for input
    float change;
    do
    {
        change = get_float("The change is: ");
    }
    while (change < 0);
    
    // Round cents to the nearest penny
    
    int dollarCent = round (change * 100);
    int money = 0;
    
    // Computing the quarters
    
    while (dollarCent >= 25)
    {
        dollarCent = dollarCent - 25;
        money++;
    }
    
    // Computing the dimes
    
    while (dollarCent >= 10)
    {
        dollarCent = dollarCent - 10;
        money++;
    }
    
    // Computing the nickels
    
    while (dollarCent >= 5)
    {
        dollarCent = dollarCent - 5;
        money++;
    }
    
    // Computing the pennies 'till change is equal to 0
    
    while (dollarCent >= 1 && dollarCent > 0)
    {
        dollarCent = dollarCent - 1;
        money++;
    }
    
    // At the end, print the answer of this question "how many coins does the cashier give?"
    
    printf("%i\n", money);
}