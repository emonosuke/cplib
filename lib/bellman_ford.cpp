#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

class Graph{
    public:
    ll size;
    const ll INF = 1e15;

    struct edge{
        ll from, to, cost;
    };

    vector<ll> dist;
    vector<edge> edges;

    Graph(ll nv){
        size = nv;
        dist = vector<ll>(nv);
    }

    void add_edge(ll x, ll y, ll cost){
        edges.push_back((edge){x, y, cost});
    }

    // O(|V||E|)
    void bellman_ford(ll s){
        fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        while(true){
            bool update = false;
            for(edge e: edges){
                if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost){
                    dist[e.to] = dist[e.from] + e.cost;
                    update = true;
                }
            }
            if(!update) break;
        }
    }

    // if there is a negative cycle can reach from s
    bool negative_cycle(ll s){
        fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        for(ll i=0;i<size;i++){
            for(edge e: edges){
                // cout << e.from << " " << e.to << " " << e.cost << endl;
                if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost){
                    dist[e.to] = dist[e.from] + e.cost;

                    if(i == size - 1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// GRL_1_B: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll v, e, r; cin >> v >> e >> r;
    Graph graph(v);
    for(int i=0;i<e;i++){
        ll s, t, d; cin >> s >> t >> d;
        graph.add_edge(s, t, d);
    }

    if(graph.negative_cycle(r)){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    graph.bellman_ford(r);
    for(ll i=0;i<v;i++){
        ll ans = graph.dist[i];
        if(ans == graph.INF) cout << "INF" << endl;
        else cout << ans << endl;
    }
}
