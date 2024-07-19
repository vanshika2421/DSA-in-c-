#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> right = NULL;
        this -> left = NULL;
    }
};

Node* insert(Node* root, int data){
    if(root == NULL){
        return NULL;
    }
    if(data > root -> data){
        return insert(root -> right, data);
    }
    else{
        return insert(root -> left, data);
    }
}

vector<int> inorder(Node* root, vector<int> &ans){
    if(root == NULL){
        return NULL;
    }
    inorder(root -> left, ans);
    ans.push_back(root -> data);
    inorder(root -> right, ans);
    return ans;
}

vector<int> merge(vector<int> &a , vector<int> &b){
    vector<int> c(a.size() + ans.size2());

    int i = 0;
     int j = 0;
    int k = 0;
    while( i < a.size() && j < b.size()){
        if (a[i] < b[j])
        {
            c[k++] = a[i];
            i++;
        }
        else{
            c[k++] = b[j];
            j++;
        }
    }
    while(i < a.size()){
         c[k++] = a[i];
            i++;
    }
    while(j < b.size()){
        c[k++] = b[j];
            j++;
    }
    return c;
}

Node* mergeBsts(int s, int e , vector<int> &c){
    if(s>e){
        return;
    }
    int mid = (s+e)/2;
    Node* rootNode = newNode(c[mid]);
    rootNode -> left = mergeBsts(s, mid -1, c );
    rootNode -> right(mid+1, e, c);
}


Node* merge3(Node* root1, Niode* root2){
     vetcor<int> a,b;
     inorder(root1, a);
     inorder(root2,b);
     vector<int> mergelist= merge(a,b);
     return mergeBsts(0, mergelist.size(), mergeList);
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;

    int n1,n2,val;
    cin >> n1;
    for(int i = 0; i < n1; i++){
        cin >> val;
        root1 = insert(root1, val);
    }
    cin >> n2;
    for(int i = 0; i < n2; i++){
         cin >> val;
         root2 = insert(root2, val);
    }
    Node*  mergedRoot = merge3(root1, root2)l
    vector<int> merge
}



