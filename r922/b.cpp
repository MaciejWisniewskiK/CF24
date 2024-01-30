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
int n;

void input() {
    
}

void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i].fi;
    for (int i = 0; i < n; i++)
        cin >> v[i].se;
    sort(ALL(v));
    for (int i = 0; i < n; i++)
        cout << v[i].fi << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << v[i].se << " ";
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