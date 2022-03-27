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

void bfs_level_wise(struct Node* root){
    queue<struct Node*> q;
    q.push(root);

    int i = 0;
    while(q.size() != 0){
        int len = q.size();

        cout<<"Level - "<<i<<": ";
        while(len > 0){
            len -= 1;

            struct Node* node= q.front();
            q.pop();

            cout<<node->val<<" ";

            if(node->left != NULL)
                q.push(node->left);

            if(node->right != NULL)
                q.push(node->right);
        }
        i++;
        cout<<endl;
    }
}

int main(){
    struct Node* root = create_binary_tree();

    cout<<"BFS Level wise Traversal"<<endl;
    bfs_level_wise(root);

    return 0;
}
