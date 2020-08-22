
Problem Link- https://leetcode.com/problems/sort-array-by-parity/


Solution----



class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int n=A.size();
        
        vector<int>vt(n);
        
        int s=0;int e=n-1;
        
        for(auto it:A)
        {
            if(it%2==0)
            {
                vt[s]=it;
                s++;
            }
            else
            {
                vt[e]=it;
                e--;
            }
        }
        
        return vt;
        
    }
};