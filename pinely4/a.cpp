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


void solve() {
    cin >> n;
    m = 0;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (i % 2 == 1) continue;
        m = max(m, k);
    }
    cout << m << "\n";
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