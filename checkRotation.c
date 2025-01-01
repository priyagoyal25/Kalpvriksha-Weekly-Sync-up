#include <stdio.h>

int len_string(char string[]) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

int isSubStr(int length1, int length2, char string[], char substr[]){
    int index_str, index_substr;
    
    for (index_str = 0; string[index_str] != '\0'; index_str++) {
   
        if (string[index_str] == substr[0]) {

            for (index_substr = 0; substr[index_substr] != '\0'; index_substr++) {
                if (string[index_str + index_substr] != substr[index_substr]) {
                    break; 
                }
            }
            if (substr[index_substr] == '\0') {
                return 1; 
            }
        }
    }
    return 0; 
}

void string_concat(char concatenated_string[], char string[]){
    int index_concat = 0, index_str = 0;
    while(concatenated_string[index_concat] != '\0'){
        index_concat++;
    }

    while(string[index_str] != '\0'){
        concatenated_string[index_concat] = string[index_str];
        index_concat++;
        index_str++;
    }
    concatenated_string[index_concat] = '\0';
}

int isRotation(char string1[], char string2[]) {
    int length1 = len_string(string1);
    int length2 = len_string(string2);

    if (length1 != length2) {
        return 0;
    }

    char concatenated_string[2 * length1 + 1];
    concatenated_string[0] = '\0';

    string_concat(concatenated_string, string1);       
    string_concat(concatenated_string, string1);       

    if(isSubStr(length1, length2, concatenated_string, string2)){
        return 1;
    }
    else{
        return 0;
    }

}

int main() {
    char string1[100], string2[100];

    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);

    if (isRotation(string1, string2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
