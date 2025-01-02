/*

1 2 3 4 5 5 4 3 2 1 
1 2 3 4 * * 4 3 2 1 
1 2 3 * * * * 3 2 1 
1 2 * * * * * * 2 1 
1 * * * * * * * * 1 

*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter no of rows: ");
    scanf("%d", &n);

    for (int i = n ; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", j);
        }
        int space = 2*(n-i);
        for(int sp = 1; sp<=space; sp++){
            printf("* "); 
        }
        for (int j = i; j >= 1; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}