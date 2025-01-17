#include<stdio.h>

void even_index_zero(int row, int col, int arr[row][col]){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if((i+j) % 2 == 0){
                arr[i][j] = 0;
            }
        }
    }
}

int main(){
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);
    int arr[row][col];

    printf("Enter elemenst: \n");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    even_index_zero(row, col,arr);

    printf("Elements: \n");

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}