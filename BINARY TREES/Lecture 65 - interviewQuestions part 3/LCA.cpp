#include<iostream>
using namespace std;


class node {
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this -> data = data;
        this -> right  = NULL;
        this -> left = NULL;
    }
    
};

node* newNode(int data){
    node* neww = new node( data);
    return neww;
}

node* lca(node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root -> data == n1 || root -> data == n2){
        return root;
    }
    node* leftAns = lca(root -> left, n1,n2);
    node* rightAns = lca(root -> right, n1, n2);

    if(root -> right != NULL && root -> left != NULL){
        return root;
    }
    else if(root -> left != NULL && root -> right == NULL){
        return leftAns;
    }
    else if(root -> right != NULL && root -> left == NULL){
        return rightAns;
    }
    else{
        return NULL;
    } 
}

int main()
{
    // Let us create the Binary Tree shown in above diagram.
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    node* ans1 = lca(root, 4, 5);
    cout << ans1 -> data << endl;
    node* ans2 = lca(root, 3, 4);
    cout << ans2 -> data << endl;
    // cout << "\nLCA(4, 6) = " << lca(root, 4, 6);
    // cout << "\nLCA(3, 4) = " << lca(root, 3, 4);
    // cout << "\nLCA(2, 4) = " << lca(root, 2, 4);
    return 0;
}