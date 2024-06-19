#include <iostream>
#include <algorithm>//sort
#include <queue> //priority queue
#include <unordered_set>
#include <limits.h>

// Reverse the array: Time: O(N); Space O(1)
using namespace std;

void reverseArray(int arr[],int n){

    int start=0, end=n-1;

    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}


// Maximum and minimum of an array using minimum number of comparisons

// Use either tournament method or count in pairs

// Linear Search: Comparisions: Worst Case: 1+2(n-2), Best Case:1+(n-2)






// Kth smallest(Largest) element in unsorted array(Assume all elements are distinct)

// Approach:

// 1)Sort the array and find kth element: Time:O(nlogn), Space Complexity:O(1)

// 2)Min Heap: Time:O(N+KlogN), Space:O(N) (Use priority queue)

// Max-Heap can be used to find the kth smallest element, by inserting first K elements into Max-Heap and then compare remaining elements with the root of the Max-Heap and if the element is less than the root then remove the root and insert this element into the heap and finally return root of the Max-Heap
// Time:(KLogK+(N-k)logN) Space:O(K) (Use priority queue)

// 3)Set data structure: It can be used to find the kth smallest element as it stores the distinct elements in sorted order. Set can be used because it is mentioned in the question that all the elements in the array are distinct. Time:(KLogN) Space:O(N)

int kthSmallest(int arr[], int N, int K){
    // Sort the given array
    sort(arr, arr + N);// sort(arr.begin(),arr.end()); if arr is a vector
 
    // Return k'th element in the sorted array
    return arr[K - 1];
}

int kSmallestElement(int arr[],int n,int k){

    // STL Priority Queue is the implementation of Heap Data Structure.
    //Top element is always the greatest by default
    priority_queue<int,vector<int>,greater<int>> pq; //Min Heap

    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    int ans,i=1;

    while(!pq.empty()){

        if(i==k){
            ans=pq.top();
            break;
        }
        pq.pop();
        i++;
    }

    return ans;
}

// Using QuickSort algo:

// QuickSelect ALGO: Time:O(N2) in worst case and O(N) on average; Space:O(1)

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int l,int r){
    int pivot=arr[r],i=l;

    for(int j=l;j<=r-1;j++){
        if(arr[j]<=pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }

    swap(&arr[i],&arr[r]);
    return i;
}

int kthSmallest(int arr[],int l,int r,int k){

     // If k is smaller than number of elements in array
    if(k>0 && k<=(r-l)+1){

        int pos=partition(arr,l,r);

        if(pos-l==k-1){
            return arr[pos];
        }
        else if(pos-l> (k-1)){
            return kthSmallest(arr,l,pos-1,k);
        }
        else{
            return kthSmallest(arr,pos+1,r, k-pos+l-1);
        }

    }

     // If k is more than number of elements in array
    return INT_MAX;
}

// Array consists of 0, 1 and 2. Sort the arrays: Time:O(N), Space:O(1)


//  takes 2 for loops to find the answer
void sort012(int arr[], int n)
    {
        // code here 
        int x=0,y=0,z=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0)
            x++;
            else if(arr[i]==1)
            y++;
            else if(arr[i]==2)
            z++;
        }
        
        for(int i=0;i<x;i++){
            arr[i]=0;
        }
        
        for(int i=x;i<x+y;i++){
            arr[i]=1;
        }
        
        for(int i=x+y;i<x+y+z;i++){
            arr[i]=2;
        }
        
}

//  takes 2 for loops to find the answer- Dutch National Flag Problem

void swap(int* a,int* b){
        int temp=*a;
        *a=*b;
        *b=temp;

    }
    
void sort_012(int arr[], int n){
    // code here 
    
    int low=0,mid=0,high=n-1;
    
    while(mid<=high){
        if(arr[mid]==0){
            swap(&arr[low],&arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(&arr[mid],&arr[high]);
            high--;
        }
    }
}
    


// Move all the negative elements to the one side of the array
// Order of element is NOT important

// Time:O(N) Space:O(1) 

// Parttion of Quick sort algo

void rearrange(int arr[], int n){
    int low=0;

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            swap(&arr[i],&arr[low]);
            low++;
        }
    }
}

// Using Dutch National Flag Algorithm.
void reArrange(int arr[],int n){
      int low =0,high = n-1;
      while(low<high){
      if(arr[low]<0){
          low++;
      }else if(arr[high]>0){
          high--;
      }else{
        swap(arr[low],arr[high]);
      }
    }
}


// Union and Intersection of 2 unsorted orders.
// Time:O(nlogn+mlogm), Space:O(m+n)

int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set<int> us;
        
        for(int i=0;i<n;i++){
            us.insert(a[i]);
        }
        
        for(int i=0;i<m;i++){
            us.insert(b[i]);
        }
        
        return us.size();
}

// Sorted arrays
//Time:O(m+n), Space:O(1)

int doUnionSorted(int a[], int n, int b[], int m){
        //code here
        int i=0,j=0;

        while(i<n && j<m){
            if(a[i]==b[j]){
                cout<<a[i];
                i++;
                j++;
            }
            else if(a[i]<b[j]){
                cout<<a[i];
                i++;
            } 
            else{
                cout<<b[j];
                j++;
            }
        }

        while(i<n){
            cout<<a[i++];
        }

        while(j<m){
            cout<<b[j++];

        }
}


// Cyclically rotate an array by one: Time-O(N), Space:O(1) (Clockwise direction)

void rotate(int arr[], int n)
{
    int temp=arr[n-1];

    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];

    }
    arr[0]=temp;
    
    
}

// Cyclically rotate an array by k: Time-O(N), Space:O(1) (Clockwise direction)

// 1)Using cyclic replacements
// 2)Using Reverse



