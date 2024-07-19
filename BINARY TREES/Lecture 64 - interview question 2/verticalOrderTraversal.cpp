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

// int height(node* root){
//     if(root == NULL){
//         return 0;
//     }

//     else{
//     int leftHeight = height(root -> left);
//     int rightHeight = height(root -> right);

//     if(leftHeight > rightHeight){
//         return leftHeight + 1;
//     }
//     else{
//         return rightHeight + 1;
//     }
//     }
// }

// void printNodes(node* root, int level){
//     if(root == NULL){
//         return;
//     }
//     if(level == 1){
//         cout << root -> data;
//     }
//     if(level > 1){
//         printNodes(root -> left, level -1);
//         printNodes(root -> right, level -1);
//     }
// }

// void buildtree(node* root){
    
//     int h = height(root);
//     for(int i = 1; i <= h; i++){
//         cout << endl;
//         printNodes(root,i);
//     }
// }

vector<vector<int>> verticalOrder(node* root){
   vector<vector<int>> ans;
   if(root == NULL) { return ans; }
   map<int, vector<pair<int,int>>> mpp;
   queue<pair<node*, pair<int,int>>> q;
   q.push({root, {0,0}});
   while (!q.empty()){
    int sizee = q.size();
    // for(int i = 0; i < sizee; i++){
        auto p = q.front();
        q.pop();
    
    node* roots = p.first;
    int level = p.second.second;
    int vertical = p.second.first;

    mpp[vertical].push_back({level,roots -> data});

    if(root -> left){
        q.push({root -> left, {vertical -1, level+1}});
    }
    if(root -> right){
        q.push({root -> right, {vertical + 1, level+1}});
    }
    
   }

   vector<int> temp;
   for(auto& i : mpp){
    sort(i.second.begin(), i.second.end());
    for(auto it: i.second){
        temp.push_back(it.second);
    }
    ans.push_back(temp);
    // temp.clear();
   }

return ans;
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
    vector<vector<int>> result = verticalOrder(root);
    for(const auto& vec: result){
        for(int x : vec){
            cout << x << " ";
        }
        cout << endl;
    }
}
