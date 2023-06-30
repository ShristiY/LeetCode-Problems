class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        vector<int>store;
        int n=nums.size();
        int n1,n2;
        store=nums;
        sort(store.begin(),store.end());
        int l=0,r=n-1;
        while(l<r)
        {
            if(store[l]+store[r]==target)
            {
                n1=store[l];
                n2=store[r];
                break;
            }
            else if(store[l]+store[r]<target)
            l++;
            else
            r--;
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]==n1)
            ans.push_back(i);
           else if(nums[i]==n2)
            ans.push_back(i);
        }
        return ans;
    }
};