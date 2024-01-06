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
    input();
    
    int res = 0;
    int maxi = inf;
    int maxi2 = inf;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a > maxi) {
            res++;
            maxi2 = maxi;
            maxi = a;
        }
        else if (a > maxi2) {
            maxi = a;
        } else {
            maxi2 = a;
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