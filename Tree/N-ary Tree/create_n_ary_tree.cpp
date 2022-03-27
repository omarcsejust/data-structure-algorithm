#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int val;
    vector<struct Node*> childs;
};

struct Node* create_n_ary_tree(){
    cout<<"Enter val: ";
    int val;
    cin>> val;
    if(val == -1)
        return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;

    cout<<"Enter child for "<<val<<": ";
    node->childs.push_back(node);
    create_n_ary_tree();

    return node;
};

int print_n_ary(struct Node *root){
    return 0;
}

int main(){
    create_n_ary_tree();
    return 0;
}
