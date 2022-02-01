#include<iostream>
#include<stdio.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void traverseLinkedList(struct Node *ptr){
    while(ptr != NULL){
        cout<<"Element: "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

void deleteAtIndex(struct Node *ptr, int index){
    int counter = 0;
    while(ptr->next != NULL){
        counter++;
        if(counter == index){
            struct Node *deleted = ptr->next;
            struct Node *previous = ptr;
            struct Node *next = deleted->next;

            // Linking Nodes
            previous->next = next;

            // Free memory
            free(deleted);
        }
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head, *first, *second, *third, *fourth;

    // Dynamically allocate memory for elements/nodes of Linked List inside Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head = first;

    // Link first & second node
    first->data = 10;
    first->next = second;

    // Link second & third node
    second->data = 20;
    second->next = third;

    // Link third & fourth node
    third->data = 30;
    third->next = fourth;

    // Terminate the list
    fourth->data = 40;
    fourth->next = NULL;

    traverseLinkedList(head);

    cout<<"Delete at index"<<endl;
    deleteAtIndex(head, 2);
    traverseLinkedList(head);

    return 0;
}
