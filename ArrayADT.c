#include<stdio.h>
#include<stdlib.h>

struct myArray {
    int tot_size;
    int used_size;
    int *ptr;
};

void createArray (struct myArray *a, int tsize, int usize) {
    a->tot_size = tsize;
    a->used_size = usize;
    a->ptr = (int*)malloc(tsize*(sizeof(int)));
}

void setVal(struct myArray *a) {
    int n;
    for (int i = 0; i < a->used_size; i++) {
        printf("Enter Element %d:",i);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
    
}

void showArray(struct myArray *a) {
    for (int i = 0; i < a->used_size; i++) {
        printf("%d\n",(a->ptr)[i]);
    }
    
}



int main() {

    struct myArray marks;
    printf("We are going to create an array\n");
    createArray(&marks,10,3);

    printf("Now we are going to insert values in array\n");
    setVal(&marks);

    printf("Printing array:\n");
    showArray(&marks);


    return 0;
}
