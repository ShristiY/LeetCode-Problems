class Solution {
public:
       int solve(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++)
        {
            int pick=nums[i];
            if(i>1)
                pick+=prev2;
            int notPick=prev;
            int curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int>firstIn,lastIn;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0) lastIn.push_back(nums[i]);
            if(i!=n-1) firstIn.push_back(nums[i]);
        }
        int ans1=solve(firstIn);
        int ans2=solve(lastIn);
        return max(ans1,ans2);
    }
};