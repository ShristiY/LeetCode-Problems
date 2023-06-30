class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int count1=0, count2=0, ele1,ele2;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(count1==0 && nums[i]!=ele2)
            {
                count1++;
                ele1=nums[i];
            }
            else if(count2==0 && nums[i]!=ele1)
            {
                count2++;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
                count1++;
            else if(nums[i]==ele2)
                count2++;
            else{
                count1--;
                count2--;
            }
        }
        
        int check1=0,check2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele1)
                check1++;
            else if(nums[i]==ele2)
                check2++;
        }
        if(check1>n/3)
            ans.push_back(ele1);
        if(check2>n/3)
            ans.push_back(ele2);
        
        return ans;
    }
};