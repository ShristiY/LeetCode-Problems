class Solution {
public:

    int numDistinct(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<double>prev(m+1,0),cur(m+1,0);
        
       cur[0]=1; 
        prev[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    cur[j]=prev[j-1]+prev[j];
                else
                    cur[j]=prev[j];
            }
                prev=cur;
        }
        return (int)prev[m];
    }
};