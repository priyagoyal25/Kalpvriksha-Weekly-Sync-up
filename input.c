#include<stdio.h>
#include<string.h>

int main(){
    char input[100] = {'\0'};
    printf("Enter: ");
    fgets(input, sizeof(input),stdin);
    // scanf("%[^\n]%*c", input);
    printf("string: %s", input);
    return 0;

}