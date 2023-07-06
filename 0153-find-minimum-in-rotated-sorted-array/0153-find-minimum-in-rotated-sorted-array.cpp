class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return -1;
        if(nums[0]<nums[n-1]) return nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
                return nums[i];
        }
        return nums[0];
    }
};