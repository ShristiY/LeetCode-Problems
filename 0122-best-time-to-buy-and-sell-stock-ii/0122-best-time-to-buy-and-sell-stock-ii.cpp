class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            
                dp[ind][0]=max(-arr[ind]+dp[ind+1][1],dp[ind+1][0]);
            
                dp[ind][1]=max(arr[ind]+dp[ind+1][0],dp[ind+1][1]);
        }
        return dp[0][0];
    }
};