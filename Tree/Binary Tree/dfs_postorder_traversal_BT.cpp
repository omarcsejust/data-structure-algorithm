#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* create_binary_tree(){
    int val;
    cout<<"Input root: ";
    cin>>val;

    if(val == -1)
        return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));

    // Left child of current root
    root->val = val;
    cout<<"Left of "<<val<<", ";
    root->left = create_binary_tree();

    // Right child of current root
    cout<<"Right of "<<val<<", ";
    root->right = create_binary_tree();

    return root;
}

int dfs_postorder_traversal(struct Node* root){
    if(root == NULL)
        return 0;
    dfs_postorder_traversal(root->left);
    dfs_postorder_traversal(root->right);
    cout<<root->val<<" ";

    return 0;
}

int main(){
    struct Node* root = create_binary_tree();
    cout<<"Postorder Traversal: ";
    dfs_postorder_traversal(root);

    return 0;
}
