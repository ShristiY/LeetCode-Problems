class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=3;trans>=0;trans--)
            {
                if(trans%2==0)
                    dp[ind][trans]=max(-arr[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
                else
                    dp[ind][trans]=max(arr[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
            }
        }
        return dp[0][0];
    }
};