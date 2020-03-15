#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class Graph{
    public:
    const ll INF = 1e18;

    struct edge{
        ll to, cap, rev;
    };
    ll size;
    vector<vector<edge> > g;
    vector<bool> checked;

    Graph(ll n){
        size = n;
        g = vector<vector<edge> >(size);
        checked = vector<bool>(size, false);
    }

    void add_edge(ll from, ll to, ll cap){
        // one is the rev-edge of the other
        g[from].push_back((edge){to, cap, (ll)g[to].size()});
        g[to].push_back((edge){from, 0LL, (ll)g[from].size() - 1});
    }

    ll dfs(ll v, ll t, ll f){
        if(v == t) return f;
        checked[v] = true;
        for(edge &e: g[v]){
            if(!checked[e.to] && e.cap > 0){
                ll d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll maxflow(ll s, ll t){
        ll flow = 0;
        while(1){
            fill(checked.begin(), checked.end(), false);
            ll f = dfs(s, t, INF);
            if(f == 0) return flow;
            flow += f;
        }
    }
};

// GRL_6_A: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll v, e; cin >> v >> e;
    Graph graph(v);
    for(ll i=0;i<e;i++){
        ll u, v, c; cin >> u >> v >> c;
        graph.add_edge(u, v, c);
    }
    cout << graph.maxflow(0, v - 1) << endl;
}
