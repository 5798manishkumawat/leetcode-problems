
Problem Link - https://leetcode.com/problems/longest-palindrome/


Solution-----



class Solution {
public:
    map<char,int>mp;
    int longestPalindrome(string s) {
        
        int n=s.length();
        
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        
        
        int res=0;
        int flag=0;
        for(char i='a';i<='z';i++)
        {
            if(mp[i]%2!=0)
            {
                res-=1;flag=1;
            }
            res+=mp[i];
        }   
        
        for(char i='A';i<='Z';i++)
        {
            if(mp[i]%2!=0)
            {
                res-=1;flag=1;
            }
            res+=mp[i];
        } 
        
        if(flag==1)
        res++;
        
        
        return res;
        
    }
};
