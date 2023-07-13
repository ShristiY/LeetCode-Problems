class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            
            if(st.empty()) left[i]=0;
            else 
                left[i]=st.top()+1;
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        vector<int>right(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            
            if(st.empty()) right[i]=n-1;
            else 
                right[i]=st.top()-1;
            
            st.push(i);
        }
        
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]*(right[i]-left[i]+1));
        }
        
        return maxi;
        
    }
};