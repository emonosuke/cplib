#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e10;

// Longest Increasing Subsequence at A=a_1...a_n
// O(nlogn)
// DPL_1_D: verified
int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin >> a[i];
    vector<ll> dp(n + 1);  // the last(maximum) value of LIS length i+1
    // (if not exist then INF)
    fill(dp.begin(), dp.end(), INF);
    for(ll i=0;i<n;i++){
        // lower_bound(k) returns min pointer a_i >= k
        *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    cout << ll(lower_bound(dp.begin(), dp.end(), INF) - dp.begin()) << endl;
}
