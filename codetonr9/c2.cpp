#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;

// ------------------------------------------------

constexpr int inf = 1e9;
constexpr ll infll = 1e18;
constexpr int MAXN = 1e6;


ll msb(ll x) {
    ll i;
    for (i = 1; i * 2 <= x; i *= 2);
    return i;
}

void solve() {
    ll x, m;
    cin >> x >> m;

    if (x == 1) {
        cout << m << "\n";
        return;
    }
    
    set<ll> set_ys;
    ll ys = 0;    
    ll msb_ = msb(x);
    for (ll y = 1; y <= min(msb_, m); y++) {
        if (y == x) continue;
        if ((x ^ y) % y == 0) {
            set_ys.insert(y);
        }
    }

    ys += (m - 1) / x;

    for (ll y_ = ys * x; y_ <= m + x; y_ += x) {
        if ((y_ ^ x) <= m)
            set_ys.insert(y_ ^ x);
    }

    if (m % x == 0) ys--;
    set_ys.erase(0);
    cout << ys + (set_ys.size()) << "\n";

    //for (ll y : set_ys) cout << y << " "; cout << "\n";
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