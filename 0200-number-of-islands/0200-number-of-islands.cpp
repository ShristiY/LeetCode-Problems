class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<int>>&vis)
    {
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=r+delRow[i];
            int ncol=c+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
            {
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};