
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

//JAVA Solution
// public int mincostTickets(int[] days, int[] costs) {
//         boolean[] dayIncluded = new boolean[366];
//         for (int day : days) {
//             dayIncluded[day] = true;
//         }
//         int[] minCost = new int[366];
//         minCost[0] = 0;
//         for (int day = 1; day <= 365; ++day) {
//             if (!dayIncluded[day]) {
//                 minCost[day] = minCost[day-1];
//                 continue;
//             }
//             int min;
//             min = minCost[day-1] + costs[0];
//             min =Math.min(min, minCost[Math.max(0, day-7)] + costs[1]);
//             min = Math.min(min, minCost[Math.max(0, day-30)] + costs[2]);
//             minCost[day] = min;
//         }

//         return minCost[365];

//     }
