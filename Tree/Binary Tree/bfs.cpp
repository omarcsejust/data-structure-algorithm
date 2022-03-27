#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node *create_binary_tree(){
    int val;
    cout<<"Enter node value: ";
    cin>>val;

    if(val == -1){
        return NULL;
    }

    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;

    // build left subtree
    cout<<"Enter left of "<<val<<", ";
    node->left = create_binary_tree();

    // build right subtree
    cout<<"Enter right of "<<val<<", ";
    node->right = create_binary_tree();

    return node;
};

int find_max_node(struct Node *root){
    if(root == NULL)
        return -999999;

    int l_max = find_max_node(root->left);
    int r_max = find_max_node(root->right);

    if(l_max < root->val){
        l_max = root->val;
    }
    if(r_max < root->val){
        r_max = root->val;
    }

    if(l_max > r_max)
        return l_max;

    return r_max;
}

int bfs(struct Node *root){
    queue<struct Node*> nodes;
    nodes.push(root);

    struct Node *cur_node;
    while(!nodes.empty()){
        cur_node = nodes.front();
        nodes.pop();

        cout<<cur_node->val<<" ";

        if(cur_node->left != NULL)
            nodes.push(cur_node->left);

        if(cur_node->right != NULL)
            nodes.push(cur_node->right);
    }

    return 0;
}

int main(){
    // Building Binary Tree
    struct Node *root = create_binary_tree();

    // Finding the MAX element in BInary Tree
    int max_val = find_max_node(root);
    cout<<"Max Val: "<<max_val<<endl;

    // BFS traversal in BInary Tree
    cout<<"BFS Traversal: ";
    bfs(root);

    return 0;
}
