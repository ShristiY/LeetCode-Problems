class Solution {
public:
    long long func(vector<int>&nums,int threshold,int mid)
    {
        long long total=0;
        for(int i=0;i<nums.size();i++)
            total+=ceil(double(nums[i])/double(mid));
        
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
        }
        int l=1,h=maxi, ans=maxi;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(func(nums,threshold,mid)<=threshold)
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