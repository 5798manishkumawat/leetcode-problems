
Problem Link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

Solution-----



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
    void getVerticalOrder(TreeNode* root, int hd,int d, map<int, vector<pair<int,int>>> &mp) 
    { 
        if (root == NULL) 
            return; 

        mp[hd].push_back({d,root->val}); 
        
        getVerticalOrder(root->left, hd-1,d+1,mp); 
        
        getVerticalOrder(root->right, hd+1,d+1,mp); 
    } 
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map <int,vector<pair<int,int>>>mp; 
        int hd = 0; int d=0;
        getVerticalOrder(root, hd,d,mp);
        
        vector<vector<int>>ans;
        
        for (auto it=mp.begin(); it!=mp.end(); it++) 
        {
            sort((it->second).begin(),(it->second).end());
            vector<int>vt;
            
            for(auto tt=(it->second).begin();tt!=(it->second).end();tt++)
            {
                vt.push_back(tt->second);
            }
            
            if(vt.size()!=0)
            ans.push_back(vt);
            
        }
        
        return ans;
    }
};