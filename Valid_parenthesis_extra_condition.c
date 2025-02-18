#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hashmap{
    char ch;
    int value;
};

struct Stack{
    char *data;
    int top;
    int capacity;
};

struct Stack *stack;
struct hashmap map[6];
int map_size = 0;

int map_search(char ch){
    for(int i=0;i<map_size;i++){
        if(map[i].ch == ch) return i;
    }
    return -1;
}

void insert_map(char ch){
    int index = map_search(ch);
    if(index == -1){
        map[map_size].ch = ch;
        map[map_size].value = 1;
        map_size++;
    }
    else{
        map[index].value++;
    }
}

void initialise_stack(){
    stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = 100;
    stack->data = (char*) malloc(stack->capacity * sizeof(char));
}

int is_empty(){
    return stack->top == -1;
}

int is_full(){
    return stack->top == stack->capacity-1;
}

void push(char ch){
    if(is_full()) return;

    stack->top++;
    stack->data[stack->top] = ch;
}

void pop(){
    if(is_empty()) return;
    stack->top--;
}

int is_valid_parenthesis(char* input){
    for(int i=0;i<strlen(input);i++){
        if(input[i] == '(' || input[i] == '{' || input[i] == '['){
            push(input[i]);
            insert_map(input[i]);
        }
        else  if(input[i] == ')'){
            insert_map(input[i]);
            if(is_empty() || stack->data[stack->top] != '(') return 0;
            else pop();
        }
        else  if(input[i] == '}'){
            insert_map(input[i]);
            if(is_empty() || stack->data[stack->top] != '{') return 0;
            else pop();
        }
        else  if(input[i] == ']'){
            insert_map(input[i]);
            if(is_empty() || stack->data[stack->top] != '[') return 0;
            else pop();
        }
    }
    if(is_empty()) return 1;
    return 0;
}

int main(){
    initialise_stack();
    char* input = (char*) malloc(100* sizeof(char));
    scanf("%s", input);

    int is_valid = is_valid_parenthesis(input);
    if(is_valid) printf("true\n");
    else printf("false\n");

    for(int i =0 ;i<map_size;i++){
        printf("%c : %d\n", map[i].ch, map[i].value);
    }

    return 0;
}