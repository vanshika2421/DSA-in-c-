#include<iostream> 
using namespace std;


int solve(Node* root, int &i, int k ){
    if(root == NULL){
        return -1;
    }
    
    solve(root -> left, i, k);
    
    if(i == NULL){
        return -1;
    }
    i++;
    if(i == k){
        return root;
    }
    solve(root -> right, i,k);
}

int kthSmallest(Node* root, int k){
    int i=0;
    int ans = solve(root, i, k);
    return ans;
}