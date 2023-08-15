
#include <stdio.h>


void display(int arr[],int size) {
    for(int i =0;i<size;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void indInsertion (int arr[], int size, int element, int capacity, int index) {
    if(size>=capacity) {
        printf("Insertion failure....array size full");
    }
    
    for(int i = size-1; i>=index;i--) { // will start from last index and shift values to right until we get required index. 
        arr[i+1] = arr[i];
    }
    arr[index] = element;
}

void insertionWithoutShifting (int arr[], int size, int element, int capacity, int index) {
    if(size>=capacity) {
        printf("Insertion failure....array size full");
    }
    
    for(int i =0;i<=index;i++) {
        if (arr[i] == arr[index]) {
            arr[size] = arr[i];
            arr[index] = element;
        }
    }
}

void inddeletion(int arr[],int size,int index) {
    if(size==0){
        printf("No elements to delete....deletion failed!!");
    }
    for(int i = index;i<size-1;i++) {
        arr[i] = arr[i+1];
    }
}

void deletionandshiftlast(int arr[],int size,int index) {
    if(size==0){
        printf("No elements to delete....deletion failed!!");
    }
    for(int i = index; i<size-1; i++) {
        if(i==index) {
            arr[i] = arr[size-1];
        }
    }
}

int main() {
    
   int arr[100] = {1,2,34,45,56,67};
   int size = 6, element = 23, index = 2;
   
   printf("--------------Insertion--------------------\n");
   printf("CASE-1:When Order Matters\n");
   printf("Displaying array before insertion:\n");
   display(arr,size);
   printf("Inserting at required index and shifting value at index towards right position\n");
   indInsertion(arr, size, element,100,index);
   size++;
   printf("Displaying array after insertion:\n");
   display(arr,size);
   printf("\n");

   printf("CASE-2:When Order doesn't Matters\n");
   printf("Displaying array before insertion:\n");
   display(arr,size);
   printf("Inserting at required index and shifting value at index to last position\n");
   int element1 = 55;
   insertionWithoutShifting(arr, size, element1,100,index);
   size++;
   printf("Displaying array after insertion:\n");
   display(arr,size);
   printf("\n");

   printf("--------------Deletion--------------------\n");
   printf("CASE-1:When Order Matters\n");
   printf("Displaying array before deletion:\n");
   display(arr,size);
   printf("Deleting at required index and shifting value at index towards left position.\n");
   inddeletion(arr, size,index);
   size--;
   printf("Displaying array after deletion:\n");
   display(arr,size);
   printf("\n");

   printf("CASE-2:When Order doesn't Matters\n");
   printf("Displaying array before deletion:\n");
   display(arr,size);
   printf("Deleting at required index and shifting value at last index to empty value index.\n");
   deletionandshiftlast(arr, size,index);
   size--;
   printf("Displaying array after deletion:\n");
   display(arr,size);
   printf("\n");


   return 0;
}

/*
--------------Insertion--------------------
CASE-1:When Order Matters
Displaying array before insertion:
1 2 34 45 56 67 
Inserting at required index and shifting value at index towards right position
Displaying array after insertion:
1 2 23 34 45 56 67 

CASE-2:When Order doesn't Matters
Displaying array before insertion:
1 2 23 34 45 56 67 
Inserting at required index and shifting value at index to last position
Displaying array after insertion:
1 2 55 34 45 56 67 23 

--------------Deletion--------------------
CASE-1:When Order Matters
Displaying array before deletion:
1 2 55 34 45 56 67 23 
Deleting at required index and shifting value at index towards left position.
Displaying array after deletion:
1 2 34 45 56 67 23 

CASE-2:When Order doesn't Matters
Displaying array before deletion:
1 2 34 45 56 67 23 
Deleting at required index and shifting value at last index to empty value index.
Displaying array after deletion:
1 2 23 45 56 67 
*/