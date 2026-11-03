class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> unique;
        unordered_map<int,int> mp;
        for(int x: nums) mp[x]++;
        for(pair<int,int> a: mp) unique.push_back(a.first);
        sort(unique.begin(), unique.end(), [&mp](int a, int b){
            if(mp[a]>mp[b]) return true;
            return false;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(unique[i]);
        }
        return ans;
    }
};