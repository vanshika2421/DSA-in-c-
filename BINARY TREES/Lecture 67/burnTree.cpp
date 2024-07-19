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
        this -> left = NULL;
        this -> right = NULL;
    }

};

Node* createParentNode(int data, map<Node*,Node*> &NodeToParent, int Target){
    queue<Node*> q;
    q.push(root);

    Node* result = NULL;
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front -> data == Target){
            result = front;
        }
        if(front -> left){
            NodeToParent[front -> left] = front;
            q.push(front);
        }
        if(front -> right){
            NodeToParent[front -> right] = front;
            q.push(front);
        }
    }
    return result;
}

int burnTree(Node* root, map<Node*,Node*> &NodeToParent){
    queue<Node*> q;
    map<Node*, bool> visited;
    bool flag = 0;
    q.push(root);
    visited[root] = 1;
    int ans= 0;
    while(!q.empty()){
       
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* front = q.front();
            q.pop();
        
        if(front->left && !visited[front -> left]){
            q.push(front -> left);
            visited[front -> left] = 1;
            flag = 1;
        }
        if(front -> right && !visited[front -> right]){
            q.push(front -> right);
            visited[front -> right] = 1;
            flag = 1;
        }
        if(NodeToParent[front] && !visited[NodeToParent[front]]){
            q.push(NodeToParent[front]);
            visited[NodeToParent[front]] = 1;
            flag = 1;
        }
    }
    }
    if(flag == 1){
        ans++;
    }
    return ans;
}


int mintTime(Node* root, int target){
    // step 1 -> node to parent ki mapping nikalni hai.. kyunki you have left to right ki mapping but you dont know whats there parent is 
    // step 2 -> target node find krni hai
    // step 3 -> visieted and non visited ko leke tree burn krna hai

    map<Node* , Node*> NodeToParent;
    Node* targetNode = createParentNode(root,target, NodeToParent);
    int ans = minTimeToBurnTree(root, NodeToParent);
    return ans;
} 