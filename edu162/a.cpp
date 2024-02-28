#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second


void solve() {
    int n, m, k;
    cin >> n;

    bool was_1 = false;
    int res = 0;
    int c0 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a) {
            was_1 = true;
            c0 = 0;
        }
        if (!a) {
            c0++;
            if (was_1)
                res++;
        }
    }

    cout << res-c0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tcase = 1;
    cin >> tcase;
    while (tcase--) {
        solve();
    }

    return 0;
}

