
Problem Link - https://leetcode.com/problems/maximum-product-subarray/


Solution-----



class Solution {
public:
    int maxProduct(vector<int>& nums) {
         
        int n=nums.size();
        int maxn=nums[0], minn=nums[0], product=nums[0];
        for(int i=1; i<n; i++)
        {
            int x = nums[i];
            int y = x*maxn;
            int z = x*minn;
            maxn = max(x, max(y, z));
            minn = min(x, min(y, z));
            
            product=max(product, max(maxn, minn));
        }
        return product;
    } 
};


//Solution in JAVA

// public int maxProduct(int[] A) {
//         int n = A.length, res = A[0], l = 0, r = 0;
//         for (int i = 0; i < n; i++) {
//             l =  (l == 0 ? 1 : l) * A[i];
//             r =  (r == 0 ? 1 : r) * A[n - 1 - i];
//             res = Math.max(res, Math.max(l, r));
//         }
//         return res;
//     }
