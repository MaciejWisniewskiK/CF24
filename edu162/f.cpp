#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>

constexpr ll mod = 1e9 + 7;

ll qp(ll a, ll b) {
    if (b == 0)
        return 1LL;
    
    ll c = qp(a, b / 2);
    c = (c * c) % mod;
    if (b % 2)
        c = (c * a) % mod;

    return c;
}

ll bin_to_int(string s) {
    ll res = 0;
    for (char c : s) {
        res = (res * 2) % mod;
        if (c == '1')
            res = (res + 1) % mod;
    }

    return res;
}

ll one_shrink_reverse(int n, int k, string s) {
    string s2 = "";

    int num1s = 0;
    for (char c : s) {
        if (c == '1') {
            num1s++;

            if (num1s == k) {
                for (int i = 1; i < k; i++)
                    s2.push_back('1');
            }
        }

        if (num1s >= k)
            s2.push_back(c);
    }

    reverse(s2.begin(), s2.end());
    return bin_to_int(s2);
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int num1s = 0;
    for (char c : s)
        num1s += (c == '1' ? 1 : 0);

    if (num1s <= k) {
        cout << (qp(2, k) - 1 + mod) % mod << "\n";
        return;
    }

    cout << one_shrink_reverse(n, k, s) << "\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tcase = 1;
    //cin >> tcase;
    while (tcase--) {
        solve();
    }

    return 0;
}

