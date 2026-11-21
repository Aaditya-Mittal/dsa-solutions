class Solution {
public:
    int helper(string &word, unordered_set<char> &st){
        int n = word.size();
        if(!n) return 0;
        for(int i = 0; i < n; i++){
            if(st.count(word[i])) return 0;
        }
        return 1;
    }

    int canBeTypedWords(string text, string b) {
        unordered_set<char> st;
        for(char c: b){
            st.insert(c);
        }
        string word = "";
        int i = 0, n = text.size();
        int count = 0;
        while(i<n){
            if(text[i]==' '){
                count += helper(word, st);
                word = "";
            }
            else word+=text[i];
            i++;
        }
        count+= helper(word,st);
        return count;
    }
};