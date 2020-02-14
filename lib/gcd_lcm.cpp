#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a %b);
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
