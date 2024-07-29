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
    switch (n)
    {
    case 1:
        cout << "1\n1\n";
        return;
    case 2:
        cout << "2\n1 2\n";
        return;
    case 3:
        cout << "2\n1 2 2\n";
        return;
    case 4:
        cout << "3\n1 2 2 3\n";
        return;
    case 5:
        cout << "3\n1 2 2 3 3\n";
        return;
    default:
        cout << "4\n";
        break;
    }
    for (int i = 1; i <= n; i++)
        cout << (i % 4 + 1) << " ";
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