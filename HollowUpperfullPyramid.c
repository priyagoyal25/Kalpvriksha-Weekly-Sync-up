/*

        1
      1   3
    1       5
  1           7
1 2 3 4 5 6 7 8 9

*/
#include <stdio.h>


int main()
{
    int n;
    printf("Enter no of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
      
        int space = n - i;
        for (int sp = 1; sp <= space; sp++)
        {
            printf("  ");
        }
        
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if(j == 1 || j==2 * i - 1 || i == n){
                printf("%d ", j);
            }
            else{
                printf("  ");
            }
            
        }
        printf("\n");
    }
    return 0;
}