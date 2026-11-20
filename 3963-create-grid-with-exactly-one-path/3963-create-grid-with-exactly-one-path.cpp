class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        ans[0] = string(n, '.');
        for(string &a:ans){
            a[n-1] = '.';
        }
        return ans;
    }
};