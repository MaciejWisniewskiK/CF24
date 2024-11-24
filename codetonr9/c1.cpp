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
    
    set <ll> ys;    
    for (ll i = 1; i * i <= x; i++) {
        if (x % i != 0) continue;
        ll y = x ^ i;
        ll y2 = x ^ (x / i);

        if (y <= m)
            ys.insert(y);
        if (y2 <= m)
            ys.insert(y2);
    }

    ll msb_ = msb(x);
    for (ll y = msb_; y < msb_ * 2; y++) {
        if (y > m) break;
        if (y == x) continue;
        ll xor_ = x ^ y;
        if (y % xor_ == 0)
            ys.insert(y);
    }

    ys.erase(0);
    cout << ys.size() << "\n";

    //for (ll y : ys)
    //    cout << y << " ";
    //cout << "\n";
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