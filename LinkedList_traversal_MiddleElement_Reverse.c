// LinkedList to print middle element, reverse list
#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

int count = 0;
void linkedListTraversal(struct node * ptr) {
    while(ptr != NULL){
        printf("Linked List traversal:%d\n ",ptr->data);
        ptr= ptr->next;
        count++;
    }
    printf("\n");
}

struct node * searchMiddle(struct node * ptr){
    //printf("count is :%d",count);
    struct node *current = ptr; 
    int middelPos = count/2;
    //printf("middelpos:%d \n",middelPos);
    current = ptr;
    
    for(int i=0; i<middelPos; i++){
        current = current->next;
    }
    printf("middle element: %d\n",current->data);
    printf("\n");
}

void printReverseList(struct node* ptr) {
    struct node* prev = NULL;
    struct node* current = ptr;
    struct node* next;
    
    
    while(current != NULL) {
         next = current->next;
         current->next =  prev;
         prev = current;
         current = next;
    }
    ptr = prev;
    printf("Reversed LinkedList: ");
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr= ptr->next;
    }
}


int main() {
    
    struct node * head;
    head = (struct node * )malloc(sizeof(struct node));
    
    struct node * second;
    second = (struct node *)malloc(sizeof(struct node));
    
    struct node * third;
    third = (struct node *)malloc(sizeof(struct node));
    
    struct node * forth;
    forth = (struct node *)malloc(sizeof(struct node));
    
    struct node * fifth;
    fifth = (struct node *)malloc(sizeof(struct node));
    
    struct node * sixth;
    sixth = (struct node *)malloc(sizeof(struct node));
    
    struct node * seventh;
    seventh = (struct node *)malloc(sizeof(struct node));
    
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = forth;
    
    forth->data = 4;
    forth->next = fifth;
    
    fifth->data = 5;
    fifth->next = sixth;
    
    sixth->data = 6;
    sixth->next = seventh;
    
    seventh->data = 7;
    seventh->next = NULL;
    
    linkedListTraversal(head);
    searchMiddle(head);
    printReverseList(head);
    
}


/* OUTPUT:
Linked List traversal: 1
Linked List traversal: 2
Linked List traversal: 3
Linked List traversal: 4
Linked List traversal: 5
Linked List traversal: 6
Linked List traversal: 7
 
middle element: 4

Reversed LinkedList: 7 6 5 4 3 2 1 

*/