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

    vi v(n);

    for (int i = 0; i < n; i++)
     cin >> v[i];
    sort(ALL(v));

    int res = 1;
    int id = (n/2);
    if (n % 2 == 0)
        id--;
    for (int i = id + 1; i < n; i++) {
        if (v[i] != v[id]) break;
        res++;
    }
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