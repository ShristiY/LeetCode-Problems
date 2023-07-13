class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int leftmax=0,rightmax=0;
        int ans=0;
        int l=0,r=n-1;
        while(l<=r)
        {
            if(arr[l]<=arr[r])
            {
                if(arr[l]>=leftmax)
                    leftmax=arr[l];
                else
                    ans+=leftmax-arr[l];
                
                l++;
            }
            else{
                if(arr[r]>=rightmax)
                    rightmax=arr[r];
                else
                    ans+=rightmax-arr[r];
                
                r--;
            }
        }
        return ans;
    }
};