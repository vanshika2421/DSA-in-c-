#include<iostream>
using namespace std;


class node{
    public:
    int data; 
    node* left;
    node* right;

    node(int data){
        data = data;
        right = NULL;
        left = NULL;

    }
};

node* newNode(int data){
    node* neww = new node(data);
    return neww;
}


void sumOfroots(node* root, int sum, int len, int maxsum, int maxlen){
    if(root == NULL){
        if(maxlen < len){
            maxlen = len;
            maxsum = sum;
        }
        if(maxsum < sum && maxlen == len){
            maxsum = sum;
        }
    }

    sumOfroots(root -> left, sum + root -> data, len + 1 , maxsum, maxlen);
    sumOfroots(root -> right, sum + root -> data, len + 1 , maxsum, maxlen);
}

int printSumofRoots(node* root){
    if(root == NULL){
        return;
    }
    int maxsum = INT_MIN;
    int maxlen = 0;
    sumOfroots(root, 0,0, maxsum,maxlen);
    return maxsum;
}

int main(){
    
}