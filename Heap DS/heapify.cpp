#include<iostream>
#include<stdio.h>
using namespace std;

void heapify(int a[], int i, int n){
    int largest = i; // Here i is Parent Node
    int left_child_index = 2*i + 1;
    int right_child_index = 2*i + 2;

    if(left_child_index <= n-1 && a[left_child_index] > a[largest]){
        largest = left_child_index;
    }

    if(right_child_index <= n-1 && a[right_child_index] > a[largest]){
        largest = right_child_index;
    }

    if(largest != i){
        //perform swap
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        //recursively fix top-down nodes: O(log(n))
        heapify(a, largest, n);
    }
    for(int j = 0; j<7; j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

int main(){
    int heap_size = 7;
    int heap[heap_size] = {5, 2, 7, 9, 8, 12, 3};
    for(int i=(heap_size/2)-1; i>=0; i--){
        heapify(heap, i, heap_size);
    }
    return 0;
}
