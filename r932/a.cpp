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
//int n;

void input() {
    //cin >> n;
}

void solve() {
    //input();
    ll n, m, k, q;
    cin >> n;
    string s;
    cin >> s;
    string sr = s; 
    reverse(ALL(sr));

    if (s <= sr)
        cout << s << "\n";
    else
        cout << sr << s << "\n";
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