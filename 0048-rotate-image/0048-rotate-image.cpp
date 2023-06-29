class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>dum(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dum[j][n-i-1]=mat[i][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j]=dum[i][j];
            }
        }
    }
};