
Problem Link - https://leetcode.com/problems/implement-rand10-using-rand7/


Solution----------



// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
    
public:
    
    int rand10() {
        
       int oe=rand7();
        
        while(oe==7)
            oe=rand7();
        
        int num=rand7();
        
        while(num>=6)
            num=rand7();
        
        if(oe%2==0)
        return num+5;
        else
        return num;
        
    }
};