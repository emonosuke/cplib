#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MAX_N = 1e9;

// O(sqrt(n))
vector<ll> get_divisors(ll n){
    vector<ll> divisors;
    for(ll i=1;i*i<=n;i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(i != (n / i)) divisors.push_back(n / i);
        }
    }
    return divisors;
}

// O(sqrt(n))
map<ll, ll> get_prime_factors(ll n){
    map<ll, ll> prime_factors;  // prime, number of prime factors
    for(ll i=2;i*i<=n;i++){
        while(n % i == 0){
            prime_factors[i]++;
            n /= i;
        }
    }
    if(n != 1) prime_factors[n] = 1;
    return prime_factors;
}

// O(nlog(logn))
vector<ll> eratosthenes(ll n){
    vector<ll> primes;
    vector<bool> is_prime(MAX_N + 1);

    ll cnt = 0;
    for(ll i=1;i<=n;i++) is_prime[i] = true;
    is_prime[1] = false;
    for(ll i=2;i<=n;i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(ll j=2*i;j<=n;j+=i) is_prime[j] = false;
        }
    }
    return primes;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<ll> divisors = get_divisors(12);
    for(ll divisor: divisors){
        cout << divisor << " ";
    }
    cout << endl;
    map<ll, ll> prime_factors = get_prime_factors(12);
    for(auto p=prime_factors.begin();p != prime_factors.end();p++){
        cout << p->first << " " << p->second << endl;
    }
    vector<ll> primes = eratosthenes(12);
    for(ll prime: primes){
        cout << prime << " ";
    }
    cout << endl;
}
