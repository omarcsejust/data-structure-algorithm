#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* create_tree(){
    Node *node = (Node*)malloc(sizeof(Node));
    int data;
    cout<<"Enter node data:";
    cin>>data;
    if(data == -1) return NULL;
    node->data = data;

    cout<<"Enter left for "<<data<<", ";
    node->left = create_tree();

    cout<<"Enter right for "<<data<<", ";
    node->right = create_tree();

    return node;
}

int main(){
    create_tree();
    return 0;
}
