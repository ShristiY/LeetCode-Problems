class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            int dist=x*x+y*y;
            
            pq.push({dist,{x,y}});
            if(pq.size()>k)
                pq.pop();
        }
        
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            vector<int>vec;
            vec.push_back(x);
            vec.push_back(y);
            ans.push_back(vec);
        }
        return ans;
    }
};