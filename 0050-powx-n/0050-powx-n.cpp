class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        long long N = n;
        while(N){
            if(N&1) result = result *  x;
            x = x * x;
            N/=2;
        }
        if(n<0){
            result=1/result;
        }
        return result;
    }
};