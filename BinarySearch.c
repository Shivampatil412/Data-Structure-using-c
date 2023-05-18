// Online C compiler to run C program online
#include <stdio.h>

int binarySearch(int arr[], int size, int element) {
    int low,mid,high;
    low = 0;
    high = size-1;
    
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2,5,12,23,45,67,78,123};
    int size = sizeof(arr)/sizeof(int);
    int element = 23;
    int searchIndex = binarySearch(arr, size,element);
    printf("element found at: %d",searchIndex);

    return 0;
}