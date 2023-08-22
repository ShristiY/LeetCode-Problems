class Solution {
public:
    //MOST OPTIMAL
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int ind=0;ind<n;ind++)
        {
            for(int prev=0;prev<=ind-1;prev++)
            {
                if(nums[prev]<nums[ind])
                    dp[ind]=max(dp[ind],dp[prev]+1);
            }
        }
        int maxi=dp[0];
        for(int i=1;i<n;i++)
            maxi=max(maxi,dp[i]);
        
        return maxi;
    }
};