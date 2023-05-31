class Solution {
public:
    struct compare{
    bool operator()(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first){
            {
                if(a.second<b.second)return true;
                return false;
            }
        }
        return a.first>b.first;
    }
    };
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        
        for(auto it:mp)
        {
            int ele=it.first;
            int freq=it.second;
            pq.push({freq,ele});
        }
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int freq=it.first;
            int num=it.second;
            while(freq>0)
            {
                ans.push_back(num);
                freq--;
            }
            pq.pop();
        }
        return ans;
    }
};