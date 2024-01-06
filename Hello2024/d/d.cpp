#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pii>;

// ------------------------------------------------

constexpr int inf = 1e9;
constexpr int MAXN = 1e6;

void solve() {
    int n;
    cin >> n;
    vii v;

    bool exited = false;
    int zerocount = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (exited) continue;
        if (a == 0) zerocount++;
        
        if (v.empty()) {
            v.pb({a, a});
            continue;
        }

        if (a > v.back().se + 1) {
            v.pb({a, a});
            continue;
        }
        
        if (a < v.back().fi - 1) {
            exited = true;
            continue;
        }

        pii p = v.back();
        v.pop_back();
        p.fi = min(a, p.fi);
        p.se = a;
        
        while (!v.empty() && v.back().se >= p.fi - 1) {
            p.fi = v.back().fi;
            v.pop_back();
        }

        v.push_back(p);
    }

    if (exited || zerocount != 1) {
        cout << "NO\n";
        return;
    }
    if (v.size() > 1 || v[0].fi != 0)
        cout << "NO\n";
    else
        cout << "YES\n";
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