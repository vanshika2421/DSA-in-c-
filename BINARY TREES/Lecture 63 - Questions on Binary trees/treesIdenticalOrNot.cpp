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

// 1 -> 2 -> 3

bool identical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
     else if(root1 == NULL && root2 != NULL){
        return false;
    }
    else if(root1 != NULL && root2 == NULL){
        return false;
    }
    else if(root1 && root2){
        if(root1 -> data == root2 -> data){
            return true;
            identical(root1-> left , root2 -> left);
        }
        else{
            return false;
        }
    }
}

