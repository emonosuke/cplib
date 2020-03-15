#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, -1, 0, +1};

// divide m no more than n times
// O(nm)
ll partition(ll n, ll m){
    vector<vector<ll> > dp(n + 1, vector<ll>(m + 1));
    dp[0][0] = 1;
    // start with [1]
    // 1. add +1 to all values
    // 2. append 1
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j - i >= 0){
                dp[i][j] = (dp[i-1][j] + dp[i][j-i]) %MOD;
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << partition(3, 4) << endl;
}
