class Solution {
public:
    //most optimised
   
    int minimumTotal(vector<vector<int>>& mat) {
        int n=mat.size();
        
        vector<int>front(n,0);
        for(int j=0;j<n;j++)
            front[j]=mat[n-1][j];
        
        for(int i=n-2;i>=0;i--)
        {
            vector<int>cur(n,0);
            for(int j=i;j>=0;j--)
            {
                int down=mat[i][j]+front[j];
                int dia=mat[i][j]+front[j+1];
                
                cur[j]=min(down,dia);
            }
            front=cur;
        }
        return front[0];
        
    }
};