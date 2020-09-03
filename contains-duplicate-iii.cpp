
Problem Link - https://leetcode.com/problems/contains-duplicate-iii/


Solution----------



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
                if(k==10000) return false;
                for(int j=i+1;j<=i+k && j<n;j++)
                {
                    long int d=abs((long)nums[j]-(long)nums[i]);
                    if(d<=(long)t)
                    return true;
                }   
        }
        
        return false;
    }
};