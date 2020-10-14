
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


//JAVA Solution
// class Solution {
//     Map<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new HashMap<>();
//     int minX = 0, maxX = 0;
//     public List<List<Integer>> verticalTraversal(TreeNode root) {
//         helper(root, 0, 0);
//         List<List<Integer>> vertical = new ArrayList<>();
//         for (int i = minX; i <= maxX; i++) {
//             List<Integer> level = new ArrayList<Integer>();
//             for (int key : map.get(i).keySet()) {
//                 while (!(map.get(i).get(key)).isEmpty()) {
//                     level.add(map.get(i).get(key).poll());
//                 }
//             }
//             vertical.add(level);
//         }
//         return vertical;
        
//     }
    
//     private void helper(TreeNode node, int x, int y) {
//         if (node == null) return;
//         minX = Math.min(minX, x);
//         maxX = Math.max(maxX, x);
//         if (map.get(x) == null) { map.put(x, new TreeMap<Integer, PriorityQueue<Integer>>()); }
//         if (map.get(x).get(y) == null) { map.get(x).put(y, new PriorityQueue<Integer>()); }
//         map.get(x).get(y).add(node.val);
//         helper(node.left, x - 1, y + 1);
//         helper(node.right, x + 1, y + 1);   

//     }
// }
