
Problem Link - https://leetcode.com/problems/unique-paths/



Solution-----



class Solution {
public:
    
    int dp[101][101];
    
    int path(int m,int n)
    {
        for(int i=0;i<m;i++)
        dp[0][i]=1;
        
        for(int i=0;i<n;i++)
        dp[i][0]=1;
        
        for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        
        return dp[n-1][m-1];
    }
    
    
    
    int uniquePaths(int m, int n) {
        
        memset(dp,0,sizeof(dp));
        
        
        return path(m,n);
    }
};

//JAVA Solution

// public class Solution {
//     public int uniquePaths(int m, int n) {
//         Integer[][] map = new Integer[m][n];
//         for(int i = 0; i<m;i++){
//             map[i][0] = 1;
//         }
//         for(int j= 0;j<n;j++){
//             map[0][j]=1;
//         }
//         for(int i = 1;i<m;i++){
//             for(int j = 1;j<n;j++){
//                 map[i][j] = map[i-1][j]+map[i][j-1];
//             }
//         }
//         return map[m-1][n-1];
//     }
// }
