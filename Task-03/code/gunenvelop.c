#include <stdio.h>
int main()
{
    int countaa=0;
    int s=-1;
    int n, sum = 0, m;
    scanf("%d", &n);
    while(s!=0)
    {
         while (n > 0)
       {
        m = n % 10;
        sum = sum + m;
        n = n / 10;
       }
       if(sum>=0 && sum<=9)
       {
        countaa++;
        s=0;
       }
       else
       {
        countaa++;
        n=sum;
        sum=0;
       }
    }
    printf("%d\n",countaa);
    return 0;
}