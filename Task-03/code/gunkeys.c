#include<stdio.h>
int main()
{
    int t,n;
    int countaa=0;
    scanf("%d",&t);
    int keys[3];
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(int i=0;i<3;i++)
        {
            scanf("%d",&keys[i]);
        }
        for(int i=0;i<3;i++)
        {
            
            if(keys[n-1]!=0)
            {
                countaa++;
                n=keys[n-1];
            }
        }
        if(countaa==2)
        {
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        countaa=0;

    }
    return 0;

}