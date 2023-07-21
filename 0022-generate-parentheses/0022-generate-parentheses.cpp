class Solution {
public:
    void func(vector<string>&ans, string s, int op, int cl)
    {
        if(op==0 && cl==0) 
        {
            ans.push_back(s);
            return;
        }
        
        if(op!=0)
            func(ans,s+'(',op-1,cl);
        if(cl>op)
            func(ans,s+')',op,cl-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        int op=n,cl=n;
        func(ans,s,op,cl);
        return ans;
    }
};