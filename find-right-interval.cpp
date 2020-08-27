
Problem Link - https://leetcode.com/problems/find-right-interval/



Solution-----



class Solution {
public:
    
    static bool compare(pair<int,int>x,pair<int,int>y)
    {
        return y.second>x.first; 
    }
    
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        map<pair<int,int>,int>mp;
        vector<int>ans;
        vector<pair<int,int>>pairs;
        
        for(int i=0;i<intervals.size();i++)
        {
            int x=intervals[i][0];
            int y=intervals[i][1];
            
            mp[{x,y}]=i;
            
            pairs.push_back({x,y});
        }
        
        sort(pairs.begin(),pairs.end());
        
        for(int i=0;i<intervals.size();i++)
        {
            int x=intervals[i][0];
            int y=intervals[i][1];
            pair<int,int>curr={x,y};
            
            auto it=lower_bound(pairs.begin(),pairs.end(),curr,compare);
            
            if(it==pairs.end())
            ans.push_back(-1);
            else
            ans.push_back(mp[*it]);
        }
        
        return ans;
        
    }
};