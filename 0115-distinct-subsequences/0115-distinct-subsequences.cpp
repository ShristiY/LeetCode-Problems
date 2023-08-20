class Solution {
public:
    int func(string s1, string s2,int i,int j,vector<vector<int>>&dp)
    {
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i-1]==s2[j-1])
        {
            return dp[i][j]=func(s1,s2,i-1,j-1,dp)+func(s1,s2,i-1,j,dp);
        }
        else
            return dp[i][j]=func(s1,s2,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(s,t,n,m,dp);
    }
};