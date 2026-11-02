class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> temp;
        int n= strs.size();
        for(int i=0; i<n; i++){
            string a = strs[i];
            sort(a.begin(), a.end());
            temp[a].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(pair<string, vector<string>> t:temp){
            ans.push_back(t.second);
        }
        return ans;
    }
};