
// class Solution{
//     int height(Node* root){
//         if (root == NULL){
//             return 0;
//         }
//         else{
//             int lefty = height(root -> left);
//             int righty = height(root -> right);
//             // if(lefty > righty){
//             //     return lefty + 1;
//             // }
//             // else{
//             //     return righty + 1;
//             // }
//             int ans = max(lefty,righty) + 1;
//             return ans;
//         }
//     }
//     public:
//     //Function to check whether a binary tree is balanced or not.
//     pair<bool,int> isBtree(Node* root){
//          if(root == NULL){
//             pair<bool, int> p = make_pair(true,0);
//             return p;
//         }
//         else{
            
//             pair<bool,int> left = isBtree(root -> left);
//             pair<bool,int> right = isBtree(root -> right);
//             bool lefty = left.first;
//             bool rigthy = right.first;
//             bool x = abs(left.second - right.second ) <= 1;
//             pair<bool,int> ans;
//             ans.second = max(left.second , right.second) + 1;
            
//             if(x && lefty && rigthy){
//                 ans.first = true;
//             }
//             else{
//                 ans.second = false;
//             }
//             return ans;
//         }
//     }
//     bool isBalanced(Node *root)
//     {
//      return isBtree(root).first;
//     }
// };