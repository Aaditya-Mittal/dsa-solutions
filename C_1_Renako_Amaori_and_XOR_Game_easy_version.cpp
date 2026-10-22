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

int helper(vi & a, vi &b, int i, int &n, int score1, int score2){
    if(i>=n){
        if(score1 > score2) return 2;
        if(score1 < score2) return 0;
        else return 1;
    }

    

    if(i%2==0){
        if(a[i]!=b[i]){
            if(i==0){
            int x = helper(a, b, i+1, n, a[i], b[i]);
            int y = helper(a, b, i+1, n, b[i], a[i]);
            return max(x, y);
        }
            else{
                int x = helper(a, b, i+1, n, score1^a[i], score2^b[i]);
                int y = helper(a, b, i+1, n, score1^b[i], score2^a[i]);
                return max(x, y);
            }
        }

        else{
            if(i==0) return helper(a, b, i+1, n, a[i], b[i]);
            else return helper(a, b, i+1, n, score1^a[i], score2^b[i]);
        }
        
        
    }

    else {
        if(a[i]!=b[i]){
            int x = helper(a, b, i+1, n, score1^a[i], score2^a[i]);
            int y = helper(a, b, i+1, n, score1^b[i], score2^b[i]);
            return min(x, y);
        }

        else return helper(a, b, i+1, n, score1^b[i], score2^a[1]);
    }

}

void solve() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        

        vi a, b;
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            a.pb(x);
        }
        for(int i = 0; i<n; i++){
            int x;
            cin>>x;
            b.pb(x);
        }

        if(n==1){
            if(a[0]==b[0]) cout<<"Tie";
            else cout<<"Ajisai";
            cout<<endl;
            continue;
        }

        int score1 = 0, score2 = 0;

       

        int final = helper(a, b, 0, n, score1, score2);
        
        if(final==2) cout<<"Ajisai";
        else if(final==0) cout<<"Mai";
        else cout<<"Tie";

        cout<<endl;


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

