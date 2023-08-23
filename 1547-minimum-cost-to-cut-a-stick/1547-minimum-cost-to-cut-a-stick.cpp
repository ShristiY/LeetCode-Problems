class Solution {
public:
int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
if(i>j)
return 0;

if(dp[i][j] != -1)
return dp[i][j];

int res= INT_MAX;
for(int k=i; k<=j; k++){
   int cost= (cuts[j+1]-cuts[i-1])+ func(i,k-1,cuts,dp)+ func(k+1,j,cuts,dp);
res= min(res,cost);
}
return dp[i][j]=res;
  }

    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
     
        vector<vector<int>> dp(m+1, vector<int>(m+1,-1));
        return func(1,m,cuts,dp);
    }
};