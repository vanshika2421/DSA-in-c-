#include<iostream>
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

// fiing height of tree
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int leftHeight = height(root -> left);
        int rightHeight = height(root-> right);

        if(leftHeight > rightHeight){
            return leftHeight + 1;
        }
        else{
            return rightHeight + 1;
        }
    }
}

void printGivenNodes(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data;
    }
    else if(level > 1){
        printGivenNodes(root-> left, level-1);
        printGivenNodes(root -> right, level -1);
    }
}

void reverse(Node* root){
    int h = height(root);
    cout << h << endl;
    int i;
    for(i = h; i >=1 ; i--){
        cout << endl;
        printGivenNodes(root,i);
    }
}

void buildTree(Node* root){
    int h = height(root);
    int i;
    for(i = 1; i <=h; i++){
        cout << endl;
        printGivenNodes(root,i);
    }
}

int main(){

    Node* root = NewNode(1);
    root -> left = NewNode(2);
    root -> right = NewNode(3);
    root -> left -> left = NewNode(4);
    root -> left -> right = NewNode(5);
    root->right-> left = NewNode(6);
    cout << "building tree: ";
    buildTree(root);
    cout << endl << endl;


    cout << "Reversing tree : " ;
    reverse(root);
}


