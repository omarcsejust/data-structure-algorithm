#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int val;
    struct Node *left, *right;
};

struct Node* build_BT(){
    int val;
    cout<<"Input Node val: ";
    cin>>val;
    if(val == -1)
        return NULL;

    struct Node *node = (Node*)(malloc(sizeof(Node)));
    node->val = val;

    cout<<"Left of "<<val<<": ";
    node->left = build_BT();

    cout<<"Right of "<<val<<": ";
    node->right = build_BT();

    return node;
}

int dfs_preorder(struct Node* root){
    if(root == NULL)
        return 0;

    cout<<root->val<<" ";
    dfs_preorder(root->left);
    dfs_preorder(root->right);
}

int dfs_inorder(struct Node* root){
    if(root == NULL)
        return 0;

    dfs_inorder(root->left);
    cout<<root->val<<" ";
    dfs_inorder(root->right);
}

int bfs(struct Node* root){
    queue<struct Node*> q;
    q.push(root);

    while(q.size() > 0){
        struct Node *node = q.front();
        q.pop();
        cout<<node->val<<" ";
        if(node->left != NULL)
            q.push(node->left);

        if(node->right != NULL)
            q.push(node->right);
    }
    return 0;
}

int main(){
    struct Node *root = build_BT();
    dfs_preorder(root);
    cout<<endl;
    dfs_inorder(root);

    cout<<"BFS"<<endl;
    bfs(root);
    return 0;
}
