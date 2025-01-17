#include<stdio.h>
#include<string.h>

void change_string(char string[]){
    int i = 0;
    while(string[i] != '\0'){
        if((i+1) % 2 == 0 && string[i] >= 'a' && string[i]<='z'){
            string[i] = (string[i] -'a') + 'A';
        }
        i++;
    }
}

void change_string_modified(char string[]){
    int i = 0;
    int res_index = 0;

    while(string[i] != '\0'){
        if((i+1) % 2 == 0 && string[i] >= 'a' && string[i]<='z'){
            string[res_index] = (string[i] -'a') + 'A';
            res_index++;
        }else if(string[i] >= 'a' && string[i]<='z' || string[i] >= 'A' && string[i]<='Z'){
            string[res_index++] = string[i];
        }
        i++;
    }
    string[res_index] = '\0';
    printf("%s", string);
}

int main(){
    char string[16] = {'\0'};

    printf("Enter string: ");
    scanf("%15s", string);

    change_string(string);
    // change_string_modified(string);
    printf("String: %s", string);
    return 0;
}