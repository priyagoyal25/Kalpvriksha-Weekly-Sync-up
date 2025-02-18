#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hashmap { 
    char character;
    int value;   
};

struct hashmap map[256]; 
int map_size = 0;  

int map_search(char ch) {
    for (int i = 0; i < map_size; i++) {
        if (map[i].character == ch)
            return i;  
    }
    return -1;  
}

void insert(char ch) {
    int index = map_search(ch);
    if (index == -1) {
        map[map_size].character = ch;
        map[map_size].value = 1;
        map_size++;
    } 
    else {  
        map[index].value++;
    }
}

void find_non_repeating(char *str) {
    char queue[100000];  
    int front = 0, rear = 0;
    int len = strlen(str);

    char *result = (char *)malloc((len * 2) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < len; i++) {
        char ch = str[i];
        insert(ch);
        queue[rear++] = ch;

        while (front < rear) {
            int index = map_search(queue[front]);
            if (index != -1 && map[index].value > 1)
                front++;
            else
                break;
        }

        if (front < rear) {
            result[idx++] = queue[front];
        } else {
            result[idx++] = '-';
            result[idx++] = '1';
        }
    }

    result[idx] = '\0';
    printf("Output: %s\n", result);
    free(result);
}

int main() {
    char str[100000];
    scanf("%s", str);

    find_non_repeating(str);

    return 0;
}
