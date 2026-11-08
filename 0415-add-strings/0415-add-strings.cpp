class Solution {
public:
    string addStrings(string n1, string n2) {
        int n = n1.size(), m = n2.size();
        if(n > m){
            n2 = string(n-m, '0') + n2;
        }
        else{
            n1 = string(m-n, '0') + n1;
        }
        string ans = "";
        int carry = 0;
        for(int i = max(m,n)-1; i>=0; i--){
            int a = n1[i] - '0';
            int b = n2[i] - '0';
            int c = a+b+carry;
            if(c>9) carry = 1;
            else carry = 0;
            c = c%10;
            char temp  = c + '0';
            ans = temp + ans;
        }
        if(carry) ans = "1" + ans;
        return ans;
    }
};