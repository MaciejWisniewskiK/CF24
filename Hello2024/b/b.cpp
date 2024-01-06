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
    cin >> n;
}

void solve() {
    string s;
    int n;
    cin >> n >> s;
    
    int res = 0;
    for (int i = 0; i < n; i++)
        res += (s[i] == '-' ? 1 : -1);
    
    cout << abs(res) << "\n";
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