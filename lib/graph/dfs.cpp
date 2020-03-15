#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll MAX_N = 1e5;
vector<vector<ll> > graph(MAX_N);
vector<bool> visited(MAX_N);

// ALDS1_11_B
vector<ll> d(MAX_N);
vector<ll> f(MAX_N);
ll t = 0;

// O(E)
void dfs(ll u){
    visited[u] = true;
    //
    d[u] = ++t;
    for(ll v: graph[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    f[u] = ++t;
}

// ALDS1_11_B: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    for(ll i=0;i<n;i++){
        ll u, k; cin >> u >> k;
        vector<ll> vs;
        for(ll j=0;j<k;j++){
            ll v; cin >> v;
            vs.push_back(v);
        }
        sort(vs.begin(), vs.end());
        for(ll j=0;j<k;j++){
            ll v = vs[j];
            graph[u - 1].push_back(v - 1);
        }
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) dfs(i);
    }
    for(int i=0;i<n;i++) cout << i + 1 << " " << d[i] << " " << f[i] << endl;
}
