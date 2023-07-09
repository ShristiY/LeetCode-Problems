class Solution {
public:
    int func(vector<int>&arr,int cap)
    {
        int days=1,load=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]+load<=cap)
                load+=arr[i];
            else{
                load=arr[i];
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<weights.size();i++)
        {
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }
        int required=INT_MAX;
        int l=maxi,h=sum;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            int cur=func(weights,mid);
            if(cur<=days)
            {
                required=min(required,cur);
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return l;
        
    }
};