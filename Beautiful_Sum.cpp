#include <bits/stdc++.h>
using namespace std;

void update(unordered_map<int, vector<pair<int,int>>> &mp, int v, int w){
    for(int i = 0;i< mp[v].size(); i++){
        mp[v][i].second = mp[v][i].second ^ w;
        update(mp, mp[v][i].first, w);
    }
}

void beauty(unordered_map<int, vector<pair<int,int>>> &mp, int u, vector<int> &temp, int x){
    if(mp[u].size() == 0){
        temp.push_back(x);
        return;
    }
    for(int i = 0;i< mp[u].size(); i++){
        beauty(mp, mp[u][i].first,temp, x + mp[u][i].second);
    }
}

void solve(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int, vector<pair<int,int>>> mp;
        
        for(int i = 0; i<n; i++){
            int u,v,w;
            cin>>u>>v>>w;
            mp[u].push_back({v,w});
        }

        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;

            if(x==1){
                int u, w;
                cin>>u>>w;
                update(mp, u, w);
            }
            
            else{
                
                int u;
                cin>>u;
                vector<int> w;
                beauty(mp, u, w, 0);
                if(w.size() == 0){
                    cout<<"0"<<endl;
                    continue;
                }
                int ans = w[0];
                for(int i = 1; i<w.size(); i++){
                    ans^=w[i];
                }
                cout<<ans<<endl;
            }

        }

    }
}

int main() {
	// your code goes here
	solve();
    return 0;
}
