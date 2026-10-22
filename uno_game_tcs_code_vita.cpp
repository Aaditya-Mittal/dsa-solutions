#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm> 
#include <numeric>
using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define uii            unordered_map <int, int>
#define upi            unordered_map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl


void solve() {
    int n;
    cin >> n;

    vector<string> names(n);
    vi skill(n);

    for (int i = 0; i < n; i++) cin >> names[i];
    for (int i = 0; i < n; i++) cin >> skill[i];

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) mp[names[i]] = i;

    int n1;
    cin >> n1;
    vpi friends(n1);
    vector<bool> is_paired(n, false); 
    for (int i = 0; i < n1; i++) {
        string a, b;
        cin >> a >> b;
        friends[i] = {mp[a], mp[b]};
        is_paired[mp[a]] = true;
        is_paired[mp[b]] = true; 
    }

    int n2;
    cin >> n2;
    vpi rivals(n2);
    for (int i = 0; i < n2; i++) {
        string a, b;
        cin >> a >> b;
        rivals[i] = {mp[a], mp[b]};
    }

    int limit;
    cin >> limit;

    vpi items; 
    vi item_player_mask; 
    for (int i = 0; i < n1; i++) {
        int a = friends[i].F;
        int b = friends[i].S;
        items.pb({skill[a] + skill[b], 2});
        item_player_mask.pb((1LL << a) | (1LL << b));
    }

    for (int i = 0; i < n; i++) {
        if (!is_paired[i]) {
            items.pb({skill[i], 1});
            item_player_mask.pb(1LL << i);
        }
    }

    int m = sz(items); 

    vi dp_skill(1 << m, 0);
    vi dp_count(1 << m, 0);
    vi dp_player_mask(1 << m, 0);

    for (int i = 0; i < m; ++i) {
        for (int mask = 0; mask < (1 << i); ++mask) {
            int next_mask = mask | (1 << i);
            dp_skill[next_mask] = dp_skill[mask] + items[i].F;
            dp_count[next_mask] = dp_count[mask] + items[i].S;
            dp_player_mask[next_mask] = dp_player_mask[mask] | item_player_mask[i];
        }
    }

    int maxPlayers = 0;

    for (int mask = 0; mask < (1 << m); mask++) {

        if (dp_skill[mask] > limit) continue;

        int player_mask = dp_player_mask[mask];
        bool valid = true;

        for (auto &r : rivals) {
            int a = r.F, b = r.S;
            if ((player_mask & (1LL << a)) && (player_mask & (1LL << b))) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;

        maxPlayers = max(maxPlayers, dp_count[mask]);
    }
    
    cout << maxPlayers << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}