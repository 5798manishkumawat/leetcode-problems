
Problem Link - https://leetcode.com/problems/detect-capital/


Solution------

class Solution {
public:
    map<char,int>mp;
    bool detectCapitalUse(string word) {
        
        int d=word.length();
        
        for(int i=0;i<d;i++)
        mp[word[i]]++;
        
        int sum=0;int f=0;
        for(char i='a';i<='z';i++)
        {
            sum+=mp[i];
            
            if(word[0]==i)
                f=1;
        }
        
        if(sum==0 || sum==d || (sum==d-1 && f==0))
        return true;
        else
        return false;
        
        
    }
};