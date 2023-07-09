class Solution {
public:
    int findMax(vector<int>&nums)
    {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
            ans=max(ans,nums[i]);
        return ans;
    }
    int func(vector<int>&nums,int day)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=(ceil)((double)(nums[i])/(double)(day));
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,h=findMax(nums);
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(func(nums,mid)<=threshold)
            {
                ans=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};