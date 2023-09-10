class Solution {
public:
    int func(int i,int j,vector<vector<int>>&dp)
    {
        if(i==0&& j==0)return 1;
        if(i<0 ||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up=func(i-1,j,dp);
        int left=func(i,j-1,dp);
        
        return dp[i][j]=up+left;
    }
                     
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,dp);
    }
};