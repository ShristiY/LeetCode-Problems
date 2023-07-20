class Solution {
public:
    void func(vector<int>&arr,vector<vector<int>>&ans, vector<int>&ds,int k,int ind,int n)
    {
        if(ind==n)
        {
            if(k==0)
            {ans.push_back(ds);
            }
            return;
        }
        
        if(arr[ind]<=k)
        {
            ds.push_back(arr[ind]);
            func(arr,ans,ds,k-arr[ind],ind,n);
            ds.pop_back();
        }
        func(arr,ans,ds,k,ind+1,n);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=arr.size();
    
        func(arr,ans,ds,target,0,n);
        return ans;
    }
};