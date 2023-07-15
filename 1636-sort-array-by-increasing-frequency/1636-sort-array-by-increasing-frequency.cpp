class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        //EASY AND BEST SOLUTION
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        int count=0;
        for(auto it:mp)
        {
            int num=it.first;
            int freq=-(it.second);
            pq.push({freq,num});
        }
        while(!pq.empty())
        {
            int num=pq.top().second;
            count=-(pq.top().first);
            while(count!=0)
            {
                count--;
                ans.push_back(num);
            }
            pq.pop();
        }
        return ans;
    }
};