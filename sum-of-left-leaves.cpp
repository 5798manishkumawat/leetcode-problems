
Problem Link - https://leetcode.com/problems/sum-of-left-leaves/


Solution----------




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isLeaf(TreeNode *node) 
    { 
       if (node == NULL) 
           return false; 
       if (node->left == NULL && node->right == NULL) 
           return true; 
       return false; 
    } 
    
    int leftLeavesSum(TreeNode *root) 
    { 
        int res = 0; 
        if (root != NULL) 
        { 
            if (isLeaf(root->left)) 
            res += root->left->val; 
            else 
            res += leftLeavesSum(root->left); 

           res += leftLeavesSum(root->right); 
        } 
        
        return res; 
    } 
    
    
    
    int sumOfLeftLeaves(TreeNode* root) {
        
       int sum=leftLeavesSum(root);
        
        return sum;
        
    }
};