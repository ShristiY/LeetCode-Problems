class Solution {
public:

    int change(int T, vector<int>& arr) {
        int n=arr.size();
         vector<vector<long>> dp(n,vector<long>(T+1,0));
    for(int i=0;i<=T;i++)
    {
        if(i%arr[0]==0)
            dp[0][i]=1;
    }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=T;target++)
            {
                long notTake=dp[ind-1][target];
                long take=0;
                if(arr[ind]<=target)
                    take=dp[ind][target-arr[ind]];
                
                dp[ind][target]=take+notTake;
            }
        }
        return dp[n-1][T];
    }
};