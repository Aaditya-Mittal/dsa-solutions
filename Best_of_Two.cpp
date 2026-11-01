#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define ppb            pop_back
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
        vi v1(3), v2(3);
        int sum1=0, sum2=0;
        fr(i,0,3) {
            cin>>v1[i];
            sum1+=v1[i];
        }
        fr(i,0,3) {
            cin>>v2[i];
            sum2+=v2[i];
        }
        int a = min({v1[0], v1[1], v1[2]});
        int b = min({v2[0], v2[1], v2[2]});
        sum1 -= a;
        sum2 -= b;
        int ans = sum1 - sum2;
        if(ans==0) cout<<"TIE"<<endl;
        else if(ans>0) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;


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