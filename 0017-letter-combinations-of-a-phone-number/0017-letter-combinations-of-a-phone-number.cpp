class Solution {
public:

//THIS CODE IS UNDERSTANDABLE(BY LOVE BABBAR) NOT THE PREVIOUS ONE
void func(vector<string>&ans,string ds,vector<string>&mp,string digits,int ind)
{
    if(ind==digits.size())
    {
        ans.push_back(ds);
        return;
    }
    int currNum=digits[ind]-'0'; // to convert string to integer
    string val=mp[currNum];
    for(int i=0;i<val.size();i++)
    {
        ds.push_back(val[i]);
        func(ans,ds,mp,digits,ind+1);
        ds.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string ds;
        if(digits.size()==0)
        return ans;
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        func(ans,ds,mp,digits,0);
        return ans;
    }
};