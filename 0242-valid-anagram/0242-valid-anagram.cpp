class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;
    
    vector<int> arr(26,0); // like a hashmap

    for (int i = 0; i < s.size(); i++)
        arr[s[i] - 'a']++;

    for (int i = 0; i < t.size(); i++) {
        int freq = arr[t[i] - 'a'] - 1;

        if (freq < 0)
            return false;
        
        // Update the frequency in the array
        arr[t[i] - 'a']--;
    }

    return true;
}

};