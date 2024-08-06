#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int d){
    Node* newnode = new Node(d);
    newnode -> data = d;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newNode(d);
}

Node* insert(Node* root, int d){
    Node* neww = newNode(d);
    if(root == NULL){
        return insert(root,d);
    }
    else if(d > root -> data){
      root ->right = insert(root -> right, d);
    }
    else if( d < root -> data){
        root -> left = insert(root -> left, d);
    }
}



int height(Node* root,int d){
    if(root == NULL){
        return 0;
    }
    int leftheight = height(root-> left, d);
    int rightHeight = height(root -> right, d);
    if(root -> left){
        return leftheight+1;
    }
    if(root -> right){
        return rightHeight + 1 ;
    }
    return root;
}

int printTree(Node* root, int level){
    if(level == 0){
        return;
    }
    if(level == 1){
        return root -> data;
    }
    if(level > 1){
        printTree(root -> left, level -1);
        printTree(root-> right, level -1);
    }
    return root -> data;
}

Node* buildTree(Node* root,int d){
    int h = height()
}


Node* inorder(Node* root, int d){
    if(root == NULL){
        return;
    }
    inorder(root -> left, d);
    cout << root -> data << " ";
    inorder(root -> right, d);
}

bool searchInBST(Node* root, int d, int value){
    if(root == NULL){
        return false;
    }
    if(root -> data== value){
        return true;
    }
    
    if(root -> data < value ){
        return searchInBST(root -> left, d , value);
    }
    else if(root -> data > val ue ){
        return searchInBST(root -> right, d , value);
    }
}

void delete





















int main(){


}