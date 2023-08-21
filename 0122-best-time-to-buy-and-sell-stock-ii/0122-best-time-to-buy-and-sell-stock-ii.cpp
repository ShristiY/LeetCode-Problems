class Solution {
public:
    int maxProfit(vector<int>& a) {
         int n=a.size();
        vector<int>ahead(2,0),cur(2,0);
        ahead[0]=0;
        ahead[1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j>=0;j--)
            {
                int pro;
                if(j==0)
                {
                    pro=max(-a[i]+ahead[1],0+ahead[0]);
                }
                else
                {
                    pro=max(a[i]+ahead[0],0+ahead[1]);
                }
                cur[j]=pro;
            }
            ahead=cur;
        }
        return ahead[0];
    }
};