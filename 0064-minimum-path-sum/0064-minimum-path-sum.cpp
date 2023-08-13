class Solution {
public:
    //memoization
    int func(int n, int m, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=m;j++)
           {
               if(i==0 && j==0)
               {
                   dp[i][j]=grid[i][j];
               }
               else{
               int left=grid[i][j],up=grid[i][j];
               
               if(i>0) up+=dp[i-1][j];
               else up+=1e9;
               
               if(j>0) left+=dp[i][j-1];
               else
                   left+=1e9;
               
               dp[i][j]=min(up,left);
           }
           }
       }
        return dp[n][m];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,grid,dp);
    }
};