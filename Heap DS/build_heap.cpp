#include<iostream>
#include<stdio.h>
#include <cmath>

using namespace std;

void build_max_heap(int a[], int i){
    // Here i is the last element of lowest level
    if(i > 0){
        // going bottom-to-up, until we reach to parent node i.e: 0
        int parent = (i-1)/2;  // reach child node to parent
        int left = 2*parent + 1;  // parent to left child element index
        int right = 2*parent + 2;  // parent to right child element index

        int largest = parent;

        if(left <= i && a[left] > a[largest]){
            largest = left;
        }

        if(right <= i && a[right] > a[largest]){
            largest = right;
        }

        if(parent != largest){
            //swap
            int temp = a[parent];
            a[parent] = a[largest];
            a[largest] = temp;

            build_max_heap(a, parent);
        }
    }
    for(int m=0; m<=i; m++){
        cout<<a[m]<<" ";
    }
    cout<<endl;
}

int main(){
    int heap_size = 6;
    int heap[] = {10, 5, 2, 3, 20, 1};
    int max_heap[heap_size];
    for(int i=0; i<heap_size; i++){
        max_heap[i] = heap[i];
        build_max_heap(max_heap, i);
    }
    return 0;
}
