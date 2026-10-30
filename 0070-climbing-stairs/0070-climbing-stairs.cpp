class Solution {
public:
    int climbStairs(int n) {
        if(n==1  || n==0) return 1;
        int a = 1;
        int b = 1;
        int ans = 1;
        for(int i = 2; i<=n; i++){
            ans = a+b;
            a = b;
            b = ans;
        }
        return ans;

    }
};