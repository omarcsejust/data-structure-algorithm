#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node *left;
    struct Node *right;
};

Node *create_binary_tree(){
    int val;
    cout<<"Input val:";
    cin>>val;

    if(val == -1)
        return NULL;

    Node *root = (Node*)malloc(sizeof(Node));
    root->val = val;

    cout<<"Enter left for "<<val<<" :";
    root->left = create_binary_tree();

    cout<<"Enter right for "<<val<<" :";
    root->right = create_binary_tree();


    return root;
}

int inorder_traversal_bt(Node *root){
    if(root == NULL)
        return NULL;

    inorder_traversal_bt(root->left);
    cout<<root->val<<" ";
    inorder_traversal_bt(root->right);
}

int main(){
    Node *root = create_binary_tree();
    cout<<"Inorder Traversal: ";
    inorder_traversal_bt(root);
    return 0;
}
