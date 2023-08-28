class Solution {
public:
    int func(vector<int>&nums,int n, int ind, int prev,vector<vector<int>>&dp)
    {
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        
        int notTake=func(nums,n,ind+1,prev,dp);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev])
            take=1+func(nums,n,ind+1,ind,dp);
        
        return dp[ind][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(nums,n,0,-1,dp);
    }
};