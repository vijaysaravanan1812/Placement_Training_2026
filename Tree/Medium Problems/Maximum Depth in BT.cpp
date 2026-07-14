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
public:
    int maxDepth(TreeNode* root) {
        //your code goes here
        if(root == nullptr){
            return 0;
        }
        int leftDepth =  maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth , rightDepth); 
    }
};