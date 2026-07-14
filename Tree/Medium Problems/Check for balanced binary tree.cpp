/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    int checkHeights(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = checkHeights(root->left);
        if(leftHeight == -1){
            return -1;
        }
        int rightHeight = checkHeights(root->right);
        if(rightHeight == -1){
            return -1;
        }
        if(abs(leftHeight - rightHeight) > 1){
            return -1;
        }
        return 1 + max(leftHeight , rightHeight);

    }
public:
    bool isBalanced(TreeNode *root){
    	//your code goes here
        return checkHeights(root) != -1;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(height(root->left ), height( root->right));
    }
public:
    bool isBalanced(TreeNode *root){
    	//your code goes here
        if(root == nullptr) 
            return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if(abs(leftHeight - rightHeight) > 1)
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};