class Solution {
public:
    int func(vector<int>&arr,int t, int ind,vector<vector<int>>&dp)
    {
      if(ind==0)
      {
              if(t%arr[0]==0)
                  return t/arr[0];
          else
              return 1e9;
      }
        if(dp[ind][t]!=-1) return dp[ind][t];
        int nott=func(arr,t,ind-1,dp);
        int take=1e9;
        if(arr[ind]<=t)
        take=1+func(arr,t-arr[ind],ind,dp);
        
        return dp[ind][t]=min(nott,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=func(coins,amount,n-1,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};