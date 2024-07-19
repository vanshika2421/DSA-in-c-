#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
};

Node* NewNode(int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return (newNode);
}


bool isBalanced(Node* root){
    if(root == NULL){
         return true;
    }
    else{
        bool lefty = isBalanced(root -> left);
        bool righty = isBalanced(root -> right);
        bool diff = abs(height(root -> left) - height(root->right) <=1);
        
            // bool x = abs( h1 - h2 ) <= 1;
            if(diff && left && right){
                return true;
            }
            else{
                return false;
            }
    }
}
