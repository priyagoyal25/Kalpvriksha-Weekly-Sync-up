/*
Color Coding question
0 -> red
1 -> blue
2 -> green
sort the colorcoding as red -> blue -> green 
i.e. sort 0, 1, 2
*/
#include <stdio.h>

void sortfunc(int arr[], int n)
{
    int temp, i = 0, start = 0, end = n - 1;
    while (i <= end)
    {
        if (arr[i] == 0)
        {
            temp = arr[i];
            arr[i] = arr[start];
            arr[start] = temp;
            start++;
            i++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else
        {
            temp = arr[i];
            arr[i] = arr[end];
            arr[end] = temp;
            end--;
        }
    }
}

int main()
{
    int n, arr[100];
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter array:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sortfunc(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}