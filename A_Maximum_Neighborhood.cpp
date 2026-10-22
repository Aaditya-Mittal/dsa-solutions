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
#define fr(i,a,b)      for(int i=a;i<b;i++)
#define rf(i,a,b)      for(int i=a;i>=b;i--)
#define each(x,a)      for(auto &x:a)

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
        int a;
        cin>>a;
        vi ans = {1,9,29,56,95,145,205,275,355,445,545,655,775,905,1045,1195,1355,1525,1705,1895,2095,2305,2525,2755,2995,3245,3505,3775,4055,4345,4645,4955,5275,5605,5945,6295,6655,7025,7405,7795,8195,8605,9025,9455,9895,10345,10805,11275,11755,12245,12745,13255,13775,14305,14845,15395,15955,16525,17105,17695,18295,18905,19525,20155,20795,21445,22105,22775,23455,24145,24845,25555,26275,27005,27745,28495,29255,30025,30805,31595,32395,33205,34025,34855,35695,36545,37405,38275,39155,40045,40945,41855,42775,43705,44645,45595,46555,47525,48505,49495};
        cout<<ans[a-1]<<endl;
        
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

