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
            int test;
            cin>>test;
            while(test--){
                int n, k;
                cin>>n>>k;
                string s;
                cin>>s;
                string t;
                cin>>t;

                if(s==t){
                    cout<<"0"<<endl;
                    continue;
                } 

                vector<string> ans;
                int i = 0;

                for(i = 1; i <=k; i++){
                    string temp = "";
                    for(int j = 0; j < s.size(); j++){
                        if(j==0) temp+= s[j];
                        else{
                            if(s[j-1] == t[j]) temp+=s[j-1];
                            else temp+=s[j];
                        }
                    }
                    ans.push_back(temp);
                    s = temp;
                    if(temp == t) break;
                }
                
                if(s==t){
                    cout<<i<<endl;
                    for(int j = 0; j< ans.size(); j++){
                        cout<<ans[j]<<endl;
                    }
                }       
                else cout<<"-1"<<endl;
                

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

