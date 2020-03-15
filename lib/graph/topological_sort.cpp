#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// O(|V|+|E|)
class Graph{
    public:
    ll size;
    vector<vector<ll> > g;
    vector<bool> visited;
    vector<ll> indeg;

    // sorted by topological sort
    vector<ll> sorted;

    Graph(ll n){
        size = n;
        g = vector<vector<ll> >(size);
        visited = vector<bool>(size);
        indeg = vector<ll>(size);
    }

    void add_edge(ll x, ll y){
        g[x].push_back(y);  // x -> y
        indeg[y]++;
    }

    void bfs(ll s){
        queue<ll> Q; // v, dist
        visited[s] = true;
        Q.push(s);
        while(!Q.empty()){
            ll u = Q.front(); Q.pop();
            sorted.push_back(u);
            for(ll v: g[u]){
                indeg[v]--;
                if(indeg[v] == 0 && !visited[v]){
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    // O(|E|log|V|)
    vector<ll> topological_sort(){
        for(ll s=0;s<size;s++){
            if(indeg[s] == 0 && !visited[s]) bfs(s);
        }
        return sorted;
    }
};

// GRL_4_B: verified
int main(){
    ll V, E; cin >> V >> E;
    Graph graph(V); 
    for(ll i=0;i<E;i++){
        ll s, t; cin >> s >> t;
        graph.add_edge(s, t);
    }
    vector<ll> sorted = graph.topological_sort();
    for(ll v: sorted) cout << v << endl;
}
