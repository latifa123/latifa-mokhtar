#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare and initialize a variable
    long long cardnumber = 0;

    // Ask the credit card number

    do
    {printf("What is your card number? ");
    cardnumber = get_long_long(" ");
    }
    while (cardnumber < 0);

    // Determine if it has a valid number of digits
    int count = 0;
    long long digits = cardnumber;
    while (digits > 0)
    {
        digits = digits/10;
        count++;
    }
    if ((count != 13) && (count != 15) && (count != 16))
    {
        printf("this card is invalid\n");
    }
    int number[count];


    for (int i = 0; i < count; i++)
    {
        number[i] = cardnumber % 10;

        cardnumber = cardnumber / 10;
    }

    int originalnumber[count];
    for (int i = 1; i < count; i++)
    {
        originalnumber[i] = number[i];
    }

    for (int i = 1; i < count; i+=2)
    {
        number[i] = number[i] * 2;
    }

    int v = 0;
    int temp;

    if (count == 13)
    {
      for (int i = 0; i < count; i++)
      {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        v = v + temp;
      }
      if (originalnumber[12] == 4 && v % 10 == 0)
      {
        printf("it is a visa card\n");
      }
      else
      {
        printf("this card is invalid\n");
      }
    }
    if (count == 15)
    {
      for (int i = 0; i < count; i++)
      {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        v = v + temp;
      }
      if (originalnumber[14] == 3 && v % 10 == 0 && (originalnumber[13] == 4 || originalnumber[13] == 7))
      {
        printf("it is a amex card\n");
      }
      else
      {
        printf("this card is invalid\n");
      }
    }
    if (count == 16)
    {
      for (int i = 0; i < count; i++)
      {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        v = v + temp;
      }
      if (originalnumber[15] == 4 && v % 10 == 0)
      {
        printf("it is a visa card\n");
      }
      else if (originalnumber[15] == 5 && v % 10 == 0 && (originalnumber[14] == 1 || originalnumber[14] == 2 || originalnumber[14] == 3 || originalnumber[14] == 4 || originalnumber[14] == 5))
        {
            printf("it is a master card\n");
        }
      else
      {
        printf("invalid card\n");
      }
    }

    return 0;
}
