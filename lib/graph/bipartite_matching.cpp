#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class Matching{
    public:
    ll size;
    vector<vector<ll> > g;
    vector<ll> match;
    vector<bool> checked;

    Matching(ll n){
        size = n;
        g = vector<vector<ll> >(size);
        match = vector<ll>(size, -1);
        checked = vector<bool>(size, false);
    }

    void add_edge(ll u, ll v){
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool dfs(ll v){
        checked[v] = true;
        for(ll u: g[v]){
            ll m = match[u];
            if(m < 0 || !checked[m] && dfs(m)){
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    ll bipartite_matching(){
        ll res = 0;
        for(ll v=0;v<size;v++){
            if(match[v] < 0){
                fill(checked.begin(), checked.end(), false);
                if(dfs(v)){
                    res++;
                }
            }
        }
        return res;
    }
};

// GRL_7_A: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll nx, ny, ne; cin >> nx >> ny >> ne;
    Matching mat(nx + ny);
    for(ll i=0;i<ne;i++){
        ll x, y; cin >> x >> y;
        mat.add_edge(x, nx + y);
    }
    cout << mat.bipartite_matching() << endl;
}
