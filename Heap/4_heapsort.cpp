// HEAP SORT:

#include<iostream>
#include<algorithm>

using namespace std;

// Assume it is already in heap form. Otherwise buildheap takes O(n) time and do that.

// Approach: Swap last element with root element & decrease size by 1 & heapify the root element.
// Repeat until size reduces to 1.


// Use 1-index array; Time complexity:O(nlogn)
void heapSort(int arr[], int n){

    int size=n;

    while(size>1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,n,1);
    } 
}

// Use 1-index array

void heapify(int arr[], int n, int index){
    int largest=index;
    
    int leftIndex=2*largest, rightIndex=2*largest+1;

    if(leftIndex<=n && arr[largest]<arr[leftIndex])
    largest=leftIndex;
    
    if(rightIndex<=n && arr[largest]< arr[rightIndex])
    largest=rightIndex;

    if(largest!=index){
        swap(arr[index], arr[largest]);
        heapify(arr,n,largest);
    }

}