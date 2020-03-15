#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class UnionFindTree{
    public:
    ll size;
    // parent, if par[x] = x means root
    vector<ll> par;
    vector<ll> rank;

    UnionFindTree(ll n){
        size = n;
        par = vector<ll>(n);
        rank = vector<ll>(n);

        for(ll i=0;i<size;i++){
            par[i] = i;
            rank[i] = 0;
        }
    }

    // get the root of the tree
    ll find(ll x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(ll x, ll y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(rank[x] <= rank[y]){
            par[x] = y;
        }else{
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(ll x, ll y){
        return find(x) == find(y);
    }
};

// DSL_1_A: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    UnionFindTree uf(n);
    for(int i=0;i<q;i++){
        int com, x, y; cin >> com >> x >> y;
        if(!com){
            uf.unite(x, y);
        }else{
            cout << uf.same(x, y) << endl;
        }
    }
}
