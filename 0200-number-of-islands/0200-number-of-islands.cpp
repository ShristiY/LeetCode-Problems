class Solution {
public:
void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1 || grid[x][y] == '0') {
        return;
    }
    vis[x][y] = 1;
    dfs(x + 1, y, vis, grid);
    dfs(x - 1, y, vis, grid);
    dfs(x, y + 1, vis, grid);
    dfs(x, y - 1, vis, grid);
}

    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        if(n==0) return 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if (grid[i][j]=='1' && !vis[i][j])
                {
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};