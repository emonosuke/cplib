#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll MAX_N = 1e5;
vector<vector<ll> > graph(MAX_N);
vector<bool> visited(MAX_N);

// ALDS1_11_C
vector<ll> d(MAX_N);

// O(E)
void bfs(ll u){
    queue<pair<ll, ll> > Q; // v, dist
    visited[u] = true;
    Q.push(make_pair(u, 0));
    while(!Q.empty()){
        pair<ll, ll> p = Q.front(); Q.pop();
        ll u = p.first, dist = p.second;
        //
        d[u] = dist;
        for(ll v: graph[u]){
            if(!visited[v]){
                visited[v] = true;
                Q.push(make_pair(v, dist + 1));
            }
        }
    }
}

// ALDS1_11_C: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    for(ll i=0;i<n;i++){
        ll u, k; cin >> u >> k;
        for(ll j=0;j<k;j++){
            ll v; cin >> v;
            graph[u - 1].push_back(v - 1);
        }
    }
    fill(d.begin(), d.end(), -1);
    bfs(0);
    for(ll i=0;i<n;i++) cout << i + 1 << " " << d[i] << endl;
}
