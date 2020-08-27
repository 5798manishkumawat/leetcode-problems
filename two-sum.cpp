
Problem Link - https://leetcode.com/problems/two-sum/



Solution-----



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        map<int ,vector<int>>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            int x=target-nums[i];
            
            if(nums[i]!=x && mp[x].size()>0)
            {
                ans.push_back(mp[nums[i]][0]);
                ans.push_back(mp[x][0]);
                break;
            }
            else if(nums[i]==x && mp[x].size()>1)
            {
                ans.push_back(mp[x][0]);
                ans.push_back(mp[x][1]);
                break;
            }
        }
        
        
        return ans;
    }
};