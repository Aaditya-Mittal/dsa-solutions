class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, set<char>> mp;
        unordered_map<char, set<char>> mp2;
        for(int i = 0; i<s.length(); i++){
            mp[s[i]].insert(t[i]);
            if(mp[s[i]].size() > 1) return false;
            mp2[t[i]].insert(s[i]);
            if(mp2[t[i]].size() > 1) return false;
        }
        return true;
    }
};