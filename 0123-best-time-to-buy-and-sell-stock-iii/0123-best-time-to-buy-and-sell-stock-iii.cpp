class Solution {
public:
  
    int maxProfit(vector<int>&  arr) {
        int n=arr.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int cap=1;cap<=2;cap++)
            {
                dp[ind][0][cap]=max(-arr[ind]+dp[ind+1][1][cap],0+dp[ind+1][0][cap]);
                
                dp[ind][1][cap]=max(arr[ind]+dp[ind+1][0][cap-1],0+dp[ind+1][1][cap]);
                
            }
        }
        return dp[0][0][2];
    }
};