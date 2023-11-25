// Find the kth smallest element in an array.

#include<bits/stdc++.h>
using namespace std;


// Using priority queue

int kthSmallest(int arr[], int N, int K)
{
    // Create a max heap (priority queue)
    priority_queue<int> pq;
 
    // Iterate through the array elements
    for (int i = 0; i < N; i++) {
        // Push the current element onto the max heap
        pq.push(arr[i]);
 
        // If the size of the max heap exceeds K, remove the largest element
        if (pq.size() > K)
            pq.pop();
    }
 
    // Return the Kth smallest element (top of the max heap)
    return pq.top();
}


// ---------------------------------------------------------------------------------------------------
// Using QuickSelect method.
// [link](https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/)

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
 
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int K)
{
    // If k is smaller than number of elements in array
    if (K > 0 && K <= r - l + 1) {
 
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, l, r);
 
        // If position is same as k
        if (pos - l == K - 1)
            return arr[pos];
        if (pos - l > K - 1) // If position is more, recur
                             // for left subarray
            return kthSmallest(arr, l, pos - 1, K);
 
        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r,
                           K - pos + l - 1);
    }
 
    // If k is more than number of elements in array
    return INT_MAX;
}

// ---------------------------------------------------------------------------------------------------
// Using Count Sort

int kthSmallest(int arr[], int n, int k) {
    // First, find the maximum element in the array
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
 
    // Create an array to store the frequency of each 
   // element in the input array
    int freq[max_element + 1] = {0};
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
 
    // Keep track of the cumulative frequency of elements 
   // in the input array
    int count = 0;
    for (int i = 0; i <= max_element; i++) {
        if (freq[i] != 0) {
            count += freq[i];
            if (count >= k) {
                // If we have seen k or more elements, 
              // return the current element
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    priority_queue<int> p;
    p.push(5);
    p.push(3);
    p.push(4);
    p.push(1);
    while(p.size()){
        cout<<p.top()<<' ';
        p.pop();
    }
    
    return 0;
}