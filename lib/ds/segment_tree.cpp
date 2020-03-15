#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// For Range Minimum Query
class SegmentTree{
    public:
    ll size;
    vector<ll> dat;
    const ll MAXVAL = (1LL << 31) - 1; 

    SegmentTree(ll n){
        size = 1;
        while(size < n) size *= 2;

        dat = vector<ll>(2*size - 1, MAXVAL);
    }

    // update k th value to a
    void update(ll k, ll a){
        k += size - 1;
        dat[k] = a;

        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    ll query(ll a, ll b, ll k=0, ll l=0, ll r=-1){
        if(r < 0) r = size;
        if(r <= a || b <= l) return MAXVAL;
        if(a <= l && r <= b) return dat[k];
        else{
            ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};

// DSL_2_A: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, q; cin >> n >> q;
    SegmentTree sg(n);
    vector<ll> ans;
    for(ll i=0;i<q;i++){
        ll com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            sg.update(x, y);
        }else{
            ans.push_back(sg.query(x, y + 1));
        }
    }
    for(ll a: ans) cout << a << endl;
}
