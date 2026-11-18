class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0;
        unordered_map<int,int> mp;
        while(n){
            mp[n%10]++;
            n/=10;
        }
        for(pair<int,int> x:mp){
            ans += x.first * x.second;
        }
        return ans;
    }
};