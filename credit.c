# include <stdio.h>
# include <cs50.h>

long getCardNumber(void);
string validateCard(long number);

int main(void)
{
    printf("%s",validateCard(getCardNumber()));
}

long getCardNumber(void)
{
   long num = 0;
   long limit = 10000000000000000;
   while (1)
   {
      num = get_long("Number: ");
      if (num > 0 && num < limit)
      {
          return num;
      }
   }

}

string validateCard(long number)
{
    long card = number;
    long valids = 0;
    int counter = 0;
    long index = 0;
    long temp;
    while (card > 0)
    {
        if (card >= 10 && card < 100)
            index = card;

        if (counter < 1)
        {
            valids += card % 10;
            card = card / 10;
            counter += 1;
        }
        else
        {
            temp = 2 * (card % 10);
            if (temp >= 10)
            {
                valids += temp % 10;
                valids += temp / 10;
                card = card / 10;
                counter = 0;
                temp = 0;
            }
            else
            {
                valids += temp;
                card = card / 10;
                counter = 0;
                temp = 0;
            }
        }
    }
    //printf("%ld %ld\n", index, valids);
    if ((index == 32 || index == 37) && valids % 10 == 0)
        return "AMERICAN EXPRESS\n";
    else if (index / 10 == 4 && valids % 10 == 0)
        return "VISA\n";
    else if ((index == 22 || (index >= 51 && index <= 55)) && valids % 10 == 0)
        return "MASTER CARD\n";
    else
        return "INVALID\n";
}