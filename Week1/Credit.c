#include <cs50.h>
#include <stdio.h>
#include <string.h>
//Determines whether or not a given number is an accurate credit-card number using an implementation of Luhn's Algorithm
int main()
{
    //Variables
    char buffer [50];
    char newBuffer [50];
    int timesTwo = 0;
    int item;   
    int newItem;
    int newNum;
    int x;
    int total = 0;
    //Gets input from user
    long credNum = get_long("Number: ");
    //Converts input to string
    sprintf(buffer, "%ld", credNum);
    //Gets length of string
    int length = strlen(buffer);
    for (int i = length - 2; i >= 0; i -= 2)
    {
        //Multiply by 2
        item = (buffer[i] - '0') * 2;
        if (item < 10)
        {
            //add items together
            timesTwo += item;
        }
        //If item is 2 digits, i.e. greater than 10, break them up into their own items
        else if (item >= 10)
        {
            sprintf(newBuffer, "%d", item);
            for (int j = 0; j < 2; j++)
            {
                newNum = (newBuffer[j] - '0');
                timesTwo += newNum;
            }
        }
    }
    for (int j = length - 1; j >= 0; j -= 2)
    {
        newItem = (buffer[j] - '0');
        total += newItem;
    }

    //Gets the total for the algorithm
    total += timesTwo;
    
    //If else statements to determine which, if any, the type of card is
    if (total % 10 != 0 || length < 13 || length > 16)
    {
        printf("INVALID\n");
    }
    else if (buffer[0] == '4' && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else if (buffer[0] == '5' && (buffer[1] == '1' || buffer[1] == '2' || buffer[1] == '3' || buffer[1] == '4'
                                  || buffer[1] == '5') && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (buffer[0] == '3' && (buffer[1] == '4' || buffer[1] == '7') && length == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
