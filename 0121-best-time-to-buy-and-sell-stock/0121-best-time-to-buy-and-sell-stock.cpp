class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxP=0;
        int minn=prices[0];
        for(int i=1;i<n;i++)
        {
            int cost=prices[i]-minn;
            maxP=max(maxP,cost);
            minn=min(minn,prices[i]);
        }
        return maxP;
    }
};