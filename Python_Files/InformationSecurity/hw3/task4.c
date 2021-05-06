#include <stdio.h>
unsigned char a[300] = { 'H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A'};
unsigned char b[300] = { 'H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A','H','A','A','A','A','A','A','A','A','A'};
int main()
{
        int i;
        int isSame=1;
        for(i = 0; i < 200; i++)
        {
                if(a[i]!=b[i])
                        isSame=0;
        }
        if(isSame)
                printf("This would run the safe code and display the intended behaviour");
        else
                printf("This is where malicious code would be run");
        printf("\n");
}
