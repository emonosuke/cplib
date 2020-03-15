#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// n: number of items, w_i: weight, v_i: value
// maximize value under \sum w <= W
// can choose any number of same-type items
// O(nW)
// DPL_1_C: verified
int main(){
    ll n, W; cin >> n >> W;
    // maximum value from <=i th items, total weight <= j
    vector<vector<ll> > dp(n + 1, vector<ll>(W + 1));
    vector<ll> v(n + 1), w(n + 1);
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(j < w[i]){
                dp[i][j] = dp[i - 1][j];
            }else{
                // select k items-i at dp[i][j]
                // means select k - 1 items-i at dp[i][j - w[i]]
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[n][W] << endl;
}
