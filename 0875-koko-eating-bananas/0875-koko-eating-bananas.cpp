class Solution {
public:
    long long func(int mid,vector<int>&arr,int h)
    {
        long long total=0;
        for(int i=0;i<arr.size();i++)
            total+=ceil((double(arr[i])/double(mid)));
        return total;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n=arr.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
            maxi=max(maxi,arr[i]);
        
        int l=1,high=maxi;
        int ans=maxi;
        while(l<=high)
        {
            int mid=l+(high-l)/2;
            if(func(mid,arr,h)<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};