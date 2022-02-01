#include<iostream>
#include<stdio.h>

using namespace std;

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverseForwardAndReverse(struct Node *ptr){
    bool is_next = true;
    struct Node *temp;
    while(ptr != NULL){
        cout<<"Element: "<<ptr->data<<endl;
        if(is_next == true){
            temp = ptr;
            ptr = ptr->next;
            if(ptr == NULL){
                is_next = false;
                ptr = temp;
                cout<<"Reverse Traversal of LL"<<endl;
                continue;
            }
        }

        if(is_next == false){
            ptr = ptr->prev;
        }
    }
}

// Case: 01
struct Node *insertAtFirst(struct Node *ptr, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = ptr;

    ptr->prev = new_node;

    ptr = new_node;

    return ptr;
}

// Case: 02 (index: start count from 0)
void insertAtGivenIndex(struct Node *ptr, int index, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    int counter = 0;

    while(ptr->next != NULL){  // Because we won't allow to insert at the end
        counter++;  // Because we won't allow to insert at index: 0, i.e: at the beginning
        if(counter == index){
            struct Node *previous_node = ptr->next;
            new_node->data = data;
            new_node->prev = ptr;
            new_node->next =  previous_node;

            // Reconstruct previous node's->[next address] and next node's->[previous address] of new_node
            ptr->next = new_node;
            previous_node->prev = new_node;
            break;
        }
        ptr = ptr->next;
    }
}

// Case: 03
void insertAtLast(struct Node *ptr, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    new_node->data = data;
    new_node->prev = ptr;
    new_node->next = NULL;

    // Reconstruct previous node's next node address
    ptr->next = new_node;
}

int main(){
    struct Node *head, *first, *second, *third;

    // Dynamically allocate memory for elements/nodes of Linked List inside Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head = first;

    first->data = 10;
    first->prev = NULL;
    first->next = second;

    second->data = 20;
    second->prev = first;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    cout<<second->next->prev<<"  "<<third->prev<<endl;

    traverseForwardAndReverse(head);

    // Insert at First
    /*cout<<"After Inserting at First"<<endl;
    head = insertAtFirst(head, 40);
    traverseForwardAndReverse(head);*/

    // Insert at Index
    cout<<"After Inserting at Index"<<endl;
    insertAtGivenIndex(head, 1, 50);
    traverseForwardAndReverse(head);

    // Insert at Index
    cout<<"After Inserting at Last"<<endl;
    insertAtLast(head, 60);
    traverseForwardAndReverse(head);

    return 0;
}
