class Solution {
public:
    void func(vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int k, int index, int n)
    {
        if(k==0)
            {
                ans.push_back(ds);
                 return;
            }
        
        for(int i=index;i<n;i++)
        {
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>k) break;
            ds.push_back(arr[i]);
            func(arr,ans,ds,k-arr[i],i+1,n);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        func(arr,ans,ds,target,0,n);
        return ans;
    }
};