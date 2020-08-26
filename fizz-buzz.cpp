
Problem Link - https://leetcode.com/problems/fizz-buzz/


Solution--



class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string>vt;
        for(int i=1;i<=n;i++)
        {
            if(i%15==0)
            vt.push_back("FizzBuzz");
            else if(i%5==0)
            vt.push_back("Buzz");
            else if(i%3==0)
            vt.push_back("Fizz");
            else
            {
                string x=to_string(i);
                vt.push_back(x);
            }
        }
        
        return vt;
    }
};