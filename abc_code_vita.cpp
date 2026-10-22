#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm> // For std::next_permutation, std::max
#include <sstream>   // For std::stringstream
#include <climits>   // For INT_MAX

using namespace std;

/**
 * @brief Calculates the Longest Common Subsequence (LCS) of two strings.
 * Uses a standard O(N*M) dynamic programming approach.
 * @param s1 The first string (as a vector of chars).
 * @param s2 The second string (as a vector of chars).
 * @return The length of the LCS.
 */
int lcs(const vector<char>& s1, const vector<char>& s2) {
    int n = s1.size();
    if (n == 0) return 0;

    // dp[i][j] = LCS of s1[0...i-1] and s2[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match, extend the previous LCS
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Characters don't match, take the max of skipping one
                // from s1 or skipping one from s2.
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int main() {
    // 1. Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 2. Read N
    int n;
    cin >> n;

    // 3. Read the original string S and count A, B, C
    vector<char> s(n);
    map<char, int> counts;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        counts[s[i]]++;
    }

    // 4. Read the fixed positions (1-based)
    // We store them as 0-based index and the required char.
    vector<pair<int, char>> fixed;
    string line;
    
    // Consume the newline character left by cin >>
    getline(cin, line); 
    
    // Read the actual line of fixed positions
    getline(cin, line);
    stringstream ss(line);
    int pos;
    while (ss >> pos) {
        fixed.push_back({pos - 1, s[pos - 1]}); // {0-based index, required char}
    }

    // 5. Iterate through all 6 permutations of (A, B, C)
    vector<char> p = {'A', 'B', 'C'};
    sort(p.begin(), p.end()); // Start with "A, B, C"

    int min_shifts = INT_MAX;
    bool possible = false;

    do {
        // a. Construct the target string T for this permutation
        vector<char> t;
        for (char owner : p) {
            t.insert(t.end(), counts[owner], owner);
        }

        // b. Check if this target T is valid
        bool valid = true;
        for (const auto& fix : fixed) {
            if (t[fix.first] != fix.second) {
                valid = false;
                break;
            }
        }

        // c. If valid, calculate shifts and update minimum
        if (valid) {
            possible = true;
            int current_lcs = lcs(s, t);
            min_shifts = min(min_shifts, n - current_lcs);
        }

    } while (next_permutation(p.begin(), p.end()));

    // 6. Print the result
    if (!possible) {
        cout << "Impossible" << endl;
    } else {
        cout << min_shifts << endl;
    }

    return 0;
}