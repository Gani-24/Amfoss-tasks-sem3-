#include<cs50.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(void)
{
    string inp=get_string("Type: ");
    int letter=0;
    int word=1;
    int sentence=0;

    for(int i=0;i<strlen(inp);i++)
    {
        if(inp[i]>='a' && inp[i]<='z')
        {
        letter++;
        }
        else if(inp[i]>='A' && inp[i]<='Z')
        {
            letter++;
        }
        else if(inp[i]==' ')
        {
            word++;
        }
        else if(inp[i]=='.')
        {
            sentence++;
        }
        else if(inp[i]=='!')
        {
            sentence++;
        }
        else if(inp[i]=='?')
        {
            sentence++;
        }
    }
    float grade =0.0588*(100* (float)letter/(float)word)-0.296*(100* (float)sentence/(float)word)-15.8;
    if(grade>=0 && grade<16)
    {
        printf("Grade: %i\n", (int) round(grade));
    }
    else if(grade>=16)
    {
        printf("Grade: 16 \n");
    }
    else
    {
        printf("Less than Grade 1");
    }
    }
