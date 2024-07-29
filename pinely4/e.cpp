#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;

// ------------------------------------------------

constexpr int inf = 1e9;
constexpr int MAXN = 1e6;
int n, m, k, q;


bool col2(int v, vii &g, vi &col) {
    for (int i : g[v]) {
        if (col[i] == col[v])
            return false;
        if (col[i] == -1) {
            col[i] = 1 - col[v];
            if (!col2(i, g, col))
                return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vii g(n + 1);

    for (int i = 0 ; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vi col(n + 1, -1);
    col[1] = 0;
    bool bob = col2(1, g, col);

    vi c1, c2;
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) c1.pb(i);
        else c2.pb(i);
    }

    if (!bob) { // Alice
        cout << "Alice\n";
        cout.flush();

        for (int i = 0; i < n; i++) {
            cout << "1 2\n";
            cout.flush();
            int a, b;
            cin >> a >> b;
        }
    }
    else { // Bob
        cout << "Bob\n";
        cout.flush();

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            
            if (a > b) swap(a, b);

            if (a == 1) {
                if (!c1.empty()) {
                    cout << c1.back() << " 1\n";
                    c1.pop_back();
                }
                else {
                    cout << c2.back() << " " << b << "\n";
                    c2.pop_back();
                }
            }
            else {
                if (!c2.empty()) {
                    cout << c2.back() << " 2\n";
                    c2.pop_back();
                }
                else {
                    cout << c1.back() << " " << b << "\n";
                    c1.pop_back();
                }   
            }
            cout.flush();
        }
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