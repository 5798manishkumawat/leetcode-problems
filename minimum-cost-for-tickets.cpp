
Problem Link - https://leetcode.com/problems/minimum-cost-for-tickets/


Solution--



class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int dp[366]={0};
        int flag[366]={0};
        
        for(auto it:days)
        flag[it]=1;
        
        for(int i=1;i<366;i++)
        {
            if(!flag[i])
            dp[i]=dp[i-1];
            else
            dp[i]=min(dp[max(0,i-1)]+costs[0],min(dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]));
        }
        
        return dp[365];
    }
};