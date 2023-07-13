class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || (arr[st.top()]>=arr[i])))
            {
                int height=arr[st.top()];
                st.pop();
                int width;
                
                if(st.empty())
                    width=i;
                else
                    width=i-st.top()-1;
                maxi=max(maxi,height*width);
            }
            st.push(i);
        }
        return maxi;
    }
};