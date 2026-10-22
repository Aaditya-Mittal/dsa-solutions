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
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

void debug_out() {
    cerr << endl;
}

template<typename T, typename... Args>
void debug_out(T a, Args... args) {
    cerr << a << " ";
    debug_out(args...);
}



void solve() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        vector<int> e;

        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            if(x%2 == 0) e.pb(x);
            v.pb(x);
        }

        if(e.size() >= 2){
            cout<<e[0]<<" "<<e[1];
            cout<<endl;
            continue;
        }

        if(v[0] == 1){
            cout<<v[0]<<" "<<v[1];
            cout<<endl;
            continue;
        }

        int flag = 0;
        for(int i = 0; i<v.size() - 1; i++){
            for(int j = i + 1; j<v.size(); j++){
                if( (v[j] % v[i]) % 2 ==0) {
                    cout<<v[i]<<" "<<v[j]; 
                    cout<<endl;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout<<"-1"<<endl;
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    clock_t z = clock();

    solve();
    
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

