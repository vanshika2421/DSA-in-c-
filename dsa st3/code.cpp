#include<iostream>
using namespace std;
 
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* newNode = new Node(data);
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
}

int height(Node* root, int data){
    if(root == NULL){
        return 0;
    }
    else{

        int leftHeight = height(root -> left, data);
        int rightHeight = height(root -> right, data);
        if(leftHeight){
            return leftHeight +1;
        }
        if(rightHeight){
            return rightHeight + 1;
        }
    }
    return ;
}

void printNodes(Node* root,int level){
    if(root == NULL){
        return;
    }

    if(level == 1){
        return root -> data;
    }

    if(level > 1){
        cout << root -> data << " ";
        printNodes(root -> left, level -1);
        printNodes(root -> right, level - 1);
    }
}

void reverse(Node* root,int level){
    int h = height(root);
    if(root == NULL){
        cout << " invalid argument" << endl;
    }
    for(int i = h; i >= 1; i--){
        printNodes(level,i);
    }
}

void buildTree(Node* root, int level){
    int h = height(root);
    if(root == NULL){
        cout << "invalid arguments"<< endl;
    }
    for(int i = 0; i <=h; i++){
        printNodes(level,i);  
    }
}

void inorder(Node* root, int data){
    if(root == NULL){
        return;
    }
    inorder(root -> left, data);
    cout << root -> data << " ";
    inorder(root -> right, data);
}

int calculatingNoOfLeafNodes(Node* root, int count){
    if(root == NULL){
        return 0;
    }
    inorder(root -> left , count);
    if(root -> left == NULL && root -> right == NULL){
        count++;
    }
    inorder(root -> right, count);
}

Node* inserting in 








