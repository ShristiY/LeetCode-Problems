class Solution {
public:

    int change(int T, vector<int>& arr) {
        int n=arr.size();
         vector<long>prev(T+1,0),cur(T+1,0);
    for(int i=0;i<=T;i++)
    {
        if(i%arr[0]==0)
            prev[i]=1;
    }
        
        for(int ind=1;ind<n;ind++)
        {
            for(int target=0;target<=T;target++)
            {
                long notTake=prev[target];
                long take=0;
                if(arr[ind]<=target)
                    take=cur[target-arr[ind]];
                
                cur[target]=take+notTake;
            }
            prev=cur;
        }
        return prev[T];
    }
};