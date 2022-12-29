#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    for(int k=0;k<strlen(argv[1]);k++)
    {
        if(isalpha(argv[1][k]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }

    }
    int k=atoi(argv[1])%26;
    string plaintext=get_string("PlainText: ");
    printf("CipherText: ");
    for(int i=0;i<strlen(plaintext);i++)
    {
        if(!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
        int offset=isupper(plaintext[i])? 65:97;
        int pi=plaintext[i]-offset;
        int ci=(pi+k)%26;
        printf("%c",ci+offset);
    }
    printf("\n");
    return 0;

}