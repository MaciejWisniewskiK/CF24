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
    long long a, b, r;
    long long res = 0;

    cin >> a >> b >> r;
    
    if (a < b)
        swap(a, b);
    
    bool skipped_one = false;

    for (long long i = (1LL << 61LL); i > 0LL; i >>= 1LL) {
        //if (i < 64)
          //  cout << i << " " << a << " " << b << " " << r << " " << res << "\n";

        if (a >= i && b >= i) {
            a -= i;
            b -= i;
            continue;
        }

        if (a >= i && b < i) {
            if (!skipped_one) {
                res = i;
                skipped_one = true;
                a -= i;
                continue;
            }

            if (r >= i) {
                a -= i;
                r -= i;
                res -= i;
                continue;
            }

            if (r < i) {
                a -= i;
                res += i;
                continue;
            }
        }

        if (a < i && b >= i) {
            b -= i;
            res -= i;
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