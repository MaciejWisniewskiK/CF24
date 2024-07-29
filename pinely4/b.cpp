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
    vi b(n+ 5);
    vi a(n+5);
    vi c(n+5);
    bool res = true;

    
    for (int i = 1; i < n; i++) {
        cin >> b[i - 1];
    }
    a[0] = b[0];
    for (int i = 1; i < n; i++) {
        a[i] = b[i - 1] | b[i];
    }
    
    for (int i = 1; i < n; i++) {
        c[i - 1] = a[i] & a[i - 1];
        if (c[i - 1] != b[i - 1]) {
            res = false;
            break;
        }
    }

    if (!res)
        cout << "-1\n";
    else {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
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