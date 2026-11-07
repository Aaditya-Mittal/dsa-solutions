class Solution {
public:
    string convertToBase7(int num) {
        int x = abs(num);
        if(x==0) return "0";
        string ans = "";
        while(x){
            ans = to_string(x%7) + ans;
            x/=7;
        }
        if(num<0) return "-"+ans;
        return ans;
    }
};