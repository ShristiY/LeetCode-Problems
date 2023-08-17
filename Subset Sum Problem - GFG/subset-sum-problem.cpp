//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool isSubsetSum(vector<int>&arr, int k){
        //MOST OPTIMISED 
        int n=arr.size();
        vector<bool>prev(k+1,false),cur(k+1,false);
        prev[0]=true;
        if(arr[0]<=k)
        prev[arr[0]]=true;
        
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=k;target++)
            {
                bool take=false;
                if(target>=arr[ind])
                take=prev[target-arr[ind]];
                bool notTake=prev[target];
                cur[target]=take||notTake;
            }
            prev=cur;
        }
        return prev[k];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends