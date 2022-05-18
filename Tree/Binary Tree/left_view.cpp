#include<iostream>
#include<queue>
#include<vector>
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

vector<int> get_left_view(vector<int> res, struct Node *root, int level){
    if(root == NULL){
        return res;
    }

    if(res.size() <= level)
        res.push_back(root->val);

    res = get_left_view(res, root->left, level + 1);
    res = get_left_view(res, root->right, level + 1);

    return res;
}

int main(){
    struct Node *root = build_BT();
    vector<int> r;
    vector<int> res = get_left_view(r, root, 0);
    for(int r: res){
        cout<<r<<" ";
    }
    return 0;
}
