class Solution {
public:
////////////////YHI DEKHOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO

bool solve(string &s, int l, int r, vector<vector<int>> &dp) {
    if (l >= r)
        return true;

    if (dp[l][r] != -1)
        return dp[l][r];

    if(s[l]==s[r])
        return dp[l][r]=solve(s,l+1,r-1,dp);
    
    return dp[l][r]=false;
}

string func(string s, vector<vector<int>> &dp) {
    int n = s.length();

    int maxlen = INT_MIN;
    int startingIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (solve(s, i, j, dp)) {
                if (j - i + 1 > maxlen) {
                    startingIndex = i;
                    maxlen = j - i + 1;
                }
            }
        }
    }

    return s.substr(startingIndex, maxlen);
}

string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return func(s, dp);
}

};