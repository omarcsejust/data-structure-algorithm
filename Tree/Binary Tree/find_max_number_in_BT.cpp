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

int find_max_element(Node* root){
    if(root == NULL){
        return -1;
    }

    int root_data = root->data;
    int left_data = find_max_element(root->left);
    //cout<<root->data<<" ";
    int right_data = find_max_element(root->right);

    if(root_data < left_data){
        root_data = left_data;
    }

    if(root_data < right_data){
        root_data = right_data;
    }

    return root_data;
}

int main(){
    Node *root = create_tree();

    int max_data = find_max_element(root);
    cout<<"Max Number: "<<max_data;
    return 0;
}
