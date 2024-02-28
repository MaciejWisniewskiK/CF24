#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define f first
#define s second


void solve() {
    int n, q;
    cin >> n >> q;

    vi v(n+1);
    vi sum(n+1);
    vi num0(n+1);
    num0[0] = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i]--;
        sum[i] = sum[i - 1] + v[i];
        num0[i] = num0[i - 1] + (v[i] == 0 ? 1 : 0);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "NO\n";
            continue;
        }
        if ((sum[r] - sum[l - 1]) < num0[r] - num0[l - 1]) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }

    /*for (int i : sum)
        cout << i << " ";
    cout << "\n";
    for (int i : num0)
        cout << i << " ";
    cout << "\n";*/


}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tcase = 1;
    cin >> tcase;
    while (tcase--) {
        solve();
    }

    return 0;
}

