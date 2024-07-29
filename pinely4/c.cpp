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

constexpr int inf = 1e9;
constexpr int MAXN = 1e6;
int n, m, k, q;

int mx(const vi &v) {
    int res = -1;
    for (int i = 0; i < v.size(); i++) {
        res = max(res, v[i]);
    }
    return res;
}

void solve() {
    cin >> n;
    vi v(n);
    bool p = false;
    bool np = false;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) {
            p = true;
        } else {
            np = true;
        }
    }

    if (p && np) {
        cout << "-1\n";
        return;
    }

    vi r;
    int MX = mx(v);
    while (MX != 0) {
        int mxhalf = (MX + 1) / 2;
        r.pb(mxhalf);
        for (int i = 0; i < n; i++) {
            v[i] = abs(v[i] - mxhalf);
        }

        MX = mx(v);
    }

    cout << r.size() << "\n";
    for (int i : r)
        cout << i << " ";
    cout << "\n";  
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