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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    // root = NewNode(data);
    q.push(NULL);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        cout << temp-> data << " ";
        if(temp-> left){
            q.push(temp-> left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }
    }
}

Node* insert(Node* root, int value){
    if(root == NULL){
        return root = NewNode(value);
    }
    if(value > root -> data){
        root -> right = insert(root -> right, value);
    }
    else{
        root -> left = insert(root -> left, value);
    }
    return root;

}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insert(root,data);
        cin >> data;
    }
}

int main(){
    Node* root = NULL;
   cout << "sb shi h " << endl;
    // root = insert(root, 1000);
    // root = insert(root, 200);
    // root = insert(root , 3);
    // root = insert(root , 6);
    // root = insert(root, 5);
    // root = insert(root, 100);
    // root = insert(root, 400);
cout << "sb shi h " << endl;
    takeInput(root);
    cout << "sb shi h " << endl;
    levelOrderTraversal(root);
}