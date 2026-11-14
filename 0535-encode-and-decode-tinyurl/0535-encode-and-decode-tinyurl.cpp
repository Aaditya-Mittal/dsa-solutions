class Solution {
public:
    vector<string> ans;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        ans.push_back(longUrl);
        return to_string(ans.size());
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return ans[stoi(shortUrl)-1];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));