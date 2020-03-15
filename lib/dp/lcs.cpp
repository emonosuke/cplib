#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Longest Common Subsequence between X=x_1...x_m and Y=y_1...y_n
// O(mn)
// ALDS_1_10_C: verified
int main(){
    ll Q; cin >> Q;
    for(ll q=0;q<Q;q++){
        string X, Y; cin >> X >> Y;
        ll m = X.size(), n = Y.size();
        vector<vector<ll> > dp(m + 1, vector<ll>(n + 1));
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=n;j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + 1);
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[m][n] << endl;
    }
}
