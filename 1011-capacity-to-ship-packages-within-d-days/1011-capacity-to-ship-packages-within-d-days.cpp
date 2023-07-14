class Solution {
public:
    int func(int mid,vector<int>&arr,int totalDays)
    {
        int days=1,load=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]+load<=mid)
                load+=arr[i];
            else
            {
                days++;
                load=arr[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {sum+=arr[i];
         maxi=max(maxi,arr[i]);
        }
        
        int l=maxi,h=sum,ans=sum;
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(func(mid,arr,days)<=days)
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