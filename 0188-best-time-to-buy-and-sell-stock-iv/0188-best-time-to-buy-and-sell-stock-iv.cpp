class Solution {
public:
    int func(int ind,int buy,int k,vector<int>&arr,vector<vector<vector<int>>>&dp,int n)
    {
        if(ind==n || k==0)
            return 0;
        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];
        int profit;
        
        if(buy==0)
            profit=max(-arr[ind]+func(ind+1,1,k,arr,dp,n),func(ind+1,0,k,arr,dp,n));
        else
            profit=max(arr[ind]+func(ind+1,0,k-1,arr,dp,n),func(ind+1,1,k,arr,dp,n));
        
        return dp[ind][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return func(0,0,k,arr,dp,n);
    }
};