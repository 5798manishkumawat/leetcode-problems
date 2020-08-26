
Problem Link - https://leetcode.com/problems/maximum-product-of-three-numbers/


Solution--



class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int p=nums[n-1]*nums[n-2]*nums[n-3];
        int q=nums[n-1]*nums[n-2]*nums[0];
        int r=nums[n-1]*nums[0]*nums[1];
        int s=nums[0]*nums[1]*nums[2];
        
        p=max(p,max(q,max(r,s)));
        return p;
    }
};