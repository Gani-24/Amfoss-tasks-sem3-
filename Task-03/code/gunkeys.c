#include <stdio.h>
#include <string.h>

int main() 
{
    char n[100];
    int c = 0;
    
    scanf("%s", n);
    
    while (strlen(n) > 1) {
        int sum = 0;
        for (int i = 0; i < strlen(n); i++) {
            sum += n[i] - '0';
        }
        sprintf(n, "%d", sum);
        c++;
    }
    
    printf("%d\n", c);
    
    return 0;
}