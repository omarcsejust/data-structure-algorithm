#include<iostream>
#include<stdio.h>

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void addNodeToBST(struct Node *ptr, int data){
    struct Node new_node = (struct Node *)malloc(sizeof(struct Node));

    if(data >= ptr->data){
        //left
        ptr = ptr->left;
    }else{
        //right
        ptr = ptr->right;
    }
}

int main(){
    struct Node *root = NULL;
    struct Node *node1, *node2;

    root = (struct Node *)malloc(sizeof(struct Node));
    node1 = (struct Node *)malloc(sizeof(struct Node));
    node2 = (struct Node *)malloc(sizeof(struct Node));



    return 0;
}
