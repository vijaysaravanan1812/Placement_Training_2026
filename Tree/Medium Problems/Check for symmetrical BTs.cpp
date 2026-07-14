/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
    bool isSymmetric(TreeNode* left , TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr){
            return false;
        }
        if(left->data != right->data){
            return false;
        }
        return isSymmetric(left->left , right->right) && isSymmetric(left->right , right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        //your code goes here
        if(root == nullptr){
            return true;
        }
        return isSymmetric(root->left , root->right);
    }
};