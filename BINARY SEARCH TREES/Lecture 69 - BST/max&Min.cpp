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

int min(Node* root){
  Node* temp =  root;
  while(temp -> left != NULL) {
    temp = temp -> left;
  }
  return temp -> data;
}

