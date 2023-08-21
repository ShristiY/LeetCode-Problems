class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<int>ahead(5,0),cur(5,0);
        
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=3;trans>=0;trans--)
            {
                if(trans%2==0)
                    cur[trans]=max(-arr[ind]+ahead[trans+1],ahead[trans]);
                else
                    cur[trans]=max(arr[ind]+ahead[trans+1],ahead[trans]);
            }
            ahead=cur;
        }
        return ahead[0];
    }
};