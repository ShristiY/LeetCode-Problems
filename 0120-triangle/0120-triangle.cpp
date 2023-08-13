class Solution {
public:
    int func(int i, int j, vector<vector<int>>&mat, int n, vector<vector<int>>&dp)
    {
        if(i==n-1) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int down=mat[i][j]+func(i+1,j,mat,n,dp);
        int dia=mat[i][j]+func(i+1,j+1,mat,n,dp);
        return dp[i][j]=min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(0,0,triangle,n,dp);
        
    }
};