class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>maxh;
        for(auto it:points)
        {
            int x=it[0]*it[0];
            int y=it[1]*it[1];
            int res=x+y;
            maxh.push({res,{it[0],it[1]}});
            if(maxh.size()>k)
                maxh.pop();
        }
        while(!maxh.empty())
        {
            int res=maxh.top().first;
            int xaxis=maxh.top().second.first;
            int yaxis=maxh.top().second.second;
            maxh.pop();
            vector<int>temp;
            temp.push_back(xaxis);
            temp.push_back(yaxis);
            ans.push_back(temp);
        }
        return ans;
    }
};