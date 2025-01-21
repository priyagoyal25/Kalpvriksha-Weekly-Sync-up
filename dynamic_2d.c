#include<stdio.h>
#include<stdlib.h>

void print_array(int rows, int cols, int** arr){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", *((*arr + i)+j));
        }
        printf("\n");
    }
}
int main(){
    int rows, cols;
    printf("Enter rows and cols: ");
    scanf("%d %d", &rows, &cols);

    int** arr = (int **) malloc(rows * sizeof(int *));

    for(int i=0;i<rows;i++){
        arr[i] = (int *) malloc(cols * sizeof(int));
    }

    printf("Enter elements:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d", (*arr + i)+j);
        }
    }

    printf("\nEntered elements: \n");
    print_array(rows, cols, arr);

    return 0;
}
