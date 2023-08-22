class Solution {
public:
    int func(int ind, int trans, vector<vector<int>>&dp,vector<int>&arr,int n)
    {
        if(ind==n) return 0;
        if(trans==4) return 0;
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        int profit;
        
        if(trans%2==0)
        {
            profit=max(-arr[ind]+func(ind+1,trans+1,dp,arr,n),func(ind+1,trans,dp,arr,n));
            
        }
        else
            profit=max(arr[ind]+func(ind+1,trans+1,dp,arr,n),func(ind+1,trans,dp,arr,n));
        
        return dp[ind][trans]=profit;
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        return func(0,0,dp,arr,n);
    }
};