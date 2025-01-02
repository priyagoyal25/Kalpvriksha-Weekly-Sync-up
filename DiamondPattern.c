/*
For input n = 5

        1           
      1 2 3         
    1 2 3 4 5       
  1 2 3 4 5 6 7     
1 2 3 4 5 6 7 8 9   
  1 2 3 4 5 6 7     
    1 2 3 4 5       
      1 2 3         
        1           

*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter no of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {

        for (int sp = 1; sp <= n - i; sp++)
        {
            printf("  ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    for (int i = n - 1; i >= 1; i--)
    {

        for (int sp = 1; sp <= n - i; sp++)
        {
            printf("  ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}