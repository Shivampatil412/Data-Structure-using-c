#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
struct Node * deleteFirst(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
struct Node *deleteAtIndex(struct Node *head, int index) {
    struct Node * p = head;
    struct Node * q =  head->next;
    
    for(int i =0; i<index-1;i++) {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
struct Node *deleteAtLast(struct Node *head) {
    struct Node * p = head;
    struct Node * q =  head->next;
    
    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}


// Case 4: Deleting the element with a given value from the linked list
struct Node *deleteAtValue(struct Node *head, int value) {
    struct Node * p = head;
    struct Node * q =  head->next;
    
    while(p->data !=value && q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value) {
      p->next = q->next;
      free(q);
    }
    
    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Link fourth and fifth nodes
    fourth->data = 8;
    fourth->next = fifth;
    
    // Link fifth and sixth nodes
    fifth->data = 6;
    fifth->next = sixth;
    
    // Terminate the list at the third node
    sixth->data = 1;
    sixth->next = NULL;
    
    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    printf("-----------------Deleting First Node----------------\n");
    head = deleteFirst(head);
    linkedListTraversal(head);
    
    printf("-----------------Deleting Node at given Index----------------\n");
    head = deleteAtIndex(head, 3);
    linkedListTraversal(head);
    
    printf("-----------------Deleting Node at Last----------------\n");
    head = deleteAtLast(head);
    linkedListTraversal(head);
    
    printf("-------Deleting the element with a given value from the linked list--------\n");
    head = deleteAtValue(head, 8);
    linkedListTraversal(head);
    
    
    return 0;
}