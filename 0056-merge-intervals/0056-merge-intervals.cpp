class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        if(n==0)
            return ans;
        sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
        vector<int>res;
        for(auto it:intervals){
            int start=it[0];
            int end=it[1];
            if(temp[1]>=start)
                temp[1]=max(temp[1],end);
                else
                {ans.push_back(temp);
                temp=it;
                }
            
        }
        ans.push_back(temp);
        return ans;
    }
};