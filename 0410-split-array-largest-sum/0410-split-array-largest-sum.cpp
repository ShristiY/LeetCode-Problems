class Solution {
public:
    int func(int mid,vector<int>&arr,int k)
    {
        int painters=1;
        long long curr=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]+curr<=mid)
                curr+=arr[i];
        else
        {
            painters++;
            curr=arr[i];
        }
        }
        return painters;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN, sum=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int l=maxi,h=sum;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(func(mid,nums,k)<=k)
                h=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};