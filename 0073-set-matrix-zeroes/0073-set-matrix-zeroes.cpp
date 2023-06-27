class Solution {
public:
    //IInd Approach
    
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>dumR(m,-1);
        vector<int>dumC(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dumR[j]=0;
                    dumC[i]=0;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dumR[j]==0 || dumC[i]==0)
                    mat[i][j]=0;
            }
        }
    }
};