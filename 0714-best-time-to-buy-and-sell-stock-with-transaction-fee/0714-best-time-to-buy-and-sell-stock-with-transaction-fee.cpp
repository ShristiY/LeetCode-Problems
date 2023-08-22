class Solution {
public:
    int func(int ind, int buy, int n, vector<vector<int>>&dp,vector<int>&arr,int fee)
    {
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        int profit;
        if(buy==0)
            profit=max(-arr[ind]+func(ind+1,1,n,dp,arr,fee),func(ind+1,0,n,dp,arr,fee));
        else
            profit=max(arr[ind]-fee+func(ind+1,0,n,dp,arr,fee),func(ind+1,1,n,dp,arr,fee));
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return func(0,0,n,dp,arr,fee);
    }
};