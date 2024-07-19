#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* newNode(int d){
    node* neww = new node(d);
    return neww;
}

void diagonalTraversal(node* root, int level, map<int, vector<int>> &diagonalPrint){
    if(root == NULL){
        return;
    }
    diagonalPrint[level].push_back(root -> data);
    diagonalTraversal(root -> left,level+1, diagonalPrint);
    diagonalTraversal(root -> right, level, diagonalPrint);

}

void diagonalPrints(node* root){
    map<int, vector<int>> diagonalPrint;
    diagonalTraversal(root,0,diagonalPrint);

    for(auto i: diagonalPrint){
        vector<int>  v = i.second;
        for(auto it : v){
            cout << it << " ";
            cout << endl;
        }
    }
}

int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    diagonalPrints(root);
    // for(const auto& vec: result){
    //     for(int x : vec){
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
}
