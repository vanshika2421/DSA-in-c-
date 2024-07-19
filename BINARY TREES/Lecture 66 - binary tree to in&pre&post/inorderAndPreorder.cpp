#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;

    node(int data){
        data = data;
        left = NULL;
        right = NULL;
    }
};

int findPosition(int in[], int element, int n){
    for(int i = 0; i < n; i++){
        if(in[i] == element){
            return i;
        }
    }
}

node* two(int in[], int pre[], int &index, int indexStart, int indexEnd, int n){
    
    if(index >= n || indexStart > indexEnd){
        return NULL;
    }
    int element = pre[index++];
    int position = findPosition(in, element, n);
    node* root = new node(element);

    root -> left = two(in, pre, index, indexStart, position - 1, n);
    root -> right = two(in, pre, index, position + 1, indexEnd, n);

    return root;

}

node* one(int in[], int pre[], int n){
    int preOrderIndex = 0;
    node* ans = two(in, pre, preOrderIndex, 0, n-1, n);
    return ans;

}