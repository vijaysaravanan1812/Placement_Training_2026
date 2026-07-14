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
    int height(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(height(root->left) , height(root->right));
    }
public:
    int diameterOfBinaryTree(TreeNode* root, int & Diameter) {
        //your code goes here
        if(root == nullptr)
            return  0;


        int leftHeight = diameterOfBinaryTree(root->left , Diameter);
        int rightHeight = diameterOfBinaryTree(root->right, Diameter);
        Diameter = max( Diameter ,  leftHeight + rightHeight);
        return 1 + max(leftHeight , rightHeight);

    }
    int diameterOfBinaryTree(TreeNode * root){
        int Diameter = INT_MIN;
        diameterOfBinaryTree(root , Diameter);
        return Diameter;
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

class Solution {
    int height(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(height(root->left) , height(root->right));
    }
public:
    void diameterOfBinaryTree(TreeNode* root, int & Diameter) {
        //your code goes here
        if(root == nullptr)
            return;


        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        Diameter = max( Diameter ,  leftHeight + rightHeight);
        diameterOfBinaryTree(root->left, Diameter);
        diameterOfBinaryTree(root->right, Diameter);

    }
    int diameterOfBinaryTree(TreeNode * root){
        int Diameter = INT_MIN;
        diameterOfBinaryTree(root , Diameter);
        return Diameter;
    }
};