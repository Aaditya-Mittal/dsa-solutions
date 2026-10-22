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
        int n, m;
        cin>>n>>m;

        int ans = 0;

        que_min sword1;

        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            sword1.push(x);
        }

        vector<int> mon, c;

        for(int i=0; i<m;i++){
            int x;
            cin>>x;
            mon.pb(x);
        }

        for(int i=0; i<m;i++){
            int x;
            cin>>x;
            c.pb(x);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mon1, mon2;

        for(int i = 0; i<m; i++){
            if(c[i]==0) mon2.push({mon[i], c[i]});
            else mon1.push({mon[i], c[i]});
        }

        vector<int> sword2;

        while(sword1.size() && mon1.size()){
            if(sword1.top() < mon1.top().F){
                sword2.pb(sword1.top());
                sword1.pop();
                continue;
            }
            else{
                int c = mon1.top().S;
                mon1.pop();
                ans++;
                int x = sword1.top();
                sword1.pop();
                sword1.push(max(x,c));
            }
        }

        for(int i = 0; i<sword2.size(); i++){
            sword1.push(sword2[i]);
        }

        while(sword1.size() && mon2.size()){
            if(sword1.top() < mon2.top().F){
                sword1.pop();
                continue;
            }
            else{
                ans++;
                sword1.pop();
                mon2.pop();
            }
        }

        cout<<ans<<endl;
       

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

