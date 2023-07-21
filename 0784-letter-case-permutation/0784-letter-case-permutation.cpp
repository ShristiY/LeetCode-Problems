class Solution {
public:
    void func(vector<string>&ans,string s, int index)
    {
        if(index==s.size()){
            ans.push_back(s);
            return;
        }
        
        char temp=s[index];
        if(isupper(s[index]))
            s[index]=tolower(s[index]);
        else 
            s[index]=toupper(s[index]);
        func(ans,s,index+1);
        
        if(isalpha(temp))
        {   s[index]=temp;
        func(ans,s,index+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        func(ans,s,0);
        return ans;
    }
};