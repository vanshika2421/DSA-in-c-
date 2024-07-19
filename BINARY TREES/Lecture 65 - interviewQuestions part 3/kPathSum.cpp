#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = left;
        this -> right = right;
    }
}


void solve(Node* root, vector<int> &path, int &count, int k){
    if(root == NULL){
        return;
    }
    path.push_back(root->data);
    solve(root -> left , path, count, k);
    solve(root -> right, path, count, k);
    int sum = 0;
    int size = path.size();
    for(int i = size-1; i>=0; i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }
    path.pop_back();
}

int sumk(Node* root, int k){
    vector<int> path;
    int count = 0;
    solve(root, path, count, k);
    return count;
}
