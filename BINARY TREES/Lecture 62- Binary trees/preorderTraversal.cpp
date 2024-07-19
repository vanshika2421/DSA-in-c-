
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){
    cout << " Enter the data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    // cout << " Expanding tree for roots ";
    cout << " Enter data for left side: " << data << endl;
    root -> left = buildTree(root->left);
    cout << " Enter data for right side: " << data << endl;
    root -> right = buildTree(root -> right); 
    return root;
}



void levelOrdertraversal(Node* root){
    queue<Node*> q;
    q.push(NULL);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        // cout << temp -> data << endl;
        q.pop();

        if(temp == NULL){ // iska mtlb hai k humne agr next level pr jana hai toh hume enter marna pdega and and we have to put one more NULL in queue
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout << temp -> data << endl;
        if(temp->left){
            q.push(temp -> left);
    }
    if(temp->right){
        q.push(temp -> right);
    }
        }
    }

    // return q;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    levelOrdertraversal(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
}




