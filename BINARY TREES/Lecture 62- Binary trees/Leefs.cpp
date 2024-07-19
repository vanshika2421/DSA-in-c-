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

void inorder(Node* root , vector<int>& leafNodes){
    //base case
    // vector<int> arr;
    if(root == NULL){
        return ;
    }
    inorder(root -> left, leafNodes);
    if(root -> left -> data == -1 && root -> right -> data == -1){
        leafNodes.push_back(root -> data);
    }
    inorder(root -> right, leafNodes);
    // cout << root -> data << endl
    // return arr;
}

vector<int> Findleafnodes(node* root){
    vector<int> leafNodes;
    inorder(root, leafNodes);
    return leafNodes;
}

int main(){

    Node* root = NewNode(1);
    root -> left = NewNode(2);
    root -> right = NewNode(3);
    root -> left -> left = NewNode(4);
    root -> left -> right = NewNode(5);
    root->right-> left = NewNode(6);
    cout << "building tree: " ;
    buildTree(root);
    cout << endl;
        vector<int> leafNodes = Findleafnodes(root);
        cout << "Leaf nodes of the BST: ";
    for (int node : leafNodes) {
        cout << node << " ";
    }
    cout << endl;
    cout << "-----------------------" << endl;
    // cout << "Reversing tree : " ;
    // reverse(root); cout << endl;
    // cout << "-----------------------" << endl;
    cout << "Inorder trvaersal tree : ";
    // inorder(root); cout << endl;
    
    // cout << "preorder trvaersal tree : ";
    // preOrder(root); cout << endl;
    // cout << "postorder trvaersal tree : ";
    // postorder(root); cout << endl;
    // cout << "-----------------------" << endl;
    // // buildFromLevelOrder(root);
    // // printGivenNodes(root,3);
    //  cout << "-----------------------" << endl;
    //  cout << " Longest diameter : " << " ";
    // cout << diameter(root);

}

