class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1)
                    fresh++;                    
            }
        }
        int time=0;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            time=max(time,tm);
            for(int i=0;i<4;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=2;
                    cnt++;
                    q.push({{nrow,ncol},tm+1});
                }
            }  
        }
        if(cnt==fresh) return time;
        return -1;
    }
};