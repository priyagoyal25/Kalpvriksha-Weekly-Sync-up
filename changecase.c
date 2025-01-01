#include <stdio.h>
#include<string.h>

int main() {
    char input_string[100];

    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin); 
   
    for (int index = 0; input_string[index] != '\0'; index++) {
       
        if (input_string[index] >= 'a' && input_string[index] <= 'z') {
            input_string[index] = input_string[index] - 32; 
        }
        else if (input_string[index] >= 'A' && input_string[index] <= 'Z') {
            input_string[index] = input_string[index] + 32; 
        }
    }
    printf("Changed Case of given String: %s\n", input_string);

    return 0;
}