class Solution {
public:
    //IInd approach
    int findDuplicate(vector<int>& nums) {
        int ans;
        int n=nums.size();
        vector<int>freq(n,0);
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(freq[i]>1)
                ans=i;
        }
        return ans;
    }
};