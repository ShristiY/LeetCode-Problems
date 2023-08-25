class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<int>prev(m,0),cur(m,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                    cur[j]=1;
                else{
                    int up=0,left=0;
                    if(i>0)
                        up=prev[j];
                    if(j>0)
                        left=cur[j-1];
                    cur[j]=up+left;
                }
            }
            prev=cur;
        }
        return prev[m-1];
    }
};