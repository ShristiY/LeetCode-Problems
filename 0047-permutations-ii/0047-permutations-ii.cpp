class Solution {
public:
    void func(vector<int>nums, vector<vector<int>>&ans,int index, int n)
    {
        if(index==n-1)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=index;i<n;i++)
        {
            if(i>index && nums[i]==nums[index]) continue;
            
            swap(nums[i],nums[index]);
            func(nums,ans,index+1,n);
            // swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        func(nums,ans,0,n);
        return ans;
    }
};