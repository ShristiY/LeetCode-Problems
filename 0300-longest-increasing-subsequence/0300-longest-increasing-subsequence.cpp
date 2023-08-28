class Solution {
public:
    int func(vector<int>&nums,vector<vector<int>>&dp,int ind, int prev, int n)
    {
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        
        int notTake=0+func(nums,dp,ind+1,prev,n);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])
            take=1+func(nums,dp,ind+1,ind,n);
        
        return dp[ind][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(nums,dp,0,-1,n);
    }
};