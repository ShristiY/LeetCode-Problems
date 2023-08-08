class Solution {
public:
    bool detect(int node,vector<vector<int>>&graph,vector<int>&color)
    {
        // color[node]=0;
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=!color[node];
                if(detect(it,graph,color)==false)
                    return false;
            }
            else if(color[it]==color[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                if(detect(i,graph,color)==false)
                    return false;
            }
        }
        return true;
    }
};