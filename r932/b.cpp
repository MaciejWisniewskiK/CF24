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
constexpr int MAXN = 1e5;

void solve() {
    int n;
    cin >> n;
    vi v(n);
    
    vi fir(n + 1, inf);
    vi las(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        
        fir[a] = min(fir[a], i);
        las[a] = max(las[a], i);
    }

    //for (int i : fir) cout << i << " "; cout << "\n";
    //for (int i : las) cout << i << " "; cout << "\n";

    int last_left = 1;
    int first_right = n;
    for (int i = 0; i < n; i++) {
        if (fir[i] == inf) {
            cout << "2\n1 " << last_left << "\n" << last_left + 1 << " " << n << "\n";
            return;
        }

        if (fir[i] == las[i]) {
            cout << "-1\n";
            return;
        }

        last_left = max(last_left, fir[i]);
        first_right = min(first_right, las[i]);

        if (last_left >= first_right){
            cout << "-1\n";
            return;
        }
    }

    cout << "2\n1 " << last_left << "\n" << last_left + 1 << " " << n << "\n";
    return;
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