class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n,1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(dp[prev]+1>dp[i] && nums[i]%nums[prev]==0)
                {
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
        }
        int ans=-1;
        int index=-1;
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>ans)
            {
                ans=dp[i];
                index=i;
            }
        }
        temp.push_back(nums[index]);
        while(hash[index]!=index)
        {
            index=hash[index];
            temp.push_back(nums[index]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};