#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int id;
    char severity[10];
    struct node* next;
};
struct node *head = NULL, *tail = NULL;

struct node * create_node(int id, char *severity){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->id = id;
    strcpy(newnode->severity, severity);
    newnode->next = NULL;
    return newnode;
}

void insert(int id, char *severity){
    struct node* newnode = create_node(id, severity);
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = tail->next;
    }
}

void display(){
    struct node* cur_node = head;
    printf("Output:\n");
    while(cur_node != NULL){
        printf("%d %s\n", cur_node->id, cur_node->severity);
        cur_node = cur_node->next;
    }
}
int get_priority(const char *severity) {
    if (strcmp(severity, "Critical") == 0) return 1;
    if (strcmp(severity, "Serious") == 0)  return 2;
    if (strcmp(severity, "Stable") == 0)   return 3;
    return 4; 
}

void sort_severity(){
    if(head == NULL) return;

    struct node *j;
    char temp_severity[10] = {'\0'};
    int swapped, temp_id;

    do{
        swapped = 0;
        for(j = head;j != NULL && j->next != NULL;j = j->next){
            if(get_priority(j->severity) > get_priority(j->next->severity)){
                temp_id = j->id;
                j->id = j->next->id;
                j->next->id = temp_id;
                
                strcpy(temp_severity, j->severity);
                strcpy(j->severity, j->next->severity);
                strcpy(j->next->severity, temp_severity);

                swapped = 1;
            }
        }
    }while(swapped);
}

int main(){
    int id;
    char severity[10]={'\0'};

    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d %9s", &id, severity);
        insert(id, severity);
    }

    sort_severity();

    display();

    return 0;
} 