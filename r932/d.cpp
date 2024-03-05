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

void solve() {
    ll n, c;
    cin >> n >> c;

    ll total_even = ((c+2)/2);
    ll total_odd = ((c+1)/2);
    ll res = total_even * (total_even-1) / 2 + total_odd * (total_odd - 1) / 2;
    res += c + 1;
    res += total_even * (total_even - 1) / 2 + total_odd * (total_odd + 1) / 2;
    //cout << res << " gownno \n";

    ll num_even = 0;
    ll num_odd = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        res -= (c - a + 1) / 2;
        if (a % 2 == 0) {
            res -= total_even;
            res += num_even;
            num_even++;
        }
        else {
            res -= total_odd;
            res += num_odd;
            num_odd++;
        }
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