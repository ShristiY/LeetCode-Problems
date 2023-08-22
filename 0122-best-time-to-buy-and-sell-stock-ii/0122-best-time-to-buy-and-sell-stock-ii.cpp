class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<int>ahead(2,0),cur(2,0);
        ahead[0]=0;
        ahead[1]=0;
        
        for(int ind=n-1;ind>=0;ind--)
        {
            
                cur[0]=max(-arr[ind]+ahead[1],ahead[0]);
            
                cur[1]=max(arr[ind]+ahead[0],ahead[1]);
            ahead=cur;
        }
        return ahead[0];
    }
};