#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    int s;
    int cars=0;
    int one=0,two=0,three=0,four=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                one ++;
                break;
            case 2:
                two ++;
                break;
            case 3:
                three ++;
                break;
            case 4:
                four ++;
                break;
        }
    }
    cars=cars+four;
    cars=cars+three;
    one=one-three;
    if(one<0)
    {
        one =0;
    }
    if(two%2==0)
    {
        two=two/2;
        cars=cars+two;
    }
    else{
        two = two/2 + 1;
        cars=cars+two;
        one = one - 2;
        if(one<0)
        {
            one =0;
        }
    }
    one = ceil(one/4.0);
    cars=cars+one;

    printf("%d\n",cars);
    return 0;
}