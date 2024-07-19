

bool searchInBST(Node* root,int x){
    if(root == NULL){
        return false;
    }
    if(root -> data  == x){
        return true;
    }
    if(x < root -> data){
        searchInBST(root -> left, x);
    }
    else{
        searchInBST(root -> right, x);
    }
};  

node* miniVal(node* root){
    node* temp = root;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    return temp -> data;
}

Node* deleteInBst(Node* root, int x){
    if(root == NULL){
        return NULL;
    }
    if(root -> val == x){
        if(root -> left == NULL && root -> right = NULL){
            delete root;
            return NULL;
        }
        else if(root -> left == NULL && root -> right != NULL){
            node* temp = root -> right;
            delete root 
            return temp;
        }
        else if(root -> left != NULL && root -> right == NULL){
            node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> right != NULL && root -> left != NULL){
            int minival = minVal(root -> right);
            root -> data = miniVal;
            root -> right = deleteInBst(root,x);
            return root;
        }
    }
}