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
        vector<vector<int>> v(2, vector<int>(n, 0));
        for(int i = 0; i<2; i++ ){
            for(int j = 0; j<n; j++){
                int x;
                cin>>x;
                v[i][j] = x;
            }
        }

        vector<vector<pii>> min_max(2, vector<pii>(n, {0,0}));
        min_max[0][0] = {v[0][0], v[0][0]};

        for(int i = 1; i<n; i++){
            int a = min(v[0][i], min_max[0][i-1].F);
            int b = max(v[0][i], min_max[0][i-1].S);
            min_max[0][i] = {a,b};
        }

        min_max[1][n-1] = {v[1][n-1], v[1][n-1]};

        for(int i = n-2; i>=0; i--){
            int a = min(v[1][i], min_max[1][i+1].F);
            int b = max(v[1][i], min_max[1][i+1].S);
            min_max[1][i] = {a,b};
        }


        map<int,int> mp;

        int max_ele = INT_MIN;

        for(int i = 0; i<n; i++){
            int a = min( min_max[0][i].F, min_max[1][i].F);
            int b = max( min_max[0][i].S, min_max[1][i].S);
            int temp = mp[a];
            max_ele = max(max_ele, a);
            if(temp == 0) mp[a] =  b;
            else mp[a] = min(temp, b);
        }

        int mini = INT_MAX;

        for(int i = max_ele; i>=1; i--){
            if(mp[i]==0) mp[i] = mini;
            else mp[i] = min(mini, mp[i]);
            if(mp[i] < mini) mini = mp[i]; 
        }

        int ans = 0;

        for(auto x: mp){
            ans += 2*n - x.S + 1;
            
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

