

Problem Link - https://leetcode.com/problems/path-sum-iii/


Solution------



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
        int cnt=0;
    void pathCount(TreeNode *root, int sum)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==sum)
            cnt++;
            return;
        }

        if(root->val==sum)
        cnt++;

        if(root->left!=NULL)
        {
            pathCount(root->left,sum-root->val);
        }
        if(root->right!=NULL)
        {
            pathCount(root->right,sum-root->val);
        }
    }
    
    
    
    
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
        return cnt;
        
        pathCount(root,sum);
        
        if(root->left!=NULL)
        pathSum(root->left,sum);
        
        if(root->right!=NULL)
        pathSum(root->right,sum);
        
        return cnt;
        
    }
};



