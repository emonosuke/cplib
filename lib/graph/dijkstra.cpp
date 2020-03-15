#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

class Graph{
    public:
    using PL = pair<ll, ll>;
    const ll INF = 1e15;

    ll size;
    // has (dist, to)
    vector<vector<PL> > g;
    vector<ll> dist;
    vector<ll> prev;

    Graph(ll n){
        size = n;
        g = vector<vector<PL> >(size);
        dist = vector<ll>(size);
        prev = vector<ll>(size);
    }

    void add_edge(ll x, ll y, ll cost){
        g[x].push_back(make_pair(cost, y));
    }

    // O(|E|log|V|)
    void dijkstra(ll s){
        priority_queue<PL, vector<PL>, greater<PL> > PQ;
        fill(dist.begin(), dist.end(), INF);
        fill(prev.begin(), prev.end(), -1);
        dist[s] = 0;
        PQ.push(make_pair(0, s));

        while(!PQ.empty()){
            PL p = PQ.top(); PQ.pop();
            ll v = p.second;
            if(dist[v] < p.first) continue;
            for(PL newp: g[v]){
                ll d = newp.first;
                ll u = newp.second;
                if(dist[u] > dist[v] + d){
                    dist[u] = dist[v] + d;
                    prev[u] = v;
                    PQ.push(make_pair(dist[u], u));
                }
            }
        }
    }

    vector<ll> get_path(ll t){
        vector<ll> path;
        for(;t!=-1;t=prev[t]) path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
};

// GRL_1_A: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int v, e, r; cin >> v >> e >> r;
    Graph graph(v);
    for(int i=0;i<e;i++){
        int s, t, d; cin >> s >> t >> d;
        graph.add_edge(s, t, d);
    }
    graph.dijkstra(r);
    for(int i=0;i<v;i++){
        if(graph.dist[i] >= graph.INF)
            cout << "INF" << endl;
        else
            cout << graph.dist[i] << endl;
    }

    vector<ll> path = graph.get_path(2);

    /*
    for(ll p: path) cout << p << " ";
    cout << endl;
    */
}
