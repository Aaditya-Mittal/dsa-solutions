#include <bits/stdc++.h>
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
#define bug(...)       cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
    int x = 1;
    while (b)
   {
        if(b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

void debug_out(){ cerr << endl; }

template<typename T, typename... Args>
void debug_out(T a, Args... args){ cerr << a << " "; debug_out(args...); }

int MOD = 998244353;

void solve(){
    int n;
    cin >> n;

    vector<string> names(n);
    vi skill(n);

    for(int i = 0; i < n; i++) cin >> names[i];
    for(int i = 0; i < n; i++) cin >> skill[i];

    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++) mp[names[i]] = i;

    int n1; 
    cin >> n1;
    vpi friends;
    for(int i = 0; i < n1; i++){
        string a, b; 
        cin >> a >> b;
        friends.pb({mp[a], mp[b]});
    }

    int n2; 
    cin >> n2;
    vpi rivals;
    for(int i = 0; i < n2; i++){
        string a, b; 
        cin >> a >> b;
        rivals.pb({mp[a], mp[b]});
    }

    int limit; 
    cin >> limit;

    int maxPlayers = 0;

    for(int mask = 0; mask < (1 << n); mask++){
        int sumSkill = 0;
        int count = 0;
        bool valid = true;

        for(auto &f : friends){
            int a = f.F, b = f.S;
            bool inA = (mask & (1 << a));
            bool inB = (mask & (1 << b));
            if(inA != inB){ valid = false; break; }
        }
        if(!valid) continue;

        for(auto &r : rivals){
            int a = r.F, b = r.S;
            bool inA = (mask & (1 << a));
            bool inB = (mask & (1 << b));
            if(inA && inB){ valid = false; break; }
        }
        if(!valid) continue;

        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                sumSkill += skill[i];
                count++;
            }
        }
        if(sumSkill <= limit) maxPlayers = max(maxPlayers, count);
    }
    cout << maxPlayers << endl;
}

int32_t main(){

    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    clock_t z = clock();
    solve();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << "s" << endl;

    return 0;
}
