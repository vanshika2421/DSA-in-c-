#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* left;
    Node* right;
};

Node* NewNode(int data){
    Node* newNode = new Node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return (newNode);
}

// fiing height of tree
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        int leftHeight = height(root -> left);
        int rightHeight = height(root-> right);

        if(leftHeight > rightHeight){
            return leftHeight + 1;
        }
        else{
            return rightHeight + 1;
        }
    }
}


Node*  minVal(Node* root){
    Node* temp = root;
    while(temp  -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}
Node* maxval(Node* root){
    Node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp ;
}

Node* deleteNode(Node* root, int val){
   int mini = minVal(root -> right) -> data;
   int maxi = maxval(root -> left) -> data;

   if( root  == NULL){
    return root;
   }
   if(root  -> data == val){
    // 0 child
    if(root -> left == NULL && root -> right == NULL){
        delete root;
        return NULL;
    }

    //1 child
    if(root -> left == NULL && root -> right != NULL){
        Node* temp = root -> right;
        delete root -> right;
        return temp;
    }
    else if(root -> left != NULL && root -> right == NULL){
        Node* temp = root -> left;
        delete temp;
        return root -> left;
    }
    // 2 child
    if(root -> left != NULL && root -> right != NULL){
    root -> data = mini;
    root -> left = deleteNode(root -> left , val);
    return root;
    }
   }
   else if(root -> data > val){
    root -> left = deleteNode(root -> left,val);
    return root;
   }
   else {
    root -> right = deleteNode(root -> right, val);
    return root;
   }
   return root;
}

void printGivenNodes(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data;
    }
    else if(level > 1){
        printGivenNodes(root-> left, level-1);
        printGivenNodes(root -> right, level -1);
    }
} 

void reverse(Node* root){
    int h = height(root);
    cout << h << endl;
    int i;
    for(i = h; i >=1 ; i--){
        cout << endl;
        printGivenNodes(root,i);
    }
}

void buildTree(Node* root){
    int h = height(root);
    int i;
    for(i = 1; i <=h; i++){
        cout << endl;
        printGivenNodes(root,i);
    }
}

void inorder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preOrder(Node* root){ //NLR
    // base case
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preOrder(root->left);
    preOrder(root -> right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    //  cout << root -> data << " ";
    preOrder(root->left);
    preOrder(root -> right);
    cout << root -> data << " ";
}

int diameter(Node* root){
    // int max = INT_MIN;
    if(root == NULL){
        return 1;
    }
    int op1 = diameter(root -> left);
    int op2 = diameter(root -> right);
    int op3 = height(root -> left) + 1 + height(root -> right);
    int ans = max(op1, max(op2,op3));
    return ans;

}

void buildFromLevelOrder(Node* root){
    queue<Node*> q;
    cout << " enter data for root" << endl;
    int data;
    cin >> data;
    root = NewNode(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << " enter data for left root : " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp -> left = NewNode(leftData);
            q.push(temp -> left);
        }

        cout << " enter data for right root" << temp -> data << endl;;
        int rightData;
        cin >> rightData;
        if(rightData != -1){
            temp -> right = NewNode(rightData);
            q.push(temp -> right);
        }
    }
}


Node* max(Node* root){
  Node* temp =  root;
  while(temp -> left != NULL) {
    temp = temp -> left;
  }
  return temp;
}


bool identical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
     else if(root1 == NULL && root2 != NULL){
        return false;
    }
    else if(root1 != NULL && root2 == NULL){
        return false;
    }
    bool lefty = identical(root1-> left , root2 -> left);
    bool righty = identical(root1-> right, root2 -> right);

    bool value = root1-> data == root2 -> data;

    if(lefty && righty && value){
        return true;
    }
    return false;
}

pair<bool,int> isSumTreePairs(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root-> left == NULL && root -> right == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> leftAns = isSumTreePairs(root-> left);
    pair<bool,int> rightAns = isSumTreePairs(root-> right);

    bool lefty = leftAns.first;
    bool righty = rightAns.first;

    bool condition = root -> data == leftAns.second + rightAns.second;

    pair<bool,int> ans;
    if(lefty && righty && condition){
        ans.first = true;
        ans.second = 2 * root-> data;
    }
    else{
        ans.first = false;
    }
}

bool isSumTree(Node* root){
    return isSumTreePairs(root).first;
}

vector<int> zigZagTrversal(Node* root){
    // sidha ans return krdo na..if nothing is present
    if(root == NULL){
        return {} ;
    }

    vector<int> result;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;


    while(!q.empty()){

        int size= q.size();
        vector<int> ans;

        for(int i = 0; i < size; i++){
        Node* frontNode = q.front();
        q.pop();

        int index = leftToRight ? i : size-i - 1;
        ans[index] = frontNode -> data;

        if(frontNode -> left){
            ans.push_back(frontNode -> data);
        }
         if(frontNode -> right){
            ans.push_back(frontNode -> data);
        }    
        }
        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}


int main(){

    Node* root1 = NewNode(1);
    root1 -> left = NewNode(2);
    root1 -> right = NewNode(3);
    root1 -> left -> left = NewNode(4);
    root1 -> left -> right = NewNode(5);
    root1 ->right-> left = NewNode(6);
    Node* root2 = NewNode(1);
    root2 -> left = NewNode(2);
    root2 -> right = NewNode(3);
    root2 -> left -> left = NewNode(4);
    root2 -> left -> right = NewNode(5);
    root2 ->right-> left = NewNode(6);
    // cout << "building tree: " ;
    // buildTree(root);cout << endl;
    // cout << "-----------------------" << endl;
    // cout << "Reversing tree : " ;
    // reverse(root);
    //  cout << endl;
    // cout << "-----------------------" << endl;
    // cout << "Inorder trvaersal tree : ";
    // inorder(root); cout << endl;
    // cout << "preorder trvaersal tree : ";
    // preOrder(root); cout << endl;
    // cout << "postorder trvaersal tree : ";
    // postorder(root); cout << endl;
    // cout << "-----------------------" << endl;
    // // buildFromLevelOrder(root);
    // // printGivenNodes(root,3);
    //  cout << "-----------------------" << endl;
    //  cout << " Longest diameter : " << " ";
    // cout << diameter(root);
    // cout << max(root) << endl;
    // cout << " deleting a node 4";
//   root1 =  deleteNode(root1,4);
//     cout << "hy" << endl;
//     // buildTree(root);
    identical(root1,root2);
}


//  int heights(Node* root){
//     if(root == NULL){
//         return 1;
//     }
//     else{
//         int leftHeight = heights(root -> left);
//         int rightHeight = height(root -> right);
//         if(leftHeight > rightHeight){
//             return leftHeight + 1;
//         }
//         else{
//             return rightHeight + 1;
//         }
//     }
// }
