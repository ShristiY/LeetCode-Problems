class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        
        int longestStreak=0;
        for(auto it:st)
        {
            if(st.count(it-1)==0)
            {
                int currNum=it;
                int currStreak=1;
            while(st.count(currNum+1)==1)
            {
                currNum+=1;
                currStreak+=1;
            }
            longestStreak=max(longestStreak,currStreak);
            
        }
        }
        return longestStreak;
    }
};