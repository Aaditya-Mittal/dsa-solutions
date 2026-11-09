class Solution {
public:
    int helper(int x){
        int a = 0;
        while(x){
            x = x&(x-1);
            a+=1;
        }
        return a;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b){
            int x = helper(a);
            int y = helper(b); 
            if(x==y) return a < b;
            return x < y;
        });
        return arr; 
    }
};