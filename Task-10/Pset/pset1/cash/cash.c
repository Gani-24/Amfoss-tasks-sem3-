#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    float dollar;
    do
    {
        dollar=get_float("Enter your Change Sir/Madam: ");
    }
    while(dollar<=0);

    int s = round(dollar*100);
    int coins=0;

    while(s>=25)
    {
        s-=25;
        coins++;
    }
    while(s>=10)
    {
        s-=10;
        coins++;
    }
    while(s>=5)
    {
        s-=5;
        coins++;
    }
    while(s>=1)
    {
        s-=1;
        coins++;
    }
    printf("number of coins shall be %i\n", coins);
}
