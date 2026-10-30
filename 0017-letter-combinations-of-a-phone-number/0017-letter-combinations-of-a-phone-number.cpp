class Solution {
public:
    void helper(int i, string &digits, vector<string> &s, string curr){
        if(i==digits.size()){
            s.push_back(curr);
            return;
        }
        char d = digits[i];
        if(d=='2'){
            helper(i+1, digits,s,curr+"a");
            helper(i+1, digits,s,curr+"b");
            helper(i+1, digits,s,curr+"c");
        }
        else if(d=='3'){
            helper(i+1, digits,s,curr+"d");
            helper(i+1, digits,s,curr+"e");
            helper(i+1, digits,s,curr+"f");
        }
        else if(d=='4'){
            helper(i+1, digits,s,curr+"g");
            helper(i+1, digits,s,curr+"h");
            helper(i+1, digits,s,curr+"i");
        }
        else if(d=='5'){
            helper(i+1, digits,s,curr+"j");
            helper(i+1, digits,s,curr+"k");
            helper(i+1, digits,s,curr+"l");
        }
        else if(d=='6'){
            helper(i+1, digits,s,curr+"m");
            helper(i+1, digits,s,curr+"n");
            helper(i+1, digits,s,curr+"o");
        }
        else if(d=='7'){
            helper(i+1, digits,s,curr+"p");
            helper(i+1, digits,s,curr+"q");
            helper(i+1, digits,s,curr+"r");
            helper(i+1, digits,s,curr+"s");
        }
        else if(d=='8'){
            helper(i+1, digits,s,curr+"t");
            helper(i+1, digits,s,curr+"u");
            helper(i+1, digits,s,curr+"v");
        }
        else {
            helper(i+1, digits,s,curr+"w");
            helper(i+1, digits,s,curr+"x");
            helper(i+1, digits,s,curr+"y");
            helper(i+1, digits,s,curr+"z");
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        helper(0, digits, ans, "");
        return ans;
    }
};