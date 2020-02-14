#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// 0-indexed Segment Tree for Range Sum and Range Add Query
class LazySegmentTree{
    public:
    ll size;
    vector<ll> dat, lazy;

    LazySegmentTree(ll n){
        size = 1;
        while(size < n) size *= 2;

        dat = vector<ll>(2*size - 1, 0LL);
        lazy = vector<ll>(2*size - 1, 0LL);
    }

    void eval(ll k, ll l, ll r){
        if(lazy[k] != 0){
            dat[k] += lazy[k];

            // if not bottom of the tree
            if(r - l > 1){
                lazy[k*2+1] += lazy[k] / 2; 
                lazy[k*2+2] += lazy[k] / 2;
            }

            lazy[k] = 0;
        }
    }

    // Add x to [l, r)
    void add(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1){
        if(r < 0) r = size;

        eval(k, l, r);

        if(b <= l || r <= a) return;

        if(a <= l && r <= b){
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }else{
            add(a, b, x, k * 2 + 1, l, (l + r) / 2);
            add(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = dat[k*2+1] + dat[k*2+2];
        }
    }

    // Get sum of [l, r)
    ll getSum(ll a, ll b, ll k=0, ll l=0, ll r=-1){
        if(r < 0) r = size;
        if(b <= l || r <= a) return 0;

        eval(k, l, r);
        if(a <= l && r <= b) return dat[k];
        else{
            ll vl = getSum(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = getSum(a, b, k * 2 + 2, (l + r) / 2, r);
            return vl + vr;
        }
    }
};

// DSL_2_G: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, q; cin >> n >> q;
    LazySegmentTree lsg(n);
    vector<ll> ans;
    for(ll i=0;i<q;i++){
        ll com; cin >> com;
        if(com == 0){
            ll s, t, x; cin >> s >> t >> x;
            lsg.add(s - 1, t, x);
        }else{
            ll s, t; cin >> s >> t;
            ans.push_back(lsg.getSum(s - 1, t));
        }
    }
    for(ll a: ans) cout << a << endl;
}
