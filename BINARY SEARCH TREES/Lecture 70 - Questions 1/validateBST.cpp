#include<iostream>
using namespace std;



bool solve(Node* root, int min, int max){
    if(root == NULL){
         return NULL;
    }
    if(root -> data <= max && root -> data >= min){ // -infinity is min and +infinity is max;
        bool lefty = solve(rot-> left, min, root -> data);
        bool righty = solve(root -> right, root-> dat, max);
        return lefty && righty;
    }
}


bool validateBST(Node* root){
    return solve(Node* root, INT_MIN, INT_MAX);
}

int main(){
    
}