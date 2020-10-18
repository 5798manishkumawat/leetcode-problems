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
    void helper(TreeNode* root,int & maxDepth,int & leftval,int level)
    {
        if(root==nullptr)
            return;
        helper(root->left,maxDepth,leftval,level+1);
        helper(root->right,maxDepth,leftval,level+1);
        if(level>maxDepth)
        {
            maxDepth=level;
            leftval=root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth=0;
        int leftval=root->val;
       helper(root,maxDepth,leftval,0); 
        return leftval;
    }
};
