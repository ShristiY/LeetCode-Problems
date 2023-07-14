class Solution {
public:
    bool func(int day,vector<int>&arr,int m,int k)
    {
        int flowers=0,bouquets=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=day)
                flowers++;
            else{
                bouquets+=flowers/k;
                flowers=0;
            }
        }
        bouquets+=flowers/k;
        if(bouquets>=m) return true;
        return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
        int ans=-1;
        int l=mini,h=maxi;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(func(mid,arr,m,k)==true)
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