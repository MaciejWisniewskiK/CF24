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

constexpr int MAXN = 2e5;
constexpr ll mod = 1e9 + 7;

ll fact[MAXN + 7];
ll invfact[MAXN + 7];

ll qp(ll a, ll b) {
    if (b == 0LL) return 1LL;
    ll c = qp(a, b / 2LL);
    c = (c * c) % mod;
    if (b % 2 == 1LL)
        c = (c * a) % mod;
    return c;
}

ll inverse(ll a) {
    return qp(a, mod - 2);
}

ll newton(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return (((fact[n] * invfact[k]) % mod) * invfact[n - k]) % mod;
}

ll doit(vi &v) {
    ll res = 1;

    while (v.size() >= 2) {
        ll curr = (v.back() - v[v.size() - 2] - 1);
        res = (res * newton(v.back() - 2, curr)) % mod;
        res = (res * fact[curr]) % mod;
        v.pop_back();
    }
    return res;
}

void solve() {
    ll n;
    int m1, m2;
    cin >> n >> m1 >> m2;
    
    vi v1(m1), v2(m2);
    for (int i = 0; i < m1; i++)
        cin >> v1[i];
    for (int j = 0; j < m2; j++)
        cin >> v2[j];

    if (v1.back() != v2[0] || v1[0] != 1 || v2.back() != n) {
        cout << "0\n";
        return;
    }

    reverse(ALL(v2));
    for (int j = 0; j < m2; j++) 
        v2[j] = (n - v2[j] + 1);

    
    ll res = newton(n - 1, v1.back() - 1);
    res = (res * doit(v1)) % mod;
    res = (res * doit(v2)) % mod;
    cout << res << "\n";
}

// ------------------------------------------------

int main() {
    fact[0] = 1;
    invfact[0] = 1;
    for (ll i = 1; i < MAXN + 5; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = inverse(fact[i]);
    }

    int tcase = 1; 
    cin >> tcase;
    while (tcase--) {
        solve();
    }

    return 0;
}