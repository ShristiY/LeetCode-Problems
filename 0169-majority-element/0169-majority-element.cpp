class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0,ele;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count++;
                ele=nums[i];
            }
            else if(ele==nums[i])
                count++;
            else
                count--;
        }
        
        //checking 
        int check=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==ele)
                check++;
        }
        if(check>n/2)
            return ele;
        return -1;
    }
};