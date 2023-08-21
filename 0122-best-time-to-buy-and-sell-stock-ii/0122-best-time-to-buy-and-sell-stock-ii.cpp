class Solution {
public:
    //0->can buy
    //1->can't buy
    int func(int ind,int buy, vector<int>&prices,int n,vector<vector<int>>&dp)
    {
        if(ind==n)
            return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy==0)
        {
            profit=max(-prices[ind]+func(ind+1,1,prices,n,dp),0+func(ind+1,0,prices,n,dp));
        }
        else{
            profit=max(prices[ind]+func(ind+1,0,prices,n,dp),0+func(ind+1,1,prices,n,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return func(0,0,prices,n,dp);
    }
};