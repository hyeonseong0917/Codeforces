#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
const ll MOD = 1000000007;
const ll MULTIPLIER = 2022;

ll mod_inv(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    return (x1 < 0) ? x1 + m0 : x1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        
        ll n_mod = n % MOD;
        ll k = (n_mod * (n_mod + 1) % MOD * (2 * n_mod + 1) % MOD * mod_inv(6, MOD)) % MOD;
        ll sum_n_1 = ((n_mod * (n_mod - 1) % MOD) * mod_inv(2, MOD)) % MOD;
        
        ll ans = (2 * k - (n_mod * n_mod % MOD) + sum_n_1 + MOD) % MOD;
        ans = (ans * MULTIPLIER) % MOD;
        
        cout << ans << "\n";
    } 
    return 0;
}