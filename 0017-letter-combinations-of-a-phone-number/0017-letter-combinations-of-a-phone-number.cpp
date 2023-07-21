class Solution {
public:
    void func(string digits, vector<string>&ans, string ds, vector<string>&mp, int index)
    {
        if(index==digits.size())
        {
            ans.push_back(ds);
            return;
        }
        
        int currNum=digits[index]-'0'; // to convert from string to integer.
        string value=mp[currNum];
        for(int i=0;i<value.size();i++)
        {
            ds.push_back(value[i]);
            func(digits,ans,ds,mp,index+1);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string ds;
        int n=digits.size();
        if(n==0)
            return ans;
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        func(digits,ans,ds,mp,0);
        return ans;
    }
};