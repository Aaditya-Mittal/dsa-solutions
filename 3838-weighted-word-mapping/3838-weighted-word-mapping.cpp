class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string s: words){
            int temp = 0;
            for(char c: s){
                temp += weights[c-'a'];
            }
            temp%=26;
            ans+= 'z' - temp;
        }
        return ans;
    }
};