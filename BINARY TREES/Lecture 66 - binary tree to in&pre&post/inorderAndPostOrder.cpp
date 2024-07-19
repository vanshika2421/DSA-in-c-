#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

int findPos(int in[], int ele, int n){
    for(int i = 0; i < n; i++){
         if(in[i] == ele){
            return i;
         }
    }
    return -1;
};


node* solve(int in[], int post[], int &index, int indexStart, int indexEnd, int n){
    if(index < 0 || indexStart > indexEnd){
        return NULL;
    }
    int ele = post[index--];
    node* root = new node(ele);
    int position = findPos(in, ele, n);

    root -> right = solve(in, post, index, position + 1, indexEnd, n);
    root -> left = solve(in, post, index, indexStart, position -1, n);
    return root;
}

node* buildTree(int in[], int post[], int n){
    int Postindex = n-1;
    return solve(in, post, Postindex, 0, n-1 , n);
    
}

void preorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    int n = 8;
    int post[n] = {4,8,5,2,6,7,3,1};
    int in[n] = {8,4,2,5,1,6,3,7}; 

    node* root =buildTree(in,post,n);

     cout << "Inorder traversal of the constructed tree: ";
    preorderTraversal(root);
    cout << endl;

}

