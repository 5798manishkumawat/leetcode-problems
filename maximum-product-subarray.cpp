
Problem Link - https://leetcode.com/problems/maximum-product-subarray/


Solution-----



class Solution {
public:
    int maxProduct(vector<int>& nums) {
         
        int n=nums.size();
        int maxn=nums[0], minn=nums[0], product=nums[0];
        for(int i=1; i<n; i++)
        {
            int x = nums[i];
            int y = x*maxn;
            int z = x*minn;
            maxn = max(x, max(y, z));
            minn = min(x, min(y, z));
            
            product=max(product, max(maxn, minn));
        }
        return product;
    } 
};