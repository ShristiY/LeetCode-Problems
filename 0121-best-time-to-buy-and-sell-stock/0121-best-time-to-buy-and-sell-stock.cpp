class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxP=0;
        int minn=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            maxP=max(maxP,nums[i]-minn);
            minn=min(minn,nums[i]);
        }
        return maxP;
    }
};