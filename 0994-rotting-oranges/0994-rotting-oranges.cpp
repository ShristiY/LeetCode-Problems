class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0, freshCount=0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                 else if(grid[i][j]==1)
                    freshCount++;
            }
        }
        int time=0;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int tm=q.front().second;
            time=max(time,tm);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+delRow[i];
                int ncol=c+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
                {
                    count++;
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},tm+1});
                }
            }
        }
        if(count==freshCount) return time;
        return -1;
    }
};