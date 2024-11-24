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
int n, m, k, q;


void solve() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cout << s[i] << s[i] << "\n";
            return;
        }
    }

    for (int i = 2; i < s.size(); i++) {
        if (s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) {
            cout << s.substr(i - 2, 3) << "\n";
            return;
        }
    }
    cout << "-1\n";
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