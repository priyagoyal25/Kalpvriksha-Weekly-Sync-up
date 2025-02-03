#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *stack1, *stack2, *s, *t;
int top1 = -1, top2 = -1;

void push(char* stack, char c, int *top){
    if(*top >= 199) return;

    (*top)++;
    stack[*top] = c;
}

void pop(int *top){
    if(*top == -1) return;
    (*top)--;
}

int main(){
    stack1 = (char *) malloc(sizeof(char) * 200);
    stack2 = (char *) malloc(sizeof(char) * 200);
    s = (char*)malloc(sizeof(char)*200);
    t = (char*)malloc(sizeof(char)*200);
    scanf("%s", s);
    scanf("%s", t);

    for(int i=0;i<strlen(s);i++){
        if(s[i] == '#'){
            pop(&top1);
        }
        else{
            push(stack1, s[i], &top1);
        }
    }

    for(int i=0;i<strlen(t);i++){
        if(t[i] == '#'){
            pop(&top2);
        }
        else{
            push(stack2, t[i], &top2);
        } 
    }

    if(top1 != top2){
        printf("false");
        return 0;
    }

    while(top1 >= 0){
        if(stack1[top1] != stack2[top2]){
            printf("false");
            return 0;
        }
        top1--;
        top2--;
    }

    printf("true");
    return 0;
} 