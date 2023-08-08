class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int topo=0;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto p:pre)
        {
            adj[p[1]].push_back(p[0]);
        }
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
                indegree[it]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(topo==n) return true;
        return false;
    }
};