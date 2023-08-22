class Solution {
public:
  
    int maxProfit(vector<int>&  arr) {
        int n=arr.size();
        vector<vector<int>>ahead(2,vector<int>(3,0)),cur(2,vector<int>(3,0));
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int cap=1;cap<=2;cap++)
            {
                cur[0][cap]=max(-arr[ind]+ahead[1][cap],0+ahead[0][cap]);
                
                cur[1][cap]=max(arr[ind]+ahead[0][cap-1],0+ahead[1][cap]);
                
            }
            ahead=cur;
        }
        return ahead[0][2];
    }
};