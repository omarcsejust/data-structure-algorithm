#include<iostream>
#include<stdio.h>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void traverseLinkedList(struct Node *ptr){
    while(ptr != NULL){
        cout<<"Element: "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

/*Complexity: O(1)*/
struct Node *insertAtFirst(struct Node *head, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head; //Address of previous 1st Node assigned to as next node of current 1st Node
    head = new_node;

    return head;
};

/*Complexity: O(n)*/
bool insertAfterPosition(struct Node *start, int position, int data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    int counter = 1;
    bool is_added = false;
    while(start != NULL){
        if(counter == position){
            new_node->data = data;

            new_node->next = start->next;
            start->next = new_node;

            is_added = true;
            break;
        }
        start = start->next;
        counter++;
    }
    return is_added;
}

/*Complexity: O(n)*/
void insertAtEnd(struct Node *head, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    while(head->next != NULL){
        head = head->next;
    }

    head->next = new_node;
    new_node->data = data;
    new_node->next = NULL;
}

/*Suppose we are given a node from LinkedList, Complexity: O(1)*/
void insertAfterNode(struct Node *prev_node, int data){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int main(){
    struct Node *head, *first, *second, *third, *fourth;

    // Dynamically allocate memory for elements/nodes of Linked List inside Heap
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head = first;

    // Link first & second node
    first->data = 10;
    first->next = second;

    cout<<"Data in Head: "<<head->data<<", Data in 1st Node: "<<first->data<<", Addr in 1st Node: "<<first->next<<", Addr in Head:"<<head->next<<endl;
    cout<<"Addr of 2nd Node: "<<second<<endl;

    cout<<"Addr of 2nd Node: "<<&second->data<<endl;

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

    // Insert new node after first node
    insertAfterPosition(head, 2, 50);

    cout<<"After Inserting New Node"<<endl;
    traverseLinkedList(head);

    cout<<"Insert at First"<<endl;
    head = insertAtFirst(head, 60);
    traverseLinkedList(head);

    cout<<"Insert at End"<<endl;
    insertAtEnd(head, 70);
    traverseLinkedList(head);

    cout<<"Insert after a given Node"<<endl;
    insertAfterNode(third, 100);
    traverseLinkedList(head);

    return 0;
}
