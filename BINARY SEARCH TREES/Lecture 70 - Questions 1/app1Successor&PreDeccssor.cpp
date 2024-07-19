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


vector<int> solve(node *root, vector<int> &ans) {
  if (root == NULL) {
    return {};
  }
  solve(root->left, ans);
  ans.push_back(root->data);
  solve(root->right, ans);
  return ans;
}

pair<int, int> predecessorSuccessor(node *root, int key) {
  vector<int> ans;
  solve(root, ans);

  int pre = -1;
  int succ = -1;

  for (int i = 0; i < ans.size(); ++i) {
    if (ans[i] == key) {
      if (i > 0) {
        pre = ans[i - 1];
      }
      if (i < ans.size() - 1) {
        succ = ans[i + 1];
      }
      break;
    }
  }
  return make_pair(pre,succ);
}

int main(){
    node* root = NULL;
    int n ;
    int key;

    cin >> n;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        root = insert(root,value);
    }
    

}