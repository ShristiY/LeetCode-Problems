class Solution {
public:
    int climbStairs(int n) {
        //Most optimised
        int prev=1;
        int prev2=1;
        for(int i=2;i<=n;i++)
        {
            int cur=prev+prev2;
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};