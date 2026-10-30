class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, maxi = INT_MIN;
        for(int i = prices.size()-1; i >= 0; i--){
            maxi = max(prices[i], maxi);
            ans = max(maxi - prices[i], ans);
        }
        return ans;
    }
};