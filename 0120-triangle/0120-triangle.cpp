class Solution {
public:
    //tabulation
   
    int minimumTotal(vector<vector<int>>& mat) {
        int n=mat.size();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++)
            dp[n-1][j]=mat[n-1][j];
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down=mat[i][j]+dp[i+1][j];
                int dia=mat[i][j]+dp[i+1][j+1];
                
                dp[i][j]=min(down,dia);
            }
        }
        return dp[0][0];
        
    }
};