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
    int findMaxPathSum(TreeNode *root, int &MAXI){
        if(root == NULL){
            return 0;
        }

        int leftSumPath = max(0, findMaxPathSum(root->left, MAXI));
        int rightSumPath = max(0 , findMaxPathSum(root->right , MAXI));

        MAXI = max(MAXI , leftSumPath + rightSumPath + root->data);

        return max(leftSumPath , rightSumPath) + root->data;


    }
public:
    int maxPathSum(TreeNode* root) {
        //your code goes here
        int maxi = INT_MIN;

        findMaxPathSum(root , maxi);

        return maxi;
    }
};	
