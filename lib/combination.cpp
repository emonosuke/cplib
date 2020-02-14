#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll mod_pow(ll x, ll n){
    if (n == 0) return 1;
    ll res = mod_pow(x * x %MOD, n / 2);
    // x^n = ((x^2)^(n/2)) * x
    if(n & 1) return res = res * x %MOD;
    // x^n = (x^2)^(n/2)
    return res %MOD;
}

// nCk = n!/(n - k)!k! using a/b = a*b^(1e7 - 2)(mod 1e7)
ll comb(ll n, ll k){
    ll res = 1;
    k = min(n - k, k);
    for(ll i=n-k+1;i<=n;i++) res = (res * i) %MOD;
    for(ll i=1;i<=k;i++) res = (res * mod_pow(i, MOD - 2)) %MOD;
    return res;
}

// nHk
ll H(ll n, ll k){
    return comb(n - 1 + k, n - 1);
}
