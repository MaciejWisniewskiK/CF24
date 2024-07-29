#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

// ------------------------------------------------


ll n, m, k, q;

constexpr ll mod = 1000000007LL;
constexpr ll mod1000 = 1000000007000000LL;

ll qp(ll a, ll b) {
    if (b == 0LL) return 1LL;
    ll c = qp(a, b / 2LL);
    c = (c * c) % mod;
    if (b % 2 == 1LL)
        c = (c * a) % mod;
    return c;
}

void solve() {
    cin >> n >> k;
    ll sum = 0;
    ll max_sum = 0;
    ll min_sum = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sum += a;
        max_sum = max(max_sum, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    sum %= mod;
    max_sum %= mod;
    ll res = sum - max_sum + ((qp(2LL, k) * max_sum) % mod);
    while (res < 0)
        res = (res + mod1000) % mod;
    res %= mod;
    cout << res << "\n";
}

// ------------------------------------------------

int main() {
    int tcase = 1; 
    cin >> tcase;
    while (tcase--) {
        solve();
    }
    return 0;
}