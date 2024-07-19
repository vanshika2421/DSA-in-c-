#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
};

node* newnode(int data){
    node* newnode = new node();
    newnode -> data = data;
    newnode-> left = NULL;
    newnode -> right = NULL;
    return newnode;
}

node* inorder(node* root){
    if(root == NULL){
        return root;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
    return root;
}

//creating BST



node* insert(node* root, int value){
   if(root == NULL){
        return newnode(value) ;
    }
    else if( value > root -> data){
        root -> right = insert(root -> right, value);
    }
    else if(value < root -> data){
        root -> left = insert(root -> left, value);
    }
    return root;
}


void takeInput(node* root){
    int data;
    cout << " enter data" << endl;
    cin  >> data;
    while(data != -1){
        root = insert(root,data);
        cin >> data;
    }
}


int height(node* root){
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


node*  minVal(node* root){
    node* temp = root;
    while(temp  -> left != NULL){
        temp = temp -> left;
    }
    return temp;
}

node* maxval(node* root){
    node* temp = root;
    while(temp -> right != NULL){
        temp = temp -> right;
    }
    return temp ;
}

node* deletenode(node* root, int val){
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
        node* temp = root -> right;
        delete root -> right;
        return temp;
    }
    else if(root -> left != NULL && root -> right == NULL){
        node* temp = root -> left;
        delete temp;
        return root -> left;
    }
    // 2 child
    if(root -> left != NULL && root -> right != NULL){
    root -> data = mini;
    root -> left = deletenode(root -> left , val);
    return root;
    }
   }
   else if(root -> data > val){
    root -> left = deletenode(root -> left,val);
    return root;
   }
   else {
    root -> right = deletenode(root -> right, val);
    return root;
   }
   return root;
}

void printGivennodes(node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data;
    }
    else if(level > 1){
        printGivennodes(root-> left, level-1);
        printGivennodes(root -> right, level -1);
    }
} 

void reverse(node* root){
    int h = height(root);
    cout << h << endl;
    int i;
    for(i = h; i >=1 ; i--){
        cout << endl;
        printGivennodes(root,i);
    }
}


// void printGivennodes(node* root, int level){
//     if(root == NULL){
//         return;
//     }
//     if(level == 1){
//         cout << root->data;
//     }
//     else if(level > 1){
//         printGivennodes(root-> left, level-1);
//         printGivennodes(root -> right, level -1);
//     }
// }

node* buildtree(node* root){
    if(root == NULL){
        return root;
    }
    int h = height(root);
    for(int i = 1; i <=h; i++){
        cout << endl ;
      printGivennodes(root,i);
      cout << " ";
    }
    return root;

}

int main(){
    node* root = NULL;
   
    root = insert(root, 1000);
    root = insert(root, 200);
    root = insert(root , 3);
    root = insert(root , 6);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 400);

    
    // root = newnode(10);
    // root = insert(root,7);
    // root -> right = newnode(35);
    // root ->left -> left = newnode(65);
    // root ->right -> left = newnode(123);
    root = insert(root, 4);
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    root = deletenode(root,100);
    cout << endl;
    buildtree(root);
    // takeInput(root);
    // printGivennodes(root,4);
    // root = insert(root, 4);
}