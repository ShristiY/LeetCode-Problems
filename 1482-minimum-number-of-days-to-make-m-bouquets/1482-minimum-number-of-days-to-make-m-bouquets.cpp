class Solution {
public:
    int findMin(vector<int>&arr)
    {
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++)
            ans=min(ans,arr[i]);
        return ans;
    }
    int findMax(vector<int>&arr)
    {
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++)
            ans=max(ans,arr[i]);
        return ans;
    }
    bool func(vector<int>&arr,int day,int m,int k)
    {
        int bouquets=0,flowers=0;
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
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=findMin(bloomDay),h=findMax(bloomDay);
        int ans=-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(func(bloomDay,mid,m,k)==true)
            {
                h=mid-1;
                ans=mid;
            }
            else
               l=mid+1;
        }
        return ans;
    }
};