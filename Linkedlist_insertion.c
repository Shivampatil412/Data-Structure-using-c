// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr) {
    while(ptr != NULL) {
        printf("Data:%d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtBeginning(struct Node *head,int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

//Case -2
struct Node * insertInBetween(struct Node *head,int data,int index) {
    
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    int i = 0;
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    
    return head;
    
}

//case-3
struct Node * insertAtEnd(struct Node *head,int data) {
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    
    return head;
}

//case-4
struct Node * insertAfterNode(struct Node *head,struct Node *prevnode,int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    
    return head;
}

int main() {
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;
    
    
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 7;
    head->next = second;
    
    
    second->data = 8;
    second->next = third;
    
    
    third->data = 9;
    third->next = forth;
    
    forth->data = 10;
    forth->next = NULL;
    
    traversal(head);
    
    printf("Insert at Beginning\n");
    head = insertAtBeginning(head,12);
    traversal(head);
    
    printf("------------Insert in Between----------------\n");
    head = insertInBetween(head,25,2);
    traversal(head);
    
    printf("------------Insert at end----------------\n");
    head = insertAtEnd(head,30);
    traversal(head);
    
    printf("------------Insert at end----------------\n");
    head = insertAfterNode(head,second,99);
    traversal(head);
    

    return 0;
}