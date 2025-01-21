#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
} *head = NULL, *newnode;

int is_empty_list(){
    if(head == NULL){
        printf("\nEmpty list.");
        return 1;
    }
    return 0;
}

void free_linked_list(){
    struct node* cur_node = head;
    struct node* next_node;

    while(cur_node != NULL){
        next_node = cur_node->next;
        free(cur_node);
        cur_node = next_node;
    }
}

void display() {
    if(is_empty_list()) return;

    struct node* cur_node = head;
    printf("\n");
    while (cur_node != NULL) {
        printf("%d ", cur_node->data);
        cur_node = cur_node->next;
    }
    printf("\n");
}

int get_length() {
    int count = 0;
    struct node* cur_node = head;
    while (cur_node != NULL) {
        count++;
        cur_node = cur_node->next;
    }
    return count;
}

void create_newnode(int value) {
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) return;

    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
}

void insert_at_begin(int value) {
    create_newnode(value);

    newnode->next = head;
    if(head != NULL){
        head->prev = newnode;
    }
    head = newnode;
    display();
}

void insert_at_last(int value) {
    if(head == NULL){
        insert_at_begin(value);
        return;
    }

    struct node* cur_node = head;

    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }

    create_newnode(value);
    cur_node->next = newnode;
    newnode->prev = cur_node;
    display();
}

void insert_at_position(int value, int pos) {
    if(pos < 1){
        printf("\nInvalid Position.\n");
        return;
    }
    
    if(pos == 1){
        insert_at_begin(value);
        return;
    }

    struct node* cur_node = head;
    for (int i = 1; i < pos-1; i++) {
        cur_node = cur_node->next;
        if (cur_node == NULL) {
            printf("\nPosition not found.\n");
            return;
        }
    }

    create_newnode(value);
    newnode->next = cur_node->next;
    newnode->prev = cur_node;
    if(newnode->next != NULL){
        newnode->next->prev = newnode;
    }
    cur_node->next = newnode;
    display();
}

void insert_at_middle(int value) {
    int length = get_length();
    int middle_pos = (length / 2) + 1;

    insert_at_position(value, middle_pos);
}

int main() {
    int value, choice, pos;

    while (1) {
        printf("\n\n---MENU---");
        printf("\n1. Insert at begin");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Insert at middle");
        printf("\n5. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &value);
                insert_at_begin(value);
                break;

            case 2:
                printf("\nEnter value: ");
                scanf("%d", &value);
                insert_at_last(value);
                break;

            case 3:
                printf("\nEnter position: ");
                scanf("%d", &pos);
                if(pos != 1 && head == NULL) {
                    printf("\nInvalid position.\n");
                    break;
                }
                printf("Enter value: ");
                scanf("%d", &value);
                insert_at_position(value, pos);
                break;

            case 4: if(is_empty_list()) break;
                printf("\nEnter value: ");
                scanf("%d", &value);
                insert_at_middle(value);
                break;

            case 5:
                free_linked_list();
                exit(0);

            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    free_linked_list();
    return 0;
}
