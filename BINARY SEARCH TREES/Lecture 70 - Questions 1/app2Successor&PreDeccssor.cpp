#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this -> data = data;
        this -> right = right;
        this -> left = left;
    }
};

node* insert(node* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(data < root -> data){
        root -> left =  insert(root -> left, data);
    }
    else{
        root -> right = insert(root -> right, data);
    }
    return root;
}

// //Failed method
// int max(node* root){
//     node* temp = root;
//     // if(temp == NULL){
//     //     return NULL;
//     // }
//     if(temp -> right != NULL){
//         temp = temp -> left;
//     }
//     return temp -> data;
// }

// int min(node* root){
//     node* temp = root;
//     if(temp -> left != NULL){
//         return NULL;
//     }
//     return temp -> data;
// }

// pair<int,int> solve(node* root, int key){
//     if(root == NULL){
//         return;
//     }
//     int succ = min(root -> right);
//     int prec = max(root -> left);
//     return make_pair(prec, succ);
// }



pair<int,int> succpredecc(node* root, int key){
    node* temp = root;
    int succ = NULL ; int pre = NULL;
    while(temp -> data != key){
        if( key < temp -> data)
        {
            succ = temp -> data;
            temp = temp -> left;
            
        }
        if(key > temp -> data){
             pre = temp -> data;
            temp = temp -> right;
            // pre = temp -> data;
        }
    }


    node* leftTree = temp -> left;
    while(leftTree != NULL){
        pre = leftTree -> data;
        leftTree = leftTree -> right;
    }
    node* rightTree = temp -> right;
    while(rightTree != NULL){
        succ = rightTree -> data;
        rightTree = rightTree -> left;
    }
    pair<int,int> ans = make_pair(pre,succ);
    return ans;
}

