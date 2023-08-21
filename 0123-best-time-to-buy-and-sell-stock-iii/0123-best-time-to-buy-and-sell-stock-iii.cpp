class Solution {
public:
    int func(int ind,int buy,int cap,vector<int>&arr, int n, vector<vector<vector<int>>>&dp)
    {
        if(cap==0 || ind==n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit;
        if(buy==0)
            profit=max(-arr[ind]+func(ind+1,1,cap,arr,n,dp),func(ind+1,0,cap,arr,n,dp));
        else
            profit=max(func(ind+1,1,cap,arr,n,dp),arr[ind]+func(ind+1,0,cap-1,arr,n,dp));
        
        return dp[ind][buy][cap]=profit;
            
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,0,2,arr,n,dp);
    }
};