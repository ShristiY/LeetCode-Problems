class Solution {
public:
    //MEMOIZATION
    int solve(int i,int j,int n, int m, vector<vector<int>>&dp)
    {
        if(i==n-1 && j==m-1)
            return 1;
         if(i>=n || i<0 || j>=m || j<0)
            return 0;
         if(dp[i][j]!=-1)
            return dp[i][j];
        int down=solve(i+1,j,n,m,dp);
        int right=solve(i,j+1,n,m,dp);
        return dp[i][j]= down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,dp);
    }
};