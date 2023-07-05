class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        vector<int>ans;
        int res=-1;
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==x)
            {
                res=mid;
                h=mid-1;
            }
            else if(nums[mid]<x)
                l=mid+1;
            else h=mid-1;
        }
        ans.push_back(res);
        res=-1;
        l=0,h=nums.size()-1;
            while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]==x)
            {
                res=mid;
                l=mid+1;
            }
            else if(nums[mid]<x)
                l=mid+1;
            else h=mid-1;
        }
        ans.push_back(res);
        return ans;
    }
};