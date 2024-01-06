#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;

// ------------------------------------------------

constexpr ll INF = 1e18;
constexpr ll MOD = 998244353;
constexpr int MAXN = 5e3 + 7;
ll fact[MAXN];

void prepro() {
    fact[0] = 1LL;
    for (ll i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
}

ll qp(ll a, ll b) {
    if (b == 0) return 1LL;
    ll c = qp(a, b/2);
    c = (c * c) % MOD;
    if (b % 2)
        c = (c * a) % MOD;
    return c;
}

ll inv(ll a) {
    return qp(a, MOD - 2);
}

ll newton(ll n, ll k) {
    if (k < 0 || k > n) return 0LL;
    return (((fact[n] * inv(fact[k])) % MOD) * inv(fact[n - k])) % MOD;
}

void solve() {
    int n;
    cin >> n;
    int mini = 0, maxi = 0;
    map <int, ll> mapa;

    mapa[0] = 1;

    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        mapa[a]++;

        mini = min(mini, a);
        maxi = max(maxi, a);
    }

    if (mini == maxi) {
        cout << "0\n";
        return;
    }
    //cout << mini << " " << maxi << "\n";

    ll gres = 0;
    for (int i = maxi; i >= mini; i--) {
        map <int, ll> mapcp = mapa;
        ll lres = 1;

        for (int j = maxi; j > 0; j--) {
            ll x = mapcp[j] - (j <= i ? 1LL : 0LL);
            ll y = mapcp[j - 1] - x;
            lres = (lres * newton(x + y - 1, y - 1)) % MOD;
            mapcp[j - 1] = y;

            //cout << i << " " << j << " " << x << " " << y << " " << lres << "\n";
        }

        for (int j = 0; j > mini; j--) {
            mapcp[j]--;
            ll x = mapcp[j] - (j <= i ? 1LL : 0LL);
            ll y = mapcp[j - 1] - x;
            lres = (lres * newton(x + y - 1, y - 1)) % MOD;
            mapcp[j - 1] = y;

            //cout << i << " " << j << " " << x << " " << y << " " << lres << "\n";
        }

        gres = (gres + lres) % MOD;
    }

    cout << gres << "\n";
}

// ------------------------------------------------

int main() {
    prepro();
    int tcase = 1; 
    cin >> tcase;
    while (tcase--) {
        solve();
    }
    return 0;
}