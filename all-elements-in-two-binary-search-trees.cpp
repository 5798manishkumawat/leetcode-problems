
Problem Link - https://leetcode.com/problems/all-elements-in-two-binary-search-trees/



Solution --------



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
    
    vector<int>vt;
    
    void tree(TreeNode* root)
    {
        if(root!=nullptr)
        {
            int d=root->val;
            vt.push_back(d);
        }
        
        if(root->left!=nullptr)
        tree(root->left);
        
        if(root->right!=nullptr)
        tree(root->right);
        
        return;
    }
    
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vt.clear();
        if(root1!=nullptr)
        tree(root1);
        
        if(root2!=nullptr)
        tree(root2);
        
        sort(vt.begin(),vt.end());
        
        return vt;
    }
};