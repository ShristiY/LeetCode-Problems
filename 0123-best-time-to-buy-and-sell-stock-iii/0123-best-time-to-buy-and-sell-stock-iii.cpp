class Solution {
public:
    int func(int ind, int buy, int cap, vector<int>&arr, vector<vector<vector<int>>>&dp,int n)
    {
        if(ind==n) return 0;
        if(cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        
        int profit;
        if(buy==0)
            profit=max(-arr[ind]+func(ind+1,1,cap,arr,dp,n),0+func(ind+1,0,cap,arr,dp,n));
        else
            profit=max(arr[ind]+func(ind+1,0,cap-1,arr,dp,n),0+func(ind+1,1,cap,arr,dp,n));
        
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>&  arr) {
        int n=arr.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,0,2,arr,dp,n);
    }
};