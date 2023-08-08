class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&ans,vector<vector<int>>&image, int delRow[], int delCol[], int ini, int newCol)
    {
        ans[r][c]=newCol;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=r+delRow[i];
            int ncol=c+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==ini && ans[nrow][ncol]!=newCol)
                dfs(nrow,ncol,ans,image,delRow,delCol,ini,newCol);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int initial=image[sr][sc];
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,delRow,delCol,initial,color);
        return ans;
    }
};