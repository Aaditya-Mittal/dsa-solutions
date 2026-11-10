class Solution {
public:
    int helper(int x){
        int ans = 0;
        while(x){
            int temp = x%10;
            ans+=temp;
            x/=10;
        }
        return ans;
    }

    int countLargestGroup(int n) {
        unordered_map<int, int> x;
        int maxi = -1;
        for(int i = 1; i<=n; i++){
            int temp = helper(i);
            x[temp]++;
            if(x[temp] > maxi){
                maxi = x[temp];
            }
        }

        int count = 0;

        for (auto it : x) {
            if (it.second == maxi) {
                count++;
            }
        }

        return count;
    }
};