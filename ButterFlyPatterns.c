/*

1        1
12      21
123    321
1234  4321
1234554321
1234  4321
123    321
12      21
1        1

*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter no of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        int space = 2*(n-i);
        for(int sp = 1; sp<=space; sp++){
            printf(" "); 
        }
        for (int j = i; j >= 1; j--)
        {
            printf("%d", j);
        }
        printf("\n");
    }



    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        int space = 2*(n-i);
        for(int sp = 1; sp<=space; sp++){
            printf(" "); 
        }
        for (int j = i; j >= 1; j--)
        {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}