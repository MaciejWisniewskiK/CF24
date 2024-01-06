#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vi = vector<int>;

// ------------------------------------------------

constexpr ll INF = 1e18;
constexpr ll MOD = 998244353;
constexpr int MAXN = 5e3 + 7;
ll fact[MAXN];
ll invfact[MAXN];

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

void prepro() {
    fact[0] = 1LL;
    invfact[0] = 1LL;
    for (ll i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

ll newton(ll n, ll k) {
    if (k < 0 || k > n) return 0LL;
    return (((fact[n] * invfact[k]) % MOD) * invfact[n - k]) % MOD;
}

void solve() {
    int n;
    cin >> n;
    int mini = 0, maxi = 0;
    vi vpos(n + 1), vneg(n + 1);

    vpos[0] = 1;
    vneg[0] = 1;
    for (int i = 0; i < n; i++) {
        int a; 
        cin >> a;

        if (a >= 0)
            vpos[a]++;
        if (a <= 0)
            vneg[abs(a)]++;

        mini = min(mini, a);
        maxi = max(maxi, a);
    }

    if (mini == maxi) {
        cout << "0\n";
        return;
    }

    ll gres = 0;
    for (int i = maxi; i >= mini; i--) {
        ll lres = 1;

        int lasty = vpos[maxi];
        for (int j = maxi; j > 0; j--) {
            int x = lasty - (j <= i ? 1 : 0);
            int y = vpos[j - 1] - x;
            lres = (lres * newton(x + y - 1, y - 1)) % MOD;
            lasty = y;
        }

        for (int j = 0; j > mini; j--) {
            lasty--;
            int x = lasty - (j <= i ? 1 : 0);
            int y = vneg[abs(j - 1)] - x;
            lres = (lres * newton(x + y - 1, y - 1)) % MOD;
            lasty = y;
        }

        if (lasty != 1) lres = 0;
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