#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// 1-indexed
class BinaryIndexedTree{
    public:
    ll size;
    vector<ll> bit;

    BinaryIndexedTree(ll n){
        size = n;
        bit = vector<ll>(size + 1, 0LL);
    }

    // Get a_1 + ... + a_idx
    ll getSum(ll idx){
        ll acc = 0;
        while(idx > 0){
            acc += bit[idx];
            idx -= (idx & -idx);
        }
        return acc;
    }

    // add a_idx to x
    void add(ll idx, ll x){
        while(idx <= size){
            bit[idx] += x;
            idx += (idx & -idx);
        }
    }
};

// DSL_2_B: verified
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, q; cin >> n >> q;
    BinaryIndexedTree bit(n);
    vector<ll> ans;
    for(ll i=0;i<q;i++){
        ll com, x, y; cin >> com >> x >> y;
        if(com == 0){
            bit.add(x, y);
        }else{
            if(x == 1) ans.push_back(bit.getSum(y));
            else ans.push_back(bit.getSum(y) - bit.getSum(x - 1));
        }
    }
    for(ll a: ans) cout << a << endl;
}

// Chokudai SpeedRun 001: verified
// find i < j, a_i > a_j
void inversion(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    BinaryIndexedTree bit(n);
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll ans = 0;
    for(int j=0;j<n;j++){
        ans += j - bit.getSum(a[j]);
        bit.add(a[j], 1);
    }
    cout << ans << endl;
}
